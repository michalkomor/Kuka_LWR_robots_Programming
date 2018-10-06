#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include "friudp.h"
#include "friremote.h"
#include "Pomiar.h"
#include "Pomiar_cart.h"
#include "Jakobian.h"

#ifndef M_PI
#define M_PI 3.14159
#endif

using namespace std;

int main(int argc, char *argv[])
{
    /**opening infos**/
    {
        cout << "Opening FRI Interface for Program IV" << endl << endl;
    }
    /**checking byte order and datastructures**/
    {
        FRI_PREPARE_CHECK_BYTE_ORDER;
        if (!FRI_CHECK_BYTE_ORDER_OK)
        {
            cerr << "Byte order on your system is not appropriate - expect deep trouble" <<endl;
        }
        if (!FRI_CHECK_SIZES_OK)
        {
            cout << "Sizes of datastructures not appropriate - expect even deeper trouble" << endl;
        }
    }
    /**declaration of variables and objects**/

    friRemote MyFri;
    FRI_QUALITY lastQuality = FRI_QUALITY_UNACCEPTABLE;
    FRI_CTRL lastCtrlScheme = FRI_CTRL_OTHER;

    float newJntVals[LBR_MNJ];          //J[7] - for joint position saving
    double J[FRI_CART_VEC][LBR_MNJ];    //J[6][7] - for Jacobian matrix saving

    unsigned int a=0;
    unsigned int b=0;
    unsigned int c=0;
    unsigned int k=0;
    int s=1;

    /**vectors and iterators for measurement saving**/

    vector<Pomiar> Pom;
    vector<Pomiar>::iterator itr_p;
    vector<Pomiar> Pom_2;
    vector<Pomiar>::iterator itr_p_2;
    vector<Pomiar_cart> Pom_cart;
    vector<Pomiar_cart>::iterator itr_c;
    vector<Jakobian> Jak;
    vector<Jakobian>::iterator itr_j;

    /**petla glowna**/
    for(;;)
    {
        if(c==0)        //c==1, gdy komendy przestana byc wysylane
        {
            switch(MyFri.getState())
            {
            case FRI_STATE_MON:
            {
                if(a==0)
                {
                    cout << "monitor mode entered" << endl;
                    cout << "manual teaching active" << endl;
                    b = 0;
                    a = 1;
                }

                for (int i = 0; i < LBR_MNJ; i++)
                {
                    newJntVals[i] = MyFri.getMsrCmdJntPosition()[i];
                }

                /**zapis danych do wektorow**/
                Pomiar new_pomiar(MyFri.getMsrMsrJntPosition());
                Pom.push_back(new_pomiar);
                Pomiar_cart new_pomiar_cart(MyFri.getMsrBuf().data.msrCartPos);
                Pom_cart.push_back(new_pomiar_cart);
                Jakobian new_jak(MyFri.getMsrBuf().data.jacobian);
                Jak.push_back(new_jak);
                break;
            }
            case FRI_STATE_CMD:
            {
                if (MyFri.isPowerOn())
                {
                    if(b==0)
                    {
                        cout << "command mode entered" << endl;
                        cout << "vectors' size =  " << Pom.size() << endl;
                        b = 1;
                        a = 0;
                    }
                    for (int i = 0; i < LBR_MNJ; i++)
                    {
                        newJntVals[i] = (Pom[0].Pos_Act[i])+(Pom[k].Pos_Act[i]-Pom[0].Pos_Act[i])*s;    //s- wspolczynnik do skalowania ruchu
                    }
                    k++;

                    Pomiar new_pomiar_2(MyFri.getMsrMsrJntPosition());
                    Pom_2.push_back(new_pomiar_2);

                    if (k==Pom.size())
                    {
                        cout << "end of measured positions" << endl;
                        MyFri.setToKRLInt(0,11);    //wyslij informacje o koncu ruchu
                        c=1;
                    }
                }
                break;
            } //end of case FRI_STATE_CMD
            default:
            {
                for (int i = 0; i < LBR_MNJ; i++)
                {
                    newJntVals[i] = MyFri.getMsrCmdJntPosition()[i];
                }
            }
            }   //end of switch
        }   //end of if(c==0)
        MyFri.doPositionControl(newJntVals);
        /**komenda, którą nalezy wywolywac zawsze, nawet w trybie monitor,
        aby zsynchronizowac poczatkowa pozycje zlaczowa
        w FRI i KRC w chwili aktywacji Command Mode**/

        if ( MyFri.getQuality() != lastQuality)     //sygnalizuj zmiane jakosci polaczenia
        {
            cout << "quality change detected: "<< lastQuality << " to: " << MyFri.getQuality() << endl;
            lastQuality=MyFri.getQuality();
        }
        if ( lastCtrlScheme != MyFri.getCurrentControlScheme())     //sygnalizuj zmiane trybu sterowania
        {
            cout << "switching control scheme " << lastCtrlScheme;
            lastCtrlScheme = MyFri.getCurrentControlScheme();
            cout << " to " << lastCtrlScheme;
        }

        if (MyFri.getFrmKRLInt(1)==13)      //zakoncz dzialanie nieskonczonej petli
        {
            cout << "leaving..." << endl;
            break;
        }
    }      //end of for(;;)
    //zapis do plików
    {
        ofstream zapis_poz_mon;
        zapis_poz_mon.open( "pomiar_poz_mon.txt", ios::app);
        if (zapis_poz_mon.good() == true)
        {
            cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }
        ofstream zapis_poz_cart;
        zapis_poz_cart.open( "pomiar_poz_cart.txt", ios::app);
        if (zapis_poz_cart.good() == true)
        {
            cout << "otwarcie pliku do zapisu wspolrzednych kartezjanskich powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }
        ofstream zapis_jakobian;
        zapis_jakobian.open( "pomiar_jakobian.txt", ios::app);
        if (zapis_jakobian.good() == true)
        {
            cout << "otwarcie pliku do zapisu jakobianu powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }
        ofstream zapis_trq;
        zapis_trq.open( "pomiar_trq.txt", ios::app);
        if (zapis_trq.good() == true)
        {
            cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }
        ofstream zapis_poz_cmd;
        zapis_poz_cmd.open( "pomiar_poz.txt", ios::app);
        if (zapis_poz_cmd.good() == true)
        {
            cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }


        for (itr_p=Pom.begin(); itr_p!=Pom.end(); ++itr_p)
        {
            zapis_poz_mon << *itr_p;
        }
        zapis_poz_mon.close();

        for (itr_c=Pom_cart.begin(); itr_c!=Pom_cart.end(); ++itr_c)
        {
            zapis_poz_cart << *itr_c;
        }
        zapis_poz_cart.close();

        for (itr_j=Jak.begin(); itr_j!=Jak.end(); ++itr_j)
        {
            zapis_jakobian << *itr_j;
        }
        zapis_jakobian.close();

        for (itr_p_2=Pom_2.begin(); itr_p_2!=Pom_2.end(); ++itr_p_2)
        {
            zapis_poz_cmd << *itr_p_2;
        }
        zapis_poz_cmd.close();


    }

    return EXIT_SUCCESS;
}


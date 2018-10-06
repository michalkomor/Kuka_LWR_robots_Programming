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
    /**opening infos**/{
        cout << "Opening FRI Interface for Program VI" << endl << endl;
    }
    /**checking byte order and datastructures**/{
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
    float newJntTrq[LBR_MNJ];
    double J[FRI_CART_VEC][LBR_MNJ];    //J[6][7] - for Jacobian matrix saving

    unsigned int a=0;
    unsigned int b=0;
    unsigned int c=0;
    unsigned int k=0;
    int s=1;

    /**vectors and iterators for measurement saving**/

    vector<Pomiar> Pom;
    vector<Pomiar>::iterator itr_p;
    vector<Pomiar> Pom_pos;
    vector<Pomiar>::iterator itr_pos;
    vector<Pomiar> Pom_pos_2;
    vector<Pomiar>::iterator itr_pos_2;


    for (int i = 0; i < LBR_MNJ; i++)
    {
        newJntTrq[i] = 0.0;
    }
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
                Pomiar new_pomiar(MyFri.getMsrEstExtJntTrq());
                Pom.push_back(new_pomiar);
                Pomiar new_pomiar_pos(MyFri.getMsrMsrJntPosition());
                Pom_pos.push_back(new_pomiar_pos);

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
                        newJntTrq[i] = (Pom[k].Trq_Act[i]);
                    }
                    k++;

                    Pomiar new_pomiar_pos_2(MyFri.getMsrMsrJntPosition());
                    Pom_pos_2.push_back(new_pomiar_pos_2);

                    if (k==Pom.size())
                    {
                        cout << "end of measured torques" << endl;
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
                    newJntVals[i] = MyFri.getMsrMsrJntPosition()[i];
                }
            }
            }   //end of switch
        }   //end of if(c==0)
        MyFri.doJntImpedanceControl(NULL,NULL,NULL,newJntTrq);
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
            cout << " to " << lastCtrlScheme << endl;
        }

        if (MyFri.getFrmKRLInt(1)==13)      //zakoncz dzialanie nieskonczonej petli
        {
            cout << "leaving..." << endl;
            break;
        }
    }      //end of for(;;)
    //zapis do plików
    {
        ofstream zapis_momentow;
        zapis_momentow.open( "pomiar_trq.txt", ios::app);
        if (zapis_momentow.good() == true)
        {
            cout << "otwarcie pliku do zapisu momentow powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }
        ofstream zapis_poz;
        zapis_poz.open( "pomiar_poz.txt", ios::app);
        if (zapis_poz.good() == true)
        {
            cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }
        ofstream zapis_poz_2;
        zapis_poz_2.open( "pomiar_poz_2.txt", ios::app);
        if (zapis_poz_2.good() == true)
        {
            cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych 2 powiodlo sie" << endl;
        }
        else
        {
            cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
        }


        for (itr_p=Pom.begin(); itr_p!=Pom.end(); ++itr_p)
        {
            zapis_momentow << *itr_p;
        }
        zapis_momentow.close();



        for (itr_pos=Pom_pos.begin(); itr_pos!=Pom_pos.end(); ++itr_pos)
        {
            zapis_poz << *itr_pos;
        }
        zapis_poz.close();

        for (itr_pos_2=Pom_pos_2.begin(); itr_pos_2!=Pom_pos_2.end(); ++itr_pos_2)
        {
            zapis_poz_2 << *itr_pos_2;
        }
        zapis_poz_2.close();


    }

    return EXIT_SUCCESS;
}


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
    cout << "Opening FRI Interface for Program V" << endl;

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

    /**deklaracja obiektów i zmiennych**/
    friRemote LWR_1(49938);
    friRemote LWR_2(49939);
    FRI_QUALITY lastQuality_LWR_1 = FRI_QUALITY_UNACCEPTABLE;
    FRI_QUALITY lastQuality_LWR_2 = FRI_QUALITY_UNACCEPTABLE;
    float newJntVals_LWR_1[LBR_MNJ];
    float newJntVals_LWR_2[LBR_MNJ];

    for (int j = 0; j < 16; j++)
    {
        LWR_1.setToKRLInt(j,0);
        LWR_1.setToKRLReal(j,0.0);
        LWR_2.setToKRLInt(j,0);
        LWR_2.setToKRLReal(j,0.0);
    }

    /**vectory do zapisywania pomiarów**/
    vector<Pomiar> Pom_lwr_1;
    vector<Pomiar>::iterator itr_lwr_1;
    vector<Pomiar> Pom_lwr_2;
    vector<Pomiar>::iterator itr_lwr_2;

    /**zmienne pomocnicze**/
    unsigned int k=0;
    unsigned int a=0;
    unsigned int b=0;

    //zapisz aktualną pozycję w złączach
    for (int i = 0; i < LBR_MNJ; i++)
    {
        newJntVals_LWR_1[i] = LWR_1.getMsrCmdJntPosition()[i];
        newJntVals_LWR_2[i] = LWR_2.getMsrCmdJntPosition()[i];
    }

//petla główna

    for(;;)
    {

        LWR_2.doPositionControl(newJntVals_LWR_2);
        LWR_1.doDataExchange();

        for (int i = 0; i < LBR_MNJ; i++)
        {
            newJntVals_LWR_1[i] = LWR_1.getMsrCmdJntPosition()[i];
            newJntVals_LWR_2[i] = LWR_2.getMsrCmdJntPosition()[i];
        }

        if(LWR_1.getFrmKRLInt(0)==1)
        {
            if(LWR_2.getFrmKRLInt(0)==1)
            {
                if(a==0)
                {
                    LWR_1.setToKRLInt(1,9);
                    LWR_2.setToKRLInt(1,9);
                    cout << "both robots reached starting position" << endl;
                    a=1;
                }

                if(LWR_1.getState()==FRI_STATE_MON)
                {
                    if(LWR_2.getState()==FRI_STATE_CMD)
                    {
                        LWR_1.setToKRLInt(7,1);

                        if(b==0)
                        {
                            cout << "monitor mode entered at LWR 1" << endl;
                            cout << "command mode entered at LWR 2" << endl;
                            cout << "************START************" << endl;
                            b=1;
                        }
                        Pomiar new_pomiar(LWR_1.getMsrMsrJntPosition());
                        Pom_lwr_1.push_back(new_pomiar);
                        Pomiar new_pomiar_2(LWR_2.getMsrMsrJntPosition());
                        Pom_lwr_2.push_back(new_pomiar_2);
                        for (int i = 0; i < LBR_MNJ; i++)
                        {
                            newJntVals_LWR_2[i] = Pom_lwr_1[k].Pos_Act[i];
                        }
                        k++;
                    }
                }
            }
        }
        if((LWR_1.getFrmKRLInt(2) == 7))
        {
            LWR_2.setToKRLInt(2,21);
            if((LWR_2.getFrmKRLInt(2 ) == 7))
            {
                cout << endl << "process completed... leaving" << endl;
                break;
            }
        }

        if ( LWR_2.getQuality() != lastQuality_LWR_2)
        {
            cout << "quality change detected at LWR 2: "<< lastQuality_LWR_2 << " to: " << LWR_2.getQuality() << endl;
            lastQuality_LWR_2=LWR_2.getQuality();
        }

        if ( LWR_1.getQuality() != lastQuality_LWR_1)
        {
            cout << "quality change detected at LWR 1: "<< lastQuality_LWR_1 << " to: " << LWR_1.getQuality() << endl;
            lastQuality_LWR_1=LWR_1.getQuality();
        }


    }


    ofstream JntPos_lwr_1;
    JntPos_lwr_1.open( "JntPos_lwr_1.txt", ios::app);
    if (JntPos_lwr_1.good() == true)
    {
        cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych LWR 1 powiodlo sie" << endl;
    }
    else
    {
        cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
    }

    for (itr_lwr_1=Pom_lwr_1.begin(); itr_lwr_1!=Pom_lwr_1.end(); ++itr_lwr_1)
    {
        JntPos_lwr_1 << *itr_lwr_1;
    }
    JntPos_lwr_1.close();

    ofstream JntPos_lwr_2;
    JntPos_lwr_2.open( "JntPos_lwr_2.txt", ios::app);
    if (JntPos_lwr_2.good() == true)
    {
        cout << "otwarcie pliku do zapisu wspolrzednych zlaczowych LWR 2 powiodlo sie" << endl;
    }
    else
    {
        cout << "otwarcie pliku nie bardzo sie powiodlo" << endl;
    }

    for (itr_lwr_2=Pom_lwr_2.begin(); itr_lwr_2!=Pom_lwr_2.end(); ++itr_lwr_2)
    {
        JntPos_lwr_2 << *itr_lwr_2;
    }
    JntPos_lwr_2.close();



    return EXIT_SUCCESS;
}


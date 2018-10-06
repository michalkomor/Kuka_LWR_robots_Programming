
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include "friudp.h"
#include "friremote.h"
#include "Pomiar.h"
#include "Pomiar_cart.h"
#include "vector"
#include <fstream>

#ifndef M_PI
#define M_PI 3.14159
#endif

using namespace std;


int main(int argc, char *argv[])
{

    cout << "Opening FRI Interface for Program II" << endl;

    friRemote MyFri2;
    FRI_QUALITY lastQuality = FRI_QUALITY_UNACCEPTABLE;
    FRI_CTRL lastCtrlScheme = FRI_CTRL_OTHER;
    float newCartVals[FRI_CART_FRM_DIM];
    float newForceTorqueAdd[FRI_CART_VEC];
    float newJntTrq[LBR_MNJ];

    double timeCounter=0;
    double timeCounter2=0;
    double timeCounter3=0;
    double timeCounter4=0;

    vector<Pomiar> Pom;
    vector<Pomiar>::iterator itr_p;
    vector<Pomiar_cart> Pom_cart;
    vector<Pomiar_cart>::iterator itr_c;

    // do one handshake before the endless loop
    MyFri2.doDataExchange();
    for (int i = 0; i < FRI_CART_VEC; i++)
    {
        newForceTorqueAdd[i] = 0.0;
    }
    for (int i = 0; i < LBR_MNJ; i++)
    {
        newJntTrq[i] = 0.0;
    }
    /** enter main loop - wait until we enter stable command mode */
    for(;;)
    {

        switch ( MyFri2.getCurrentControlScheme())
        {
        case   FRI_CTRL_POSITION:
        case   FRI_CTRL_JNT_IMP:
        {
            for (int i = 0; i < LBR_MNJ; i++)
            {
                newJntTrq[i] = 0.0;
            }
            if ( MyFri2.getState() == FRI_STATE_CMD)
            {
                if ( MyFri2.isPowerOn() )
                {
                    timeCounter+=MyFri2.getSampleTime();
                    for (int i = 0; i < 5; i++)
                    {
                        newJntTrq[i]=(float)sin( timeCounter * M_PI * 0.2) * 40;
                    }
                }
                else
                {
                    timeCounter=0.;
                }
            }
            else
            {
                timeCounter=0.;
            }
            MyFri2.doJntImpedanceControl(NULL,NULL,NULL,newJntTrq);
            Pomiar new_pomiar(MyFri2.getMsrMsrJntPosition());
            Pom.push_back(new_pomiar);
            break;
        }

        case FRI_CTRL_CART_IMP:
        {
            for (int i = 0; i < FRI_CART_FRM_DIM; i++)
            {
                newCartVals[i] = MyFri2.getMsrCartPosition()[i];
            }
            for (int i = 0; i < FRI_CART_VEC; i++)
            {
                newForceTorqueAdd[i] = 0.0;
            }
            if ( MyFri2.getState() == FRI_STATE_CMD)
            {
                if ( MyFri2.isPowerOn() )
                {
                    if ( MyFri2.getFrmKRLInt(1) == 1)
                    {
                        timeCounter3+=MyFri2.getSampleTime();
                        for (int i = 1; i <= 3; i++)
                        {
                            newCartVals[(i*4)-1]+=(float)sin( timeCounter3 * M_PI * 0.02) * (0.05f);
                        }
                        cout << 1 ;
                    }
                    if ( MyFri2.getFrmKRLInt(1) == 2 )
                    {
                        timeCounter2+=MyFri2.getSampleTime();
                        for (int i = 0; i < 3; i++)
                        {
                            newForceTorqueAdd[i]=(float)sin( timeCounter2 * M_PI * 0.3) * (5.5);
                        }
                        cout << 2 ;
                    }
                    if ( MyFri2.getFrmKRLInt(1) == 3)
                    {
                        timeCounter4+=MyFri2.getSampleTime();
                        for (int i = 1; i <= 3; i++)
                        {
                            newCartVals[(i*4)-1]+=(float)sin( timeCounter4 * M_PI * 0.02) * (0.05f);
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            newForceTorqueAdd[i]=(float)sin( timeCounter4 * M_PI * 0.3) * (5.5);
                        }
                        cout << 3 ;
                    }
                }
                else
                {
                    timeCounter2=0.;
                    timeCounter3=0.;
                    timeCounter4=0.;
                }
            }
            else
            {
                timeCounter2=0.;
                timeCounter3=0.;
                timeCounter4=0.;
            }
            MyFri2.doCartesianImpedanceControl(newCartVals,NULL,NULL,newForceTorqueAdd);
            Pomiar_cart new_pomiar_cart(MyFri2.getMsrBuf().data.msrCartPos);
            Pom_cart.push_back(new_pomiar_cart);
            break;
        }

        default:
        {
            MyFri2.doDataExchange();
        }
        }


        if ( MyFri2.getFrmKRLInt(0) == -1)
        {
            cout << "leaving \n";
            break;
        }


        if ( MyFri2.getQuality() != lastQuality)
        {
            cout << "quality change detected "<< MyFri2.getQuality()<< " \n";
            cout << endl;
            lastQuality=MyFri2.getQuality();
        }
        if ( lastCtrlScheme != MyFri2.getCurrentControlScheme())
        {
            cout << "switching control scheme " << lastCtrlScheme;
            lastCtrlScheme = MyFri2.getCurrentControlScheme();
            cout << " to " << lastCtrlScheme << endl;
        }

    }

    ofstream zapis_poz_mon;
    zapis_poz_mon.open( "pomiar_poz_jnt.txt", ios::app);
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


    return EXIT_SUCCESS;
}

/* @} */

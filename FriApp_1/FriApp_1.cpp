#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include <vector>
#include <fstream>
#include "friudp.h"
#include "friremote.h"
#include "Pomiar.h"

#ifndef M_PI
#define M_PI 3.14159
#endif

using namespace std;

int main(int argc, char *argv[])
{

    /**opening infos**/
    {
        cout << "Opening FRI Interface for Program I" << endl << endl;
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

    friRemote friInst;
    FRI_QUALITY lastQuality = FRI_QUALITY_BAD;
    double timeCounter=0;
    float newJntVals[LBR_MNJ];
    vector<Pomiar> Pom;
    vector<Pomiar>::iterator itr_p;

    /**petla glowna**/
    for(;;)
    {

        for (int i = 0; i < LBR_MNJ; i++)
        {
            newJntVals[i] = friInst.getMsrCmdJntPosition()[i];
        }

        Pomiar new_pomiar(friInst.getMsrCmdJntPosition());
        Pom.push_back(new_pomiar);

        if ( friInst.getState() == FRI_STATE_CMD)
        {
            if ( friInst.isPowerOn() )
            {
                timeCounter+=friInst.getSampleTime();
                for (int i = 0; i < LBR_MNJ; i++)
                {
                    newJntVals[i]+=(float)sin( timeCounter * M_PI * 0.02) * (float)(30./180.*M_PI);
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
        friInst.doPositionControl(newJntVals);


        int divider = (int)( (1./friInst.getSampleTime()) *2.0);

        if ( friInst.getSequenceCount() % divider == 0)  //TO BARDZO SPOWALNIA KOMUNIKACJE
        {
            cout << "krl interaction \n";
            cout << friInst.getMsrBuf().krl;
            cout << "intf stat interaction \n";
            cout << friInst.getMsrBuf().intf.stat;
            cout << "smpl " << friInst.getSampleTime();

            cout << endl;
        }

        if ( friInst.getFrmKRLInt(0) == -1)
        {
            cout << "leaving \n";
            break;
        }

        if ( friInst.getQuality() != lastQuality)
        {
            cout << "quality change detected "<< friInst.getQuality()<< " \n";
            //cout << friInst.getMsrBuf().intf;
            cout << endl;
            lastQuality=friInst.getQuality();
        }
    }

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
    for (itr_p=Pom.begin(); itr_p!=Pom.end(); ++itr_p)
    {
        zapis_poz_mon << *itr_p;
    }
    zapis_poz_mon.close();

    return EXIT_SUCCESS;
}


#include "Pomiar.h"

Pomiar::Pomiar()
{
    //ctor
}

Pomiar::~Pomiar()
{
    //dtor
}

Pomiar::Pomiar(const float *JntValues)
{
    for(int i=0; i<LBR_MNJ; i++)
    {
        Pos_Act[i]=JntValues[i];
    }

}

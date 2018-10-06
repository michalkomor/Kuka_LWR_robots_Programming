#include "Jakobian.h"

Jakobian::Jakobian()
{
    //ctor
}

Jakobian::~Jakobian()
{
    //dtor
}

Jakobian::Jakobian(const float *Jacobian)
{
    for ( int i = 0; i < FRI_CART_VEC; i++)
    {
        for ( int j = 0; j < LBR_MNJ; j++)
        {
            Jak[i][j]=Jacobian[i*LBR_MNJ+j];
        }
    }
}

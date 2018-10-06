#include "Pomiar_cart.h"

Pomiar_cart::Pomiar_cart()
{
    //ctor
}

Pomiar_cart::~Pomiar_cart()
{
    //dtor
}
Pomiar_cart::Pomiar_cart(const float *CartPos)
{
    for(int i=0; i<FRI_CART_FRM_DIM; i++)
    {
        Pos_Cart[i]=CartPos[i];
    }

}

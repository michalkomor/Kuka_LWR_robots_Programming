#ifndef POMIAR_CART_H
#define POMIAR_CART_H

#include <iostream>
#include "friremote.h"


class Pomiar_cart
{
public:
    Pomiar_cart();
    Pomiar_cart(const float *CartPos);
    virtual ~Pomiar_cart();
    float Pos_Cart[FRI_CART_FRM_DIM];
protected:
private:
};

inline std::ostream & operator<<(std::ostream &out , Pomiar_cart& pp)
{
    for(int i=0; i<FRI_CART_FRM_DIM; i++)
    {
        out << " " << pp.Pos_Cart[i];
    }
    out << "\n";

    return out;
}
#endif // POMIAR_CART_H

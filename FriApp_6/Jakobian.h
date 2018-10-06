#ifndef JAKOBIAN_H
#define JAKOBIAN_H

#include <iostream>
#include "friremote.h"



class Jakobian
{
public:
    Jakobian();
    virtual ~Jakobian();
    Jakobian(const float *Jacobian);
    float Jak[FRI_CART_VEC][LBR_MNJ];
protected:
private:
};

inline std::ostream & operator<<(std::ostream &out , Jakobian& jj)
{
    for ( int i = 0; i < FRI_CART_VEC; i++)
    {
        for ( int j = 0; j < LBR_MNJ; j++)
        {
            out << jj.Jak[i][j] << "\t";
        }
        out << std::endl;
    }

    return out;
}

#endif // JAKOBIAN_H

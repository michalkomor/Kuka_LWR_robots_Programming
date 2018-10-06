#ifndef POMIAR_H
#define POMIAR_H

#include <iostream>
#include "friremote.h"

class Pomiar
{
    public:
        Pomiar();
        Pomiar(const float *JntValues);
        virtual ~Pomiar();
        float Pos_Act[LBR_MNJ];
    protected:
    private:
};

inline std::ostream & operator<<(std::ostream &out , Pomiar& pp)
{
    for(int i=0;i<7;i++)
    {
        out << " " << pp.Pos_Act[i];
    }
        out << "\n";

    return out;
}


#endif // POMIAR_H

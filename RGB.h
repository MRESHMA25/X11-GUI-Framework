#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB{
    public :
        RGB(int r, int b, int g);
        RGB(CuColour colour);
        RGB();
        int getR();
        int getB();
        int getG();
        void setR(int r);
        void setB(int b);
        void setG(int g);
        void setColour(CuColour colour);

        CuColour getColour();

    private:
        int r;
        int b;
        int g;

};

#endif
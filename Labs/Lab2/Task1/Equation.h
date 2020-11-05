#ifndef EQUATION_H
#define EQUATION_H

namespace Eq
{
    class Quadratic{
        private:
        double a,b,c,x1,x2,deter;

        public:
        void setEquation(double _a,double _b, double _c);
        void showEquation();
        void calculateEquation();
    };
}

#endif
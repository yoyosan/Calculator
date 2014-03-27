#ifndef OPERATII_H_INCLUDED
#define OPERATII_H_INCLUDED

#include "exceptii.h"

namespace Calculator
{
    namespace Calcule
    {
        template<typename T>
        T Add(T x, T y)
        {
            return x + y;
        }

        template<typename T>
        T Sub(T x, T y)
        {
            return x - y;
        }

        template<typename T>
        T Mult(T x, T y)
        {
            return x * y;
        }

        template<typename T>
        T Div(T x, T y)
        {
            if (y == (T)0) {
                throw ImpartireLaZero();
            }

            return x / y;
        }

        template<typename T>
        T Mod(T x, T y)
        {
            if (y == (T)0) {
                throw ImpartireLaZero();
            }

            return x % y;
        }
    }
}

#endif // OPERATII_H_INCLUDED

#include "combinatorial.h"
#include "exceptii.h"

namespace Calculator
{
    namespace Calcule
    {
        int Factorial(int n)
        {
            if (n < 0 || n > 12) {
                throw InvalidN();
            }

            if (n == 0) {
                return 1;
            }

            int result = 1;
            for (int i = 1; i <= n; ++i) {
                result *= i;
            }

            return result;
        }

        int Aranjamente(int n, int k)
        {
            if (k < 0 || k > n)
            {
                throw InvalidK();
            }

            return Factorial(n) / Factorial(n - k);
        }

        int Combinari(int n, int k)
        {
            return Aranjamente(n , k) / Factorial(k);
        }
    }
}

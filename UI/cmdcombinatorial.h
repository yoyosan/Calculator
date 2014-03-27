#ifndef CMDCOMBINATORIAL_H_INCLUDED
#define CMDCOMBINATORIAL_H_INCLUDED

#include "comanda.h"
#include "../Calcule/exceptii.h"

using namespace Calculator::Calcule;

namespace Calculator
{
    namespace UI
    {
        template<int Operatie(int), int MAX, int MIN = 0>
        class CmdCombinatorial1 : public ComandaCalcule
        {
        public:
            CmdCombinatorial1(const string &nume) : ComandaCalcule(nume) {}
            ~CmdCombinatorial1() {}

            void Execute()
            {
                cout << "Introduceti un numar intreg in intervalul ["
                    << MIN << ", " << MAX << "]." << endl;
                int n;
                cout << "Dati n = ";
                cin >> n;

                if (n < MIN || n > MAX)
                {
                    throw ParametruInAfaraIntervalului();
                }

                cout << Nume() << "(" << n << ") = " << Operatie(n) << endl;
            }
        };

        template<int Operatie(int, int), int MAX, int MIN = 0>
        class CmdCombinatorial2 : public ComandaCalcule
        {
            void verificaParametru(int param, Exceptie e)
            {
                if (param < MIN || param > MAX)
                {
                    throw e;
                }
            }
        public:
            CmdCombinatorial2(const string &nume) : ComandaCalcule(nume) {}
            ~CmdCombinatorial2() {}

            void Execute()
            {
                cout << "Introduceti doua numere intregi(n, k, n > k), in intervalul ["
                    << MIN << ", " << MAX << "]." << endl;
                int n, k;
                cout << "Dati n = ";
                cin >> n;

                verificaParametru(n, InvalidN());

                cout << "Dati k = ";
                cin >> k;

                verificaParametru(k, InvalidK());

                cout << endl << Nume() << "(" << n << ", " << k << ") = " << Operatie(n, k) << endl;
            }
        };
    }
}


#endif // CMDCOMBINATORIAL_H_INCLUDED

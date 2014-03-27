#include "comanda.h"
#include "cmdcombinatorial.h"
#include "../Calcule/exceptii.h"

using namespace Calculator::Calcule;

namespace Calculator
{
    namespace UI
    {
        CmdCombinatorial1::CmdCombinatorial1(const string &nume) : ComandaCalcule(nume) {}
        CmdCombinatorial1::~CmdCombinatorial1() {}

        void CmdCombinatorial1::Execute()
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

        CmdCombinatorial2::CmdCombinatorial2(const string &nume) : ComandaCalcule(nume) {}
        CmdCombinatorial2::~CmdCombinatorial2() {}

        bool CmdCombinatorial2::verificaParametru(int param)
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

        CmdCombinatorial2::Execute()
        {
            cout << "Introduceti doua numere intregi(n, k, n > k), in intervalul ["
                << MIN << ", " << MAX << "]." << endl;
            int n, k;
            cout << "Dati n = ";
            cin >> n;

            verificaParametru(n);

            cout << "Dati k = ";
            cin >> k;

            verificaParametru(k);

            cout << Nume() << "(" << n << ", " << k << ") = " << Operatie(n, k) << endl;
        }
    }
}

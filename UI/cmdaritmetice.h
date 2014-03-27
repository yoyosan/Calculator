#ifndef CMDARITMETICE_H_INCLUDED
#define CMDARITMETICE_H_INCLUDED

#include "comanda.h"

namespace Calculator
{
    namespace UI
    {
        template<int Operatie(int, int)>
        class CmdAritmetice : public ComandaCalcule
        {
        public:
            CmdAritmetice(const string& nume) : ComandaCalcule(nume) {}
            ~CmdAritmetice() {}

            void Execute()
            {
                cout << "Introduceti doua numere intregi (x, y)." << endl;
                int x, y;
                cout << "Dati x = ";
                cin >> x;
                cout << "Dati y = ";
                cin >> y;
                cout << endl << x << " " << Nume() << " " << y << " = " << Operatie(x, y) << endl;
            }
        };
    }
}

#endif // CMDARITMETICE_H_INCLUDED

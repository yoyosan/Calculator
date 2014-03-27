#ifndef CMDSIRURI_H_INCLUDED
#define CMDSIRURI_H_INCLUDED

#include "comanda.h"
#include "../Calcule/exceptii.h"

namespace Calculator
{
    namespace UI
    {
        template<typename SirNumere, int MAX, int MIN = 0>
        class CmdSiruri : public ComandaCalcule
        {
            SirNumere _sir;
        public:
            CmdSiruri(const string &nume) : ComandaCalcule(nume) {}

            void Execute()
            {
                cout << "Introduceti un numar intreg in intervalul ["
                    << MIN << ", " << MAX << "]." << endl;
                int n;
                cout << "Dati n = ";
                cin >> n;

                if (n < MIN || n > MAX)
                {
                    throw Calculator::Calcule::ParametruInAfaraIntervalului();
                }

                cout << endl << "Sirul " << Nume() << "[" << MIN << " - " << n << "]:\n" << _sir(n) << endl;
            }
        };
    }
}

#endif // CMDSIRURI_H_INCLUDED

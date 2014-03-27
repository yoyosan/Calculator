#include <iostream>
#include "comanda.h"

using namespace std;

namespace Calculator
{
    namespace UI
    {
        ComandaCalcule::ComandaCalcule(const string& nume) : Comanda::Comanda(nume) {}
        ComandaCalcule::~ComandaCalcule() {}

        void ComandaCalcule::AsteaptaEnter()
        {
            cout << "Apasati Enter pentru a continua...";
            cin.ignore(1, '\n');
            char ch;
            cin.get(ch);
        }
    }
}

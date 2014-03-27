#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits>

#include "meniu.h"
#include "../Calcule/exceptii.h"

using namespace Calculator::Calcule;

namespace Calculator
{
    namespace UI
    {
        void DeleteComanda(Comanda *&pcmd)
        {
            delete pcmd;
        }

        Meniu::Meniu(const string& nume) : Comanda(nume) {}


        Meniu::~Meniu()
        {
            for_each (_comenzi.begin(), _comenzi.end(), DeleteComanda);
        }

        void Meniu::Execute()
        {
            Index idx;
            do
            {
                StergeEcran();
                cout << Nume() << endl;
                for_each (_comenzi.begin(), _comenzi.end(), AfiseazaComanda());
            } while (!CitesteIndex(idx));

            try
            {
                _comenzi[idx]->Execute();
            } catch (Exceptie e)
            {
                cout << e << endl;
            }
            _comenzi[idx]->AsteaptaEnter();
        }

        void Meniu::AdaugaComanda(Comanda *comanda)
        {
            _comenzi.push_back(comanda);
        }

        void Meniu::StergeEcran()
        {
            #if defined(_WIN32) || defined(_WIN64)
                #define ERASE "cls"
            #else
                #define ERASE "clear"
            #endif

            system(ERASE);
        }

        bool Meniu::CitesteIndex(Index &index)
        {
            // reseteaza erorile din cin
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Dati indexul: ";
            cin >> index;

            if (cin.fail())
            {
                return false;
            }

            return IndexValid(index);
        }

        AfiseazaComanda::AfiseazaComanda()
        {
            _index = 0;
        }

        void AfiseazaComanda::operator () (Comanda *comanda)
        {
            cout << "\t" << _index++ << " " << comanda->Nume() << endl;
        }
    }
}

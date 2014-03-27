#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include <vector>
#include "comanda.h"

using namespace std;

namespace Calculator
{
    namespace UI
    {
        typedef vector<Comanda*> TCommands;
        typedef TCommands::size_type Index;

        void DeleteComanda(Comanda *&pcmd);

        class Meniu : public Comanda
        {
            TCommands _comenzi;

            void StergeEcran();
            bool IndexValid(Index index)
            {
                return (index >= 0 && index < _comenzi.size());
            }

            bool CitesteIndex(Index &index);
        public:
            Meniu(const string& nume);
            virtual ~Meniu();

            void Execute();
        protected:
            void AdaugaComanda(Comanda *comanda);

        };

        class AfiseazaComanda
        {
            int _index; // index comanda

        public:
            AfiseazaComanda();
            void operator() (Comanda *comanda);
        };
    }
}

#endif // MENIU_H_INCLUDED

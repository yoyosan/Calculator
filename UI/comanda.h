#ifndef COMANDA_H_INCLUDED
#define COMANDA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

namespace Calculator
{
    namespace UI
    {
        class Comanda
        {
        protected:
            const string _nume; // nume comanda

        public:
            Comanda(const string& nume) : _nume(nume) {}
            virtual ~Comanda() {}

            const string& Nume() const
            {
                return _nume;
            }

            virtual void AsteaptaEnter() {}

            virtual void Execute() = 0;
        };

        // ComandaCalcule
        class ComandaCalcule : public Comanda
        {
        public:
            ComandaCalcule(const string& nume);
            ~ComandaCalcule();

            void AsteaptaEnter();
        };
    }
}


#endif // COMANDA_H_INCLUDED

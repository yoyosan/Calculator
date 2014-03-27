#ifndef EXCEPTII_H_INCLUDED
#define EXCEPTII_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

namespace Calculator
{
    namespace Calcule
    {
        struct Exceptie
        {
            Exceptie(const string &mesaj) : _mesaj(mesaj) {}

            virtual ~Exceptie() {}

            friend ostream& operator << (ostream &out, const Exceptie &e)
            {
                return out << endl
                    << "-----------------------------------------------" << endl
                    << "Eroare: " << e._mesaj << endl
                    << "-----------------------------------------------" << endl;
            }
        protected:
            string _mesaj;
        };

        struct ImpartireLaZero : public Exceptie
        {
            ImpartireLaZero(const string &mesaj = "Impartire la zero!") : Exceptie(mesaj) {}
            ~ImpartireLaZero() {}
        };

        struct ParametruInAfaraIntervalului : public Exceptie
        {
            ParametruInAfaraIntervalului(const string &mesaj = "Parametru in afara intervalului!") : Exceptie(mesaj) {}
            ~ParametruInAfaraIntervalului() {}
        };

        struct InvalidK : public Exceptie
        {
            InvalidK(const string &mesaj = "Valoarea lui k este incorecta!") : Exceptie(mesaj) {}
            ~InvalidK() {}
        };

        struct InvalidN : public Exceptie
        {
            InvalidN(const string &mesaj = "Valoarea lui n este incorecta!") : Exceptie(mesaj) {}
            ~InvalidN() {}
        };
    }
}


#endif // EXCEPTII_H_INCLUDED

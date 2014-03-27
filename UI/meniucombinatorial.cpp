#include "../Calcule/combinatorial.h"
#include "cmdcombinatorial.h"
#include "cmdexit.h"
#include "meniucombinatorial.h"

namespace Calculator
{
    namespace UI
    {
        MeniuCombinatorial::MeniuCombinatorial() : Meniu::Meniu("Combinatorial")
        {
            AdaugaComanda(new CmdExit);
            AdaugaComanda(new CmdCombinatorial1<Calculator::Calcule::Factorial, 12>("Factorial"));
            AdaugaComanda(new CmdCombinatorial2<Calculator::Calcule::Aranjamente, 12>("Aranjamente"));
            AdaugaComanda(new CmdCombinatorial2<Calculator::Calcule::Combinari, 12>("Combinari"));
        }
    }
}

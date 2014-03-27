#include "../Calcule/siruri.h"
#include "cmdsiruri.h"
#include "cmdexit.h"
#include "meniusiruri.h"

using namespace Calculator::Calcule;

namespace Calculator
{
    namespace UI
    {
        MeniuSiruri::MeniuSiruri() : Meniu::Meniu("Siruri Numerice")
        {
            AdaugaComanda(new CmdExit);
            AdaugaComanda(new CmdSiruri<Fibonacci, Fibonacci::MAX>("Fibonacci"));
            AdaugaComanda(new CmdSiruri<Lucas, Lucas::MAX>("Lucas"));
            AdaugaComanda(new CmdSiruri<Pell, Pell::MAX>("Pell"));
            AdaugaComanda(new CmdSiruri<Triangular, Triangular::MAX>("Triangular"));
            AdaugaComanda(new CmdSiruri<Pentagonal, Pentagonal::MAX>("Pentagonal"));
            AdaugaComanda(new CmdSiruri<Prime, Prime::MAX>("Prime"));
        }
    }
}

#include "meniuoperatiiaritmetice.h"
#include "cmdexit.h"
#include "cmdaritmetice.h"
#include "../Calcule/operatii.h"

namespace Calculator
{
    using namespace Calcule;

    namespace UI
    {
        MeniuOperatiiAritmetice::MeniuOperatiiAritmetice() : Meniu::Meniu("Operatii aritmetice intregi")
        {
            AdaugaComanda(new CmdExit);
            AdaugaComanda(new CmdAritmetice<Add>("+"));
            AdaugaComanda(new CmdAritmetice<Sub>("-"));
            AdaugaComanda(new CmdAritmetice<Mult>("*"));
            AdaugaComanda(new CmdAritmetice<Div>("/"));
            AdaugaComanda(new CmdAritmetice<Mod>("%"));
        }
    }
}

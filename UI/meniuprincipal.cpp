#include "meniuoperatiiaritmetice.h"
#include "meniucombinatorial.h"
#include "meniusiruri.h"
#include "meniuprincipal.h"

namespace Calculator
{
    namespace UI
    {
        MeniuPrincipal::MeniuPrincipal() : Meniu::Meniu("Proiect Final C++")
        {
            _pExit = new CmdExit("Exit");
            AdaugaComanda(_pExit);
            AdaugaComanda(new MeniuOperatiiAritmetice);
            AdaugaComanda(new MeniuCombinatorial);
            AdaugaComanda(new MeniuSiruri);
        }

        bool MeniuPrincipal::Exit()
        {
            return _pExit->Exit();
        }
    }
}

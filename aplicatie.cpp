#include "aplicatie.h"
#include "UI/meniuprincipal.h"

namespace Calculator
{
    using namespace UI;

    void Aplicatie::Run()
    {
        MeniuPrincipal mp;
        do
        {
            mp.Execute();
        } while (!mp.Exit());
    }
}

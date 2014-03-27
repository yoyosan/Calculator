#ifndef MENIUPRINCIPAL_H_INCLUDED
#define MENIUPRINCIPAL_H_INCLUDED

#include "meniu.h"
#include "cmdexit.h"

namespace Calculator
{
    namespace UI
    {
        class MeniuPrincipal : public Meniu
        {
            CmdExit *_pExit;

        public:
            MeniuPrincipal();

            bool Exit();
        };
    }
}

#endif // MENIUPRINCIPAL_H_INCLUDED

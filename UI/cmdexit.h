#ifndef CMDEXIT_H_INCLUDED
#define CMDEXIT_H_INCLUDED

#include "comanda.h"

namespace Calculator
{
    namespace UI
    {
        class CmdExit : public ComandaCalcule
        {
            bool _exit;

        public:
            CmdExit(const string& text = "Inapoi");
            ~CmdExit();

            void Execute();
            bool Exit();
        };
    }
}

#endif // CMDEXIT_H_INCLUDED

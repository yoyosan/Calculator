#include "cmdexit.h"

namespace Calculator
{
    namespace UI
    {
        CmdExit::CmdExit(const string& text) : ComandaCalcule(text)
        {
            _exit = false;
        }

        CmdExit::~CmdExit() {}

        void CmdExit::Execute()
        {
            _exit = true;
        }

        bool CmdExit::Exit()
        {
            return _exit;
        }
    }
}

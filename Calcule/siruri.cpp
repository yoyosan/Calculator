#include <cmath>
#include <algorithm>

#include "exceptii.h"
#include "siruri.h"

using namespace std;

namespace Calculator
{
    namespace Calcule
    {
        ///////////////////////////////
        // Definire metode clasa Sir //
        ///////////////////////////////

        Sir::Sir()
        {
            _count = 0;
        }

        Sir::~Sir() {}

        Uint Sir::operator [] (int index)
        {
            if (index < 0)
            {
                throw ParametruInAfaraIntervalului();
            }

            _count = index + 1;
            CalculeazaValori(index);

            return _elemente[index];
        }

        Sir& Sir::operator () (int index)
        {
            operator [] (index);
            return *this;
        }

        ostream& operator << (ostream &out, const Sir &sir)
        {
            out << "Index\t" << "Valoare" << endl
                << "----------------------" << endl;
            for (Uint i = 0; i < sir._count; ++i)
            {
                out << i << "\t" << sir._elemente[i] << endl;
            }

            return out;
        }

        /////////////////////////////////////
        // Definire metode clasa Fibonacci //
        /////////////////////////////////////

        void Fibonacci::CalculeazaValori(int index)
        {
            if (index > MAX)
            {
                throw ParametruInAfaraIntervalului();
            }

            if (_elemente.size() == 0) {
                _elemente.push_back(0);
                _elemente.push_back(1);
            }

            for (Uint i = _elemente.size(); i < _count; i++)
            {
                _elemente.push_back(_elemente[i - 2] + _elemente[i - 1]);
            }
        }

        /////////////////////////////////////
        // Definire metode clasa Lucas     //
        /////////////////////////////////////

        void Lucas::CalculeazaValori(int index)
        {
            if (index > MAX)
            {
                throw ParametruInAfaraIntervalului();
            }

            if (_elemente.size() == 0) {
                _elemente.push_back(2);
                _elemente.push_back(1);
            }

            for (Uint i = _elemente.size(); i < _count; i++)
            {
                _elemente.push_back(_elemente[i - 2] + _elemente[i - 1]);
            }
        }

        /////////////////////////////////////
        // Definire metode clasa Pell      //
        /////////////////////////////////////

        void Pell::CalculeazaValori(int index)
        {
            if (index > MAX)
            {
                throw ParametruInAfaraIntervalului();
            }

            if (_elemente.size() == 0) {
                _elemente.push_back(0);
                _elemente.push_back(1);
            }

            for (Uint i = _elemente.size(); i < _count; i++)
            {
                _elemente.push_back(_elemente[i - 2] + 2 * _elemente[i - 1]);
            }
        }

        ///////////////////////////////////////
        // Definire metode clasa Triangular  //
        ///////////////////////////////////////

        void Triangular::CalculeazaValori(int index)
        {
            if (index > MAX)
            {
                throw ParametruInAfaraIntervalului();
            }

            for (Uint i = _elemente.size(); i < _count; i++)
            {
                _elemente.push_back(i * (i + 1) / 2);
            }
        }

        ///////////////////////////////////////
        // Definire metode clasa Pentagonal  //
        ///////////////////////////////////////

        void Pentagonal::CalculeazaValori(int index)
        {
            if (index > MAX)
            {
                throw ParametruInAfaraIntervalului();
            }

            for (Uint i = _elemente.size(); i < _count; i++)
            {
                _elemente.push_back(i * (3 * i - 1) / 2);
            }
        }

        ///////////////////////////////////////
        // Definire metode clasa Prime       //
        ///////////////////////////////////////

        class TestPrim;

        void Prime::CalculeazaValori(int index)
        {
            if (index > MAX)
            {
                throw ParametruInAfaraIntervalului();
            }

            if (_elemente.size() == 0) {
                _elemente.push_back(2);
                _elemente.push_back(3);
            }

            TestPrim testPrim(_elemente.back() + 2);
            TIterator it;
            for (Uint i = _elemente.size(); i < _count; ++testPrim)
            {
                it = find_if(_elemente.begin(), _elemente.end(), testPrim);
                if (*it > testPrim) {
                    _elemente.push_back(testPrim);
                    ++i;
                }
            }
        }

        TestPrim::TestPrim(Uint val) :
            _val(val),
            _stopVal(sqrt((double)val))
        {
        }

        TestPrim& TestPrim::operator ++ ()
        {
            _val += 2;
            _stopVal = sqrt((double)_val);

            return *this;
        }

        bool TestPrim::operator () (Uint divizor)
        {
            return (divizor > _stopVal) || (0 == _val % divizor);
        }

        TestPrim::operator Uint ()
        {
            return _val;
        }

        bool operator > (Uint val, const TestPrim &src)
        {
            return val > src._stopVal;
        }
    }
}

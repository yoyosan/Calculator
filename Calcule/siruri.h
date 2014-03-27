#ifndef SIRURI_H_INCLUDED
#define SIRURI_H_INCLUDED

#include <vector>
#include <iostream>

using namespace std;

namespace Calculator
{
    namespace Calcule
    {
        typedef unsigned int Uint;
        typedef vector<Uint> TVint;
        typedef vector<Uint>::const_iterator TIterator;

        class Sir
        {
        protected:
            Uint _count;
            TVint _elemente;

            virtual void CalculeazaValori(int index) = 0;
        public:
            Sir();
            virtual ~Sir();

            Uint operator [] (int index);
            Sir& operator () (int index);

            friend ostream& operator << (ostream &out, const Sir &sir);
        };

        class Fibonacci : public Sir
        {
        protected:
            void CalculeazaValori(int index);
        public:
            enum { MAX = 47 };
        };

        // TODO: Refactor the classes below since they're almost the same
        class Lucas : public Sir
        {
        protected:
            void CalculeazaValori(int index);
        public:
            enum { MAX = 46 };
        };

        class Pell : public Sir
        {
        protected:
            void CalculeazaValori(int index);
        public:
            enum { MAX = 26 };
        };

        class Triangular : public Sir
        {
        protected:
            void CalculeazaValori(int index);
        public:
            enum { MAX = 1024 };
        };

        class Pentagonal : public Sir
        {
        protected:
            void CalculeazaValori(int index);
        public:
            enum { MAX = 1024 };
        };

        class Prime : public Sir
        {
        protected:
            void CalculeazaValori(int index);
        public:
            enum { MAX = 1024 };
        };

        class TestPrim
        {
            Uint _val;
            double _stopVal;

        public:
            TestPrim(Uint val);
            TestPrim& operator ++ ();
            bool operator () (Uint divizor);
            operator Uint ();
            friend bool operator > (Uint val, const TestPrim &src);
        };
    }
}

#endif // SIRURI_H_INCLUDED

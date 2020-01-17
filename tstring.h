#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>

#include "operatory.h"

using namespace std;

class TString {
    public:
        char* begin() { return ptr; }
        char* end() { return ptr+len; }
        size_t length() const { return len; } // hmm...
        void clear() { delete [] ptr; ptr = nullptr; len = 0; }
        bool empty() const { return len ? false : true; }
        char& front() { return *ptr; }
        
        const char& front() const { return *ptr; }
        char& back() { return *(ptr+len-1); }
        const char& back() const { return *(ptr+len-1); }

        TString& operator= ( TString&& s );
        TString( TString&& s );
        TString& operator= (const TString& s );
        TString( const char* s=nullptr );
        TString( const TString& s);
        ~TString();

        char& operator[]( size_t n ); 
        const char& operator[]( size_t n ) const;

        TString& operator= (const TString& s);
        TString& operator= (TString&& s);
        friend std::ostream& MojeOperatory::operator<<( std::ostream& strumien, const TString& s );
        friend std::istream& MojeOperatory::operator>>( std::istream& strumien, TString& s );
        char* c_str() { return ptr; }
        const char* c_str() const { return ptr; }
        void push_back( char c ) { insert( len, c ); }
        void push_back( const char* c ) { insert( len, c ); }
        

        size_t size() const { return len; }
        char* insert(size_t pos, const char* c);
        char* insert(size_t pos, char c);
        char* erase( size_t bpos = 0, size_t blen = 0 );

        static size_t getN() { return count; }

    private:
        char* ptr = nullptr;
        std::size_t len = 0;
        static size_t count;
    protected:

};
#endif
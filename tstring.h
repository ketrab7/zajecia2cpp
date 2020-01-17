#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>


class TString {
    public:
        TString& operator= ( TString&& s );
        TString( TString&& s );
        TString& operator= (const TString& s );
        TString( const char* s=nullptr );
        TString( const TString& s);
        ~TString();
        char& operator[]( size_t n ); 
        const char& operator[]( size_t n ) const;

    private:
        char* ptr = nullptr;
        std::size_t len = 0;
    protected:

};
#endif
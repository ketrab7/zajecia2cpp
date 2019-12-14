#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>

class TString {
    public:
        TString( TString&& s );
        TString& operator= (const TString& s );
        TString( const char* s=nullptr );
        TString( const TString& s);
        ~TString();
    private:
        char* ptr = nullptr;
        std::size_t len = 0;
    protected:

};
#endif
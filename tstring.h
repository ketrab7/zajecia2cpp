#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>

class TString {
    public:
        TString( const char* s=nullptr );
    private:
        char* ptr = nullptr;
        std::size_t len = 0;
    protected:

};
#endif
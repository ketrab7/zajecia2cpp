#include "tstring.h"
#include <iostream>

using namespace std;

TString::TString(const char* s) : ptr (nullptr), len(0) {
    if (s>0){
        len = strlen (s);
        ptr = new char[ len + 1];
        strcpy (ptr, s);
    }
    #ifdef DEBUG
        cout<<"TString c-tor"<<len<<" - " << (ptr ? ptr : "pusty") <<endl;
    #endif
}
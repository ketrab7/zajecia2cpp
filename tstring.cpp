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
 TString::~TString(){
        #ifdef DEBUG
        cout<<"TString d-tor" <<len<<"-" << (ptr ? ptr : "pusty") <<endl;
        #endif

        delete [] ptr;
    }
TString::TString( const TString& s ) : ptr(nullptr), len(s.len){
    if(len>0){
        ptr = new char [len +1];
        strcpy( ptr, s.ptr);
    }
    #ifdef DEBUG
    cout<<"TString cc-tor" <<len<<"-"<<(ptr ? ptr : "pusty")<<endl;
    #endif

}
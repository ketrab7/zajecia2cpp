#include "tstring.h"
#include <iostream>
#include <stdexcept>

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
TString& TString::operator= (const TString& s ) {
    if ( this != &s ) 
    {
        delete [] ptr; ptr = nullptr; len = s.len;
        if ( len > 0 ) {
            ptr = new char[ len + 1 ];
            strcpy( ptr, s.ptr );
       }
    }
#ifdef DEBUG
    cout << "TString copy operator= " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
#endif
return *this; 
}
TString::TString( TString&& s ) : ptr(s.ptr), len(s.len) {
    s.ptr = nullptr;
    s.len = 0;

    #ifdef DEBUG
        cout << "TString mvc-tor " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
    #endif
}
TString& TString::operator= ( TString&& s ) {
   if ( this != &s ) {
        delete [] ptr; 
        len = s.len; 
        ptr = s.ptr; 
        s.len = 0; 
        s.ptr = nullptr; 
    }
    #ifdef DEBUG
        cout << "TString move operator= " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
    #endif
    return *this;
} 

char& TString::operator[]( size_t n ) {
    if ( !ptr ) throw invalid_argument("pusty obiekt"); 
    if ( n >= 0 && n < len ) return ptr[ n ];
    throw out_of_range("In TString::operator[] argument out of scope");
}
const char& TString::operator[]( size_t n ) const {
    if ( !ptr ) throw invalid_argument("pusty obiekt"); 
    if ( n >= 0 && n < len ) return ptr[ n ];
    throw out_of_range("In TString::operator[] argument out of scope");
}
char* TString::insert(size_t pos, const char* c) {
    if (pos >=0 && pos <= len) {
        size_t oldlen = len;
        len = len+strlen(c);
        char* tmp = new char[ len+1 ];
        strcpy( tmp, ptr );
        for (size_t i=pos; i<pos+strlen(c); ++i) {
            tmp[i] = c[i-pos];
        }
        for (size_t i=pos; i<oldlen; ++i) {
            tmp[i+strlen(c)] = ptr[i];
        }
        delete [] ptr;
        ptr = tmp;
        return ptr+pos;
    } else {
        throw out_of_range("zly argument");
    }
    return ptr;
}
char* TString::insert( size_t pos, char c ) {
    return insert( pos, string( { c } ).c_str() );
}
char* TString::erase( size_t bpos, size_t blen) {
    if (bpos >=0 && blen >= 0 && (bpos + blen) <= len) {
        len = len - blen;
        char* tmp = new char[ len ];
        for (size_t i = 0; i < bpos; ++i) {
            tmp[i] = ptr[i];
        }
        for (size_t i = bpos; i < len; ++i) {
            tmp[i] = ptr[i+blen];
        }
        delete [] ptr;
        ptr = tmp;
    } else {
        throw out_of_range("zly argument");
    }
    return ptr;
}
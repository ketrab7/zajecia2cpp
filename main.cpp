#include <iostream>
#include <random>
#include <string>
#include <ctime>

using namespace std;



int main () {
   string s1 = "wlazl kotek na plotek i mruga";
   for ( auto c: s1) cout <<c<<" ";
   for ( auto& c : s1 ) c = (c=='w') ? 'W' : c;

   for (int i=0; i <s1.length(); ++i) cout<<s1[i]<<" ";
}
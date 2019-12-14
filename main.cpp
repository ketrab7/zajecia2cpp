#include <iostream>
#include <random>
#include <string>
#include <ctime>

using namespace std;



int main () {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<short>dis;
    for(auto n=0;n<10;n++){
        cout<<dis(gen)<<' '<<to_string(dis(gen))<<' ';
        endl(cout);
        
    }
}
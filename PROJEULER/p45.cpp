/**
* project euler
* problem 45
* Triangular, pentagonal, and hexagonal
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_pent(long int x){
    long long int n = (1 + sqrt(24*x + 1)) / 6;
    n = n*(3*n-1)/2;
    // cout<<x<<" "<<n_;
    return x==n;
}

bool is_tri(long int x){

    long int n = sqrt(2*x);
    n = n * (n + 1) / 2;
    return x==n;

}

long int get_hex(long int x){
    return x*(2*x -1);
}        

int main() {

    long int n = 144;
    long int hex = get_hex(n);
    while(!(is_pent(hex) && is_tri(hex))){
        n++;
        hex = get_hex(n);
    }

    cout<<hex<<endl;

    return 0;
}

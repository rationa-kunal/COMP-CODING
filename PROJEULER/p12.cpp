/**
* project euler
* problem 12
* Highly divisible triangular number
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int fact(long int n){
    if(n==1) return 1;

    long int f = 1;
    long int i = 2;
    while(i*i <= n){
        long int f_ = 1;
        while(n%i == 0){
            f_++;
            n/=i;
        }
        i ++;
        f*=f_;
    }
    if(f==1) f=2;
    if(n!=1) f*=2;
    return f;
}

int main() {

    long int i = 0;
    long int d = 1;

    while(fact(i+d)<500){
        i = i+d;
        d++;
    }

    cout<<i+d<<endl;

    return 0;
}

/**
* project euler
* problem 47
* Distinct primes factors
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fact(int n){
    int i = 2;
    int count = 0;
    int _n = n;
    while(i*i <= n){
        
        if(n%i==0) count++;
        while(n%i==0) n/=i;

        i++;

    }

    if(n>1) count++;

    return count;
}

bool check(int n){
    return (fact(n)==4)&&(fact(n+1)==4)&&(fact(n+2)==4)&&(fact(n+3)==4);
}

int main() {

    int i=2;
    while(!check(i)) i++;

    cout<<i<<endl;

    return 0;
}

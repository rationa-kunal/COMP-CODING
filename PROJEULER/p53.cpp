/**
* project euler
* problem 53
* Combinatoric selections
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int fact[101];

void calc(){
    fact[0] = 1;
    for(int i=1; i<101; i++) {
        fact[i] = fact[i-1]*i;
    }
}

long long int ncr(int n, int r){
    // n! / ((n-r)! * r)

    int max, min;
    if(r > (n-r)){
        max = r;
        min = n-r;
    }else{
        max = n-r;
        min = r;
    }

    // upper part
    long long int upper = 1;
    for(int i=max+1; i<n+1; i++) upper*=i;

    long long int down = fact[min];

    // cout<<upper<<" / "<<down<<"-"<<min<<endl;

    return upper/down;
}

int main() {

    calc();

    long long int N = 1000000;
    long int count = 0;

    for(int n=1; n<101; n++){
        for(int r=0; r<=n; r++){

            if(ncr(n,r) >= N) cout<<ncr(n,r)<<endl;

        }
    }

    // cout<<count<<endl;

    // cout<<fact[34]<<endl;

    return 0;
}

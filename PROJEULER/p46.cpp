/**
* project euler
* problem 46
* Goldbach's other conjecture
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N = 1000000;
int primes[1000000];
int limit=0;

void add(int x){
    primes[limit] = x;
    limit ++;
}

bool is_prime(int n){
    if(n<0) return false;
    if(n==1) return false;
    if(n==0) return false;
    if(n==2) return true;
    if(n==3) return true;
    if(n%2==0) return false;
    if(n%3==0) return false;
    int i=5;
    int w=2;
    while(i*i<=n){
        if(n%i==0) return false;
        i+=w;
        w=6-w;
    }
    return true;
}

bool is_2sq(int x){
    if(x%2==0){
        x /= 2;
        int _x = sqrt(x);
        if(x==_x*_x) return true;
    }
    return false;
}

bool is_gold(int x){
    bool flag = false;
    for(int i=0; i<limit; i++){
        if(primes[i] > x) break;

        int _x = x-primes[i];
        if(is_2sq(_x)){
            flag = true;
            break;
        }

    }

    return flag;
}

int next(int x){
    do{
        x += 2;
    }while(is_prime(x));

    return x;
}

int main() {

    int x=2;
    int outer_sum = 0;
    while(x<N){
        if(is_prime(x)){
            add(x);
        }
        x++;
    }

    int i=9;
    while(is_gold(i)){
        i=next(i);
    }

    cout<<i<<endl;

    return 0;
}

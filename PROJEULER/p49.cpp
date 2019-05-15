/**
* project euler
* problem 49
* Permutation prime
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N = 10000;
int primes[10000];
bool flag[10000];
int limit=0;
int digit[10];

void init_digit(){
    for(int i=0; i<10; i++) digit[i]=0;
}

void init_flag(){
    for(int i=0; i<N; i++) flag[i]=false;
}

void add(int x){
    flag[x] = true;
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

bool is_permutaion(int x, int y){
    init_digit();

    while(x!=0){
        digit[x%10] ++;
        x /= 10;
    }

    bool res = true;
    while(y!=0){
        digit[y%10]--;
        if(digit[y%10] == -1) return false;
        y/=10;
    }

    return true;
}

int main() {

    init_flag();

    int x=1000;
    int outer_sum = 0;
    while(x<N){
        if(is_prime(x)){
            add(x);
        }
        x++;
    }

    int a, b, c;
    bool br = false;

    for(int i=68; i<limit; i++){
        a = primes[i];

        for(int j=i+1; j<limit; j++){
            b = primes[j];
            if(is_permutaion(a, b)){
                c = b + (b-a);
                if(c > N) break;
                if(flag[c] && is_permutaion(b, c)){
                    br = true;
                    break;
                }
            }
            // cout<<a<<" "<<b<<endl;
        }

        // cout<<i<<" "<<a<<endl;

        if(br) break;

    }

    cout<<a<<b<<c<<endl;
    return 0;
}

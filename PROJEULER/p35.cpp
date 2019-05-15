/**
* project euler
* problem 35
* Circular primes
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

int rotate(int n, int d){
    int rem = n%10;
    n/=10;
    n+= (rem*((int) pow(10, d-1)));
    // printf("rem-> %d n->%d\n", rem, n);
    return n;
}

int digits(int n){
    int d = 0;
    while(n!=0){
        n/=10;
        d++;
    }
    // cout<<"d "<<d<<endl;
    return d;
}

bool solution(int n){
    bool succ = true;
    int d = digits(n);
    int d_ = d - 1;
    while(d_--){
        n = rotate(n, d);
        // cout<<n<<endl;
        if(!is_prime(n)){
            succ = false;
            break;
        }
    }
    return succ;
}

int main() {

    int count = 0;
    for(int i=0; i<1000000; i++){
        if(is_prime(i)){
            if(solution(i)){
                count++;
            }
        }
    }

    cout<<count<<endl;

    // solution(13);

    return 0;
}

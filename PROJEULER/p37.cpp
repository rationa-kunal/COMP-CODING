/**
* project euler
* problem 37
* Truncatable primess
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

bool check(int num){
    int n = num;
    bool result=true;
    int d =0;
    while(n!=0){
        if(!is_prime(n)) return false;
        n/=10;
        d++;
    }

    d--;

    int pow10 = 1;
    while(d--){
        pow10 *= 10;
    }
    
    while(pow10!=1){
        int n_ = num%pow10;
        if(!is_prime(n_)) return false;
        pow10/=10;
    }

    return result;
}

int main() {

    int counter = 11;
    int i = 10;
    int sum = 0;
    while(counter!=0){
        if(is_prime(i)) if(check(i)) {
            sum += i;
            counter --;
        }
        i++;
    } 

    cout<<sum<<endl;


    return 0;
}

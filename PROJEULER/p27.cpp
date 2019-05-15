/**
* project euler
* problem 27
* Quadratic primes
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

int quad(int a, int b, int x){
    return (x*x) + (x*a) + (b);
}

int solution(int a, int b){
    int i = 0;
    while(is_prime(quad(a, b, i))) i++;
    return i;
}

int main() {

    int maxval = 0;
    int maxx = 0;

    for(int a=-999; a<1000; a++){
        for(int b=-1000; b<=1000; b++){
            int s = solution(a, b);
            if(s > maxval){
                maxval = s;
                maxx = a*b;
            }
        }
    }

    cout<<maxx<<endl;

    return 0;
}

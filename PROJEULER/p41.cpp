/**
* project euler
* problem 41
* Pandigital prime
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
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

int digits(int n){
    return int(log10(n)) + 1;
}

int to_int(char x){
    return int(x) - int('1') + 1;
}

int get_int(string s, int u, int v){
    int n = 0;
    for(int i=u; i<v; i++) n = (n*10) + to_int(s[i]);
    return n;
}

bool check(string pand){
    return is_prime(get_int(pand, 0, pand.length()));    
}

int main() {

    string pand = "1234567";

    string ans = "";

    do {
        if(check(pand)){
            ans = pand;
        }
    } while(next_permutation(pand.begin(), pand.end()));
    
    cout<<ans<<endl;
    
    return 0;
}

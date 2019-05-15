/**
* project euler
* problem 50
* Consecutive prime sum
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

int N = 1000000;
int prime[1000000];
long int sumprime[1000000];
int limit = 0;
int ans=0;
int total=0;

void add(long int x){
    if(total + x >N) return;
    prime[limit] = x;
    limit ++;
    total+=x;
}

int main() {

    int x=2;
    int outer_sum = 0;
    while(x<N){
        if(is_prime(x)){
            add(x); 
            if(total > N) break;
        }
        x++;
    }

    int j = limit;
    while(total > ans && j>0){
        int t = total;
        cout<<t<<endl;
        if(is_prime(t)){
            ans = max(t, ans);
        }
        for(int i=0; i<j; i++){
            t -= prime[i];
            if(is_prime(t)){
                ans = max(t, ans);
            }
        }

        total -= prime[j];
        j--;

    }

    cout<<ans<<endl;

    return 0;
}

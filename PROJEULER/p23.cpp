/**
* project euler
* problem 12
* Non-abundant sums
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_abundant(long int n){
    long int sum = 1;
    long int i =2;
    while(i*i < n){
        if(n%i == 0){
            sum += i + (n/i);
        }
        i++;
    }
    if(i*i == n){
        sum += i;
    }

    return sum>n;
}

int main() {

    long int N = 28123;
    long int abundant[N];
    long int limit = 0;

    bool flag[N];
    for(long int i=0; i<N; i++) flag[N]=false;

    for(long int i=10; i<N; i++){
        if(is_abundant(i)){
            abundant[limit] = i;
            limit ++;
        }
    }

    long int sum = 0;
    for(long int i=0; i<limit; i++){
        for(long int j=i; j<limit; j++){
            long int s = (abundant[i] + abundant[j]);
            if(s-1 < N) flag[s-1] = true;
        }
    }

    for(long int i=0; i<N; i++){
        if(!flag[i]) sum += i+1;
    }

    cout<<sum<<endl;

    return 0;
}

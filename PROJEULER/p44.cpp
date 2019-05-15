/**
* project euler
* problem 44
* Pentagon numbers
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int N = 100000;
long long int pent[100000];
long int limit = 0;
long int limitn = 0;

bool is_pent(long int x){
    long long int n = (1 + sqrt(24*x + 1)) / 6;
    n = n*(3*n-1)/2;
    // cout<<x<<" "<<n_;
    return x==n;
}

long long int get_pent(long long int x){
    return x*(3*x-1)/2;
}

int main() {

    long long int ans = __INT_MAX__;
    bool found = false;
    for(long int i=1; i<N; i++) {
        pent[i] = get_pent(i);
        // cout<<i<<" "<<pent[i]<<endl;
        if(found){
            if(ans > pent[i]-pent[i-1]){
                break;
            }
        }

        for(long long int j=1; j<i; j++){
            // if(is_pent(pent[i] + pent[j])){
            //     cout<<pent[i]<<" "<<pent[j]<<endl;
            //     break;
            // }
            if( is_pent(pent[i] + pent[j]) && is_pent(pent[i]-pent[j]) ){
                ans = min( pent[i] - pent[j], ans);
                found = true;
                break;
            }
        }

        if(found) break;
    }

    cout<<ans<<endl;

    return 0;
}

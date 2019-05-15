/**
* project euler
* problem 26
* Reciprocal cycles
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n = 1000;
int division[1000];
int limit = 0;

void init(){
    // for(int i=0; i<n; i++) division[i] = 0;
    limit = 0;
}

int solution(int x, int y){

    //printf("x->%d y->%d\n", x, y);
    int rem = x%y;

    if(rem == 0) return 0;

    int div = x/y;
    for(int i=0; i<limit; i++){
        //cout<<i<<" "<<division[i]<<endl;
        if(division[i]==rem) return limit-i;
    }

    division[limit] = rem;
    limit++;

    return solution((x%y)*10, y);
}


int main() {

    int maxval = 0;
    int maxx = 0;

    for(int i=2; i<1000; i++){
        init();
        int ans = solution(10, i);
        if(maxval < ans){
            maxval = ans;
            maxx = i;
        }
    }

    cout<<maxx<<" "<<maxval<<endl;

    return 0;
}

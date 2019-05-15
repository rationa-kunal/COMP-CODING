/**
* project euler
* problem 39
* Integer right triangles
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int solution(long int p){
    long int counter = 0;
    for(long int a=1; a<p; a++){
        for(long int b=a; b<p; b++){
            long int c = p -1*(a+b);
            if((c<a)||(c<b)) break;

            if((c*c)==(a*a + b*b)){
                counter ++;
                // cout<<a<<" "<<b<<" "<<c<<endl;
                break;
            }
        }
    }

    return counter;
}

int main() {

    long int maxval = 0;
    long int maxx = 0;
    for(long int p=120; p<1000; p++){
        long int pp = solution(p);
        if(pp > maxval){
            maxval = pp;
            maxx = p;
        }
    }

    cout<<maxx<<endl;

    return 0;
}

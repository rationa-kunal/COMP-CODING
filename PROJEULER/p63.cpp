/**
* project euler
* problem 63
* Power digit counts
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int digits_in_power(int n, int x){
    return int(x*log10(n))+1;
}

int main() {

    int count = 0;
    int curr = 1;
    for(int p=1; ;p++){
        int d = digits_in_power(curr, p);
        if(d > p) break;
        while(d<=p){
            if(d==p){
                count++;
                cout<<count<<" "<<curr<<" "<<p<<endl;
            }
            curr++;
            d = digits_in_power(curr, p);
        }

        curr =1;
    }

    return 0;
}

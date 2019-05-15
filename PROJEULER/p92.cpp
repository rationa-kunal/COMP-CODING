/**
* project euler
* problem 92
* Square digit chains
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool solution[1000];
bool flag[1000];
int sq[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
int lim = 1000;

int sq_sum(long int n){
    int sum = 0;
    while(n!=0){
        sum += (sq[n%10]);
        n/=10;
    }

    return sum;
}

bool check(int n){
    if(n==89) return true;
    else if(n==1) return false;

    if(flag[n]){
        flag[n] = false;
        solution[n] = check(sq_sum(n));
        return solution[n];
    }else{
        return solution[n];
    }

}

bool outer_check(long int n){
    if(n>lim){
        n = sq_sum(n);
    }

    return check(n);
}

int main() {

    for(int i=0; i<lim; i++){
        flag[i] = true;
    }

    long int count=0;

    for(int i=1; i<10000000; i++){
        if(outer_check(i)) count ++;
    }

    cout<<count<<endl;

    return 0;
}

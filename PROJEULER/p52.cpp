/**
* project euler
* problem 52
* Permuted multiples
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int digit[10];

void init_digit(){
    for(int i=0; i<10; i++) digit[i]=0;
}

bool is_permutaion(int x, int y){
    init_digit();

    while(x!=0){
        digit[x%10] ++;
        x /= 10;
    }

    bool res = true;
    while(y!=0){
        digit[y%10]--;
        if(digit[y%10] == -1) return false;
        y/=10;
    }

    return true;
}

int main() {

    int i=1;
    while(true){
        if(is_permutaion(i, i*2) && is_permutaion(i, i*3) && is_permutaion(i, i*4) && is_permutaion(i, i*5) && is_permutaion(i, i*6)) break;
        i++;
    }

    cout<<i<<endl;

    return 0;
}

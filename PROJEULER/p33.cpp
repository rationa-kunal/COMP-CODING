/**
* project euler
* problem 32
* Pandigital products
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N = 9;

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

int check(string pand){
    int count = 0;

    for(int first_digits=1; first_digits<N; first_digits++){
        int first = get_int(pand, 0, first_digits);
        
        for(int second_digit=1; second_digit<N-first_digits; second_digit++){
            int second = get_int(pand, first_digits, first_digits + second_digit);

            int mult = first * second;
            int mult_digits = digits(mult);

            if(mult_digits == N - (first_digits + second_digit)){
                int third = get_int(pand, first_digits+second_digit, N);
                if(mult == third) count ++;
            }

        }
    }

    return count;
}

int main() {

    string pand = "12346789";

    int ans = 0;

    do {
        // new permutaion for pandigital
        ans += check(pand);
    } while(next_permutation(pand.begin(), pand.end()));
    
    cout<<ans<<endl;
    
    return 0;
}

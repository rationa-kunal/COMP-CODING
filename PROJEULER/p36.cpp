/**
* project euler
* problem 36
* Double-base palindromes
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int rev(long long int n){
    long long int rev = 0;
    long long int num = n;
    while(num!=0){
        rev*=10;
        rev+= (num%10);
        num/=10;
    }
    return rev;
}

bool is_palindrome(long long int n){
    return rev(n)==n;
}

long long int bin(long long int n){
    long long int b=1;
    while(n!=0){
        b*=10;
        b+=(n%2);
        n/=2;
        cout<<b<<endl
    }
    cout<<b<<endl;
    b = rev(b);
    cout<<b<<endl;
    b/=10;
    return b;
}

int main() {

    cout<<bin(999999)<<endl;

    // long long int sum = 0;
    // for(long long int i=0; i<1000000; i++){
    //     if(is_palindrome(i)) if(is_palindrome(bin(i))) {
    //         cout<<i<<" "<<bin(i)<<endl;
    //         sum += i;
    //     }
    //     // cout<<"i "<<i<<endl;
    //     // cout<<bin(i)<<endl<<endll;
    // }

    // cout<<sum<<endl;

    return 0;
}

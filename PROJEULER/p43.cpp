/**
* project euler
* problem 43
* Sub-string divisibility
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int to_int(char x){
    // cout<<x<<" "<<long int(x) - long int('1') + 1<<endl;
    return int(x) - int('1') + 1;
}

long int get_int(string s, long int u, long int v){
    long int n = 0;
    for(long int i=u; i<v; i++){
        n = (n*10) + to_int(s[i]);
        // cout<<n*10<<" "<<s[i]<<endl;
    }
    return n;
}

bool divisibility(string pand, long int u, long int v, long int x){
    long int n = get_int(pand, u, v);
    // cout<<pand<<" "<<u<<" "<<v<<" "<<n<<" "<<x<<endl;
    return  n%x==0;
}

bool check(string pand){
    return divisibility(pand, 1, 4, 2)&&divisibility(pand, 2, 5, 3)&&divisibility(pand, 3, 6, 5)&&divisibility(pand, 4, 7, 7) &&divisibility(pand, 5, 8, 11)&&divisibility(pand, 6, 9, 13)&&divisibility(pand, 7, 10, 17);   
}

int main() {

    string pand = "0123456789";

    long int ans = 0;

    do {
        if(pand[0]=='0') continue;
        if(check(pand)){
            ans += get_int(pand, 0, 10);
        }
    } while(next_permutation(pand.begin(), pand.end()));
    
    cout<<ans<<endl;
    
    return 0;
}

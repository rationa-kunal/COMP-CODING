/**
* project euler
* problem 18
* Maximum path sum I
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {

    long int  n = 15;
    long int a[n][n];

    // file input
    fstream input("/home/kunal/Desktop/REAL-SHIT/PROJ-EULER/input/in15.txt");

    long int x;
    for(long int i=0; i<n; i++){
        for(long int j=0; j<=i; j++){
            input>>x;
            a[i][j] = x;
        }
    }

    for(long int i=1; i<n; i++){
        for(long int j=0; j<=i; j++){
            // cout<<a[i][j]<<"->";
            if(j==0) a[i][j] += a[i-1][j];
            else if(i==j) a[i][j] += a[i-1][j-1];
            else a[i][j] += max(a[i-1][j], a[i-1][j-1]);
            // cout<<a[i][j]<<" ";
        }
        // cout<<"\n";
    }

    long int ans = 0;
    for(long int i=0; i<n; i++){
        ans = max(ans, a[n-1][i]);
        // cout<<ans<<" "<<i<<"\n";
    }

    cout<<ans<<endl;

    return 0;
}

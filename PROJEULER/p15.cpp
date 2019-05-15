/**
* project euler
* problem 15
* Lattice paths
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    long int n=21;

    long int path[n][n];

    for(long int i=0; i<n; i++){
        for(long int j=0; j<=i; j++){

            if(j==0) path[i][j]=1;
            else if(j==i) path[i][j] = 2*path[i][j-1];
            else path[i][j] = path[i-1][j] + path[i][j-1];

        }
    }

    cout<<path[n-1][n-1]<<endl;

    return 0;
}

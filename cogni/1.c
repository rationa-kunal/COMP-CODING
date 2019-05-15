#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, n;
    scanf("%d", &x);
    if(x==0) printf("0");
    else if(x==1) printf("1");
    else if(x==2) printf("2");
    else {
        n = 0;
        while(x%2==0) {
            x/=2;
            n++;
        }
        printf("%d", 2*n);
    }

    return 0;
}

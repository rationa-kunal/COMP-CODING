#include <stdio.h>

double ans;

void solve(long int a[], double p[], long int n, long int i, long int xor, double pval) {
    // printf("[%ld %ld %ld]\n", i, xor, n);
    if(i==n) {
        ans+=pval*xor;
        return;
    }

    if(p[i]==1) {
        xor^=a[i];
        solve(a, p, n, i+1, xor, pval);
        return;
    }

    if(p[i]==0) {
        solve(a, p, n, i+1, xor, pval);
        return;
    }

    solve(a, p, n, i+1, xor, pval*(1-p[i]));
    xor^=a[i];
    solve(a, p, n, i+1, xor, pval*p[i]);

}

int main() {

    int t;
    scanf("%d", &t);

    long int n;
    while(t--) {

        scanf("%ld", &n);

        long int b[n];
        double p[n];
        for(long int i=0; i<n; i++) scanf("%ld", &b[i]);
        for(long int i=0; i<n; i++) scanf("%lf", &p[i]);

        ans=0;
        solve(b, p, n, 0, 0, 1);

        printf("%lf\n", ans);

    }

    return 0;
}
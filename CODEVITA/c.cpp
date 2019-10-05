#include <bits/stdc++.h>

using namespace std;

long int calc(long int n) {
	if(n<2) return 0;
	return (n*(n-1))/2;
}

long double calc_time(long int x, long int y, long double v) {
	return sqrt(x*x + y*y)/v;
}

int main() {

	long int c;
	cin>>c;

	long double t[c];
	long int x, y, v;

	for(long int i=0; i<c; i++) {
		cin>>x;
		cin>>y;
		cin>>v;
		t[i] = calc_time(x, y, v);
	}

	sort(t, t+c);

	long int ans=0;
	long int f=1;
	for(long int i=1; i<c; i++) {
		if(t[i]==0) continue;
		if(t[i]!=t[i-1]) {
			ans += calc(f);
			f=1;
		} else {
			f++;
		}
	}
	ans += calc(f);

	cout<<ans<<endl;

	return 0;
}
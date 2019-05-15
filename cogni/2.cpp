#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int na, nb;
	
	cin>>na;
	int a[na];

	for(int i=0; i<na; i++)cin>>a[i];

	cin>>nb;
	int b[nb];	
	int r[na+nb];
	int ri=0;
	for(int i=0; i<nb; i++)cin>>b[i];

	sort(b, b+nb);
	sort(a, a+na);

	int ai, bi;
	ai=0;
	bi=0;

	while(ai<na && bi<nb) {
		if(a[ai]==b[bi]) {
			ai++;
			bi++;
		} else if(a[ai] < b[bi]) {
			r[ri]=a[ai];
			ai++;
			ri++;
		} else {
			r[ri] = b[bi];
			bi++;
			ri++;
		}
	}

	while(ai<na) {
		r[ri] = a[ai];
		ai++;
		ri++;
	}

	while(bi<nb) {
		r[ri] = b[bi];
		bi++;
		ri++;
	}

	cout<<ri<<"\n";
	for(int i=0; i<ri; i++){
		cout<<r[i]<<" ";
	}

	return 0;
}

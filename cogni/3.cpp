#include <iostream>
#include <algorithm>

using namespace std;

bool check(string s, int i, int j, int k, int l){
	string x[j-i+1];
	for(int ii=j, i_=0; ii<=i; ii++, i_++) x[i_] = s[ii];
	cout<<x<<"\n";
	bool flag=true;
	while(k >= l) {
		if(s[k]!=s[l]) {
			flag=false;
			break;
		}
		k++;
		l--;
	}

	return flag
}

int main() {
	
	string x;
	int i, j, k, l;
	int t;


		
	return 0;
}

// E. Minimum Array

#include <bits/stdc++.h>
using namespace std;

int main() {

        long int n;
        cin>>n;

        long int a[n];
        for(long int i=0; i<n; i++)  cin>>a[i];

        list<long int> b;
        long int x;
        for(long int i=0; i<n; i++) {
                cin>>x;
                b.push_back(x);
        }

        list<long int>::iterator min_itr;
        long int min, md;
        for(long int i=0; i<n; i++) {
                min_itr = b.begin();
                min = (a[i]+ *min_itr)%n;
                for(auto itr=b.begin(); itr!=b.end(); itr++) {
                        md = (a[i]+(*itr))%n;
                        if(md<min) {
                                min_itr = itr;
                                min = md;
                        }
                }
                cout<<min<<" ";
                b.erase(min_itr);
        }

        cout<<endl;

        return 0;
}
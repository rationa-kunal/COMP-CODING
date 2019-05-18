#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 26

int fA[26];
int fB[26];

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		for(int i=0; i<MAX; i++) {
			fA[i]=0;
			fB[i]=0;
		}

		long int n;
		scanf("%ld\n", &n);	
		
		char x;
		for(long int i=0; i<n; i++) {
			// printf("[i %ld]\n", i);
			scanf("%c", &x);
			// printf("[c %c]\n", x);
			fA[x-'a']++;
		}
		scanf("%c", &x);
		for(long int i=0; i<n; i++) {
			scanf("%c", &x);
			fB[x-'a']++;
		}

		long int ans=0;
		for(int i=0; i<MAX; i++) {
			if(fA[i]<fB[i]) ans+=fA[i];
			else ans+=fB[i];
		}

		printf("%ld\n", ans);

	}	
}

#include <iostream>
#include <stdio.h>
#define sc(x) scanf("%d",&(x))
#define scc(x) scanf("%c",&(x))
#define scl(x) scanf("%lld",&(x))

using namespace std;
typedef long long ll;
const long long mod = 1000000007ll;
const int N=100001;

ll dp[10][65];
ll sol[65];


int main(){
	int t;
	sc(t);
	for(int i=0;i<10;i++){
		dp[i][1]=1;
	}
	for(int i=2;i<65;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<=j;k++){
				dp[j][i]+=dp[k][i-1];
			}
		}
	}
	for(int i=1;i<65;i++){
		for(int j=0;j<10;j++){
			sol[i]+=dp[j][i];
		}		
	}
	while(t--){
		int n,t1;
		sc(t1);sc(n);
		printf("%d %lld\n",t1,sol[n]);

	}

	


}
	

	


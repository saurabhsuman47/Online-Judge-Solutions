#include <iostream>
#include <stdio.h>
#define sc(x) scanf("%d",&(x))
#define scc(x) scanf("%c",&(x))
#define scl(x) scanf("%lld",&(x))

using namespace std;
typedef long long ll;
const long long mod = 1000000007ll;
const int N=100001;

int dx[6]={-2,-1,1,2,1,-1};
int dy[6]={0,1,1,0,-1,-1};

ll dp[100][100][15];


int main(){
	int t;
	sc(t);
	dp[50][50][0]=1;
	for(int k=1;k<15;k++){
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				if(dp[i][j][k-1]>0){
					for(int d=0;d<6;d++){
						dp[i-dx[d]][j-dy[d]][k]+=dp[i][j][k-1];
					}
				}
			}
		}
	}
	while(t--){
		ll n;
		scl(n);
		printf("%lld\n",dp[50][50][n]);

	}

	


}
	

	


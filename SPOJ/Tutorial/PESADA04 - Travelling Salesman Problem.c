#include<stdio.h>
#define sc(x) scanf("%d \n",&(x))
#define scc(x) scanf("%c",&(x))
#define scl(x) scanf("%lld",&(x))


typedef long long ll;

const int N=11;
const ll inf=10000000000000000;

ll min(ll a,ll b){
	if(a<b)return a;
	else return b;
}


int main(){
	int t;
	sc(t);
	while(t--){
		ll dp[1<<N][N];
		ll adj[N][N];
		int n;
		sc(n);
		n+=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				scanf("%lld \n",&adj[i][j]);
			}
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		printf("%lld ",adj[i][j]);
		// 	}
		// 	printf("\n");
		// }
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				dp[i][j]=inf;
			}
		}
		dp[1<<0][0]=0;
		for(int mask=0;mask<(1<<n);mask++){
			for(int j=0;j<n;j++){
				if(mask && (1<<j)==0)continue;
				int othermask=mask^(1<<j);
				for(int i=0;i<n;i++){
					if(mask&&(1<<i)==0 || i==j)continue;
					dp[mask][j]=min(dp[mask][j],dp[othermask][i]+adj[i][j]);
				}
			}
		}
		ll max=inf;
		for(int i=1;i<n;i++){
			int lim=1<<n;
			ll t1=dp[lim-1][i]+adj[i][0];
			if(t1<max)max=t1;
			
		}
		printf("%lld \n",max);
	}
		
		

	


}
	

	


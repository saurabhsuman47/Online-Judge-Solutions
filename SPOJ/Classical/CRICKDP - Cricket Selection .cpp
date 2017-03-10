#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld",&(x))
#define scl(x) scanf("%lld",&(x))
#define fori(x) for(ll i=0; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
const ll N=10005;
const ll inf=100000000000000005;
const ll K=505;


ll score[N];
ll cost[N];
ll neg_score[N];
ll ncost[N];
ll dp[N][K];

int main(){
	ll t;
	sc(t);
	while(t--){
		ll n,k,m;
		sc(n);sc(k);sc(m);
		ll total_score=0;
		ll total_neg_score=0;
		fori(n){
			sc(score[i]);
			if(score[i]>=0)total_score+=score[i];
			else total_neg_score+=score[i];
			cost[i]=inf;
		}
		fori(m){
			ll l,r,c;
			sc(l);sc(r);sc(c);
			l-=1;r-=1;
			for(ll j=l;j<=r;j++){
				if(cost[j]>=c)cost[j]=c;
			}
		}
		ll j=0;
		fori(n){
			if(score[i]<0){
				neg_score[j]=-1*score[i];
				ncost[j]=cost[i];
				j++;
			}
		}
		
		for(ll i=0;i<=j;i++)for(ll l=0;l<=k;l++)dp[i][l]=0;
		for(ll i=1;i<=j;i++){
			for(ll l=1;l<=k;l++){
				dp[i][l]=dp[i-1][l];
				ll t1;
				if(l-ncost[i-1]>=0)t1=dp[i-1][l-ncost[i-1]]+neg_score[i-1];
				else t1=0;
				dp[i][l]=max(dp[i][l],t1);
			}
		}
		//for(ll i=0;i<=j;i++){for(ll l=0;l<=k;l++)cout<<dp[i][l]<<" ";cout<<endl;}
		total_score+=dp[j][k];
		total_score+=total_neg_score;
		printf("%lld\n",total_score);
	}
	
	
	
}




 

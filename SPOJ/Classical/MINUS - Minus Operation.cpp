#include <bits/stdc++.h>

using namespace std;

#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define fori(x) for(int i=0; i<=x; i++)
#define forj(x) for(int j=0; j<=x; j++)
#define clear(arr,n); fori(n)arr[i]=0;
#define clear2(arr,n,m); fori(n)forj(m)arr[i][j]=0;
const int M = 10001;
const int K = 5000;



queue<int> myq;

int dp[101][M];
int a[101];
int sign[101];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int t;
	sc(t);
	while(t--){
		int n,m;
		sc(n);sc(m);
		for(int i=1;i<=n;i++)sc(a[i]);
		//fori(n)cout<<a[i]<<" ";cout<<endl;
		clear2(dp,n,M);
		int t1=a[1]+K;
		dp[1][t1]=1;
		t1=a[1]-a[2]+K;
		dp[2][t1]=-1;
		for(int i=2;i<n;i++){
			forj(M){
				if(dp[i][j]!=0){
					dp[i+1][j+a[i+1]]=j;
					dp[i+1][j-a[i+1]]=(-1*j);
				}
			}
		}
		// fori(n){
		// 	for(int j=K-15;j<=K+15;j++){
		// 		cout<<"0"<<j<<" ";
		// 	}
		// 	cout<<endl;
		// 	for(int j=K-15;j<=K+15;j++){
		// 		if(dp[i][j]<0)cout<<dp[i][j]<<" ";
  //               else if(dp[i][j]>0)cout<<"+"<<dp[i][j]<<" ";
		// 		else cout<<"0000"<<" ";
		// 	}
		// 	cout<<endl<<endl;

		// }
		clear(sign,n+1);
		int j=m+K;
		for(int i=n;i>=3;i--){
			sign[i]=dp[i][j]/abs(dp[i][j]);
			j=abs(dp[i][j]);
		}
		sign[1]=1;
		sign[2]=-1;
		//fori(n)cout<<sign[i]<<" ";cout<<endl;
		for(int i=2;i<=n;i++){
			sign[i]*=-1;
		}
		//fori(n)cout<<sign[i]<<" ";cout<<endl;
		int count=0;
		j=0;
		for(int i=1;i<=n;i++){
			if(sign[i]==1){j++;}
			else{
				cout<<j<<endl;
				count++;
			}
		}
		for(int i=0;i<n-1-count;i++){
			cout<<"1"<<endl;
		}
		cout<<endl;


	}



}






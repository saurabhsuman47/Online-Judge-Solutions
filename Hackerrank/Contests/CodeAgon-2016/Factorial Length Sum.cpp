
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll N=1000005;
const ll NN=16;
const int inf=100000000;



#define fori(n) for(ll i=0;i<n;i++)
#define forj(n) for(ll j=0;j<n;j++)
#define fork(n) for(ll k=0;k<n;k++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

ll seive[N];
ll b[NN];
ll c[NN];



////************
int main()
{	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	seive[0]=1;seive[1]=1;
	for(ll i=2;i*i<N;i++){
		if(seive[i]==1)continue;
		for(ll j=2;i*j<N;j++){
			seive[i*j]=1;
		}
	}
	// fori(10){
	// 	cout<<seive[i]<<" ";
	// }
	// cout<<endl;
	ll n;
	scl(n);
	for(ll i=0;i<n;i++){
		scl(b[i]);
		for(ll j=2;j<N;j++){
			if(j>b[i])break;
			if(seive[j]==1)continue;
			ll k=j;
			while(k<=b[i]){
				c[i]+=(b[i]/k);
				k*=j;
			}

		}

	}
	// fori(n){
	// 	cout<<c[i]<<" ";
	// }
	// cout<<endl;
	ll sum=0;
	for(ll i=0;i<(1<<n);i++){
		ll tempsum=0;
		for(ll j=0;j<n;j++){
			if(i&(1<<j)){
				tempsum+=c[j];
				//cout<<c[j]<<" ";
			}
		}
		//cout<<endl;
		if(tempsum%2==0)sum+=tempsum;
	}
	printf("%lld\n",sum);

	
}
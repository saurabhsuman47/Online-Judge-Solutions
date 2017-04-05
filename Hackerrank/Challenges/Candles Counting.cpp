#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=50005;
const ll mod = 1000000007ll;
ll a[N];
ll c[N];
ll dp[1<<7][N];
ll tree[1<<7][4*N];

ll query(int idx,int mask){
	ll sum = 0;
	while (idx > 0){
		sum = (sum + tree[mask][idx])%mod;
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int mask, ll val, int max_val){
	while (idx <= max_val){
		tree[mask][idx] = (tree[mask][idx] + val)%mod;
		idx += (idx & -idx);
	}
}


int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    ll maxx=-1;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&c[i]);
        if(maxx<a[i])maxx=a[i];
    }
  
    for(int i=n-1;i>=0;i--){
        int mask = (1<<(c[i]-1));
        update(a[i], mask, 1, maxx); 
        dp[mask][i] = (dp[mask][i]+1)%mod;
        for(int j=0;j<(1<<k);j++){
            ll t1 = query(maxx, j) - query(a[i], j);
            if(t1==0)continue;
            mask=j|(1<<(c[i]-1));
            update(a[i], mask, t1, maxx); 
            dp[mask][i] = (dp[mask][i]+t1)%mod;
        }
        
    }
    
    int mask=pow(2,k)-1;   
    ll sol=0;
    for(int i=0;i<n;i++){        
        sol=(sol+dp[mask][i])%mod;
    }
    cout<<sol<<endl;
}





















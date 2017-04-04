#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)



////************
int main()
{
	int t;
	sc(t);
	while(t--)
	{
		int n;
		sc(n);
		ll m;
		scl(m);
		ll a[n];
		for(int i=0;i<n;i++)
		{
			scl(a[i]);
			a[i]=a[i]%m;
		}
		ll b[n];
		b[0]=a[0];//b[n+1]=0;
		ll t1=a[0];
		for(int i=1;i<n;i++)
		{
			b[i]=(a[i]+b[i-1])%m;
			if(b[i]>t1){t1=b[i];}
		}
		// ll c[n+2],d[n+2];
		// c[0]=b[0];
		// d[n-1]=b[n-1];
		// for(int i=1;i<n;i++)
		// {
  //           if(c[i-1]>b[i]){c[i]=b[i];}else c[i]=c[i-1];
		// }
		// for(int i=n-2;i>=0;i--)
		// {
		// 	if(d[i+1]<b[i]){d[i]=b[i];}else d[i]=d[i+1];
		// }
        // for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
        // for(int i=0;i<n;i++)cout<<c[i]<<" ";cout<<endl;
        // for(int i=0;i<n;i++)cout<<d[i]<<" ";cout<<endl;
		
		
		for(int i=0;i<n;i++){a[i]=i+1;}
		pair<ll,ll> pairs[ n ];			
		for ( int i = 0; i < n; ++i )
		  pairs[ i ] = make_pair( b[ i ], a[ i ] );
		
		sort( pairs, pairs+n );
		
		for ( int i = 0; i < n; ++i )
		{
		  b[ i ] = pairs[ i ].first;
		  a[ i ] = pairs[ i ].second;
		}
		ll t2=1000000000000000;
		for(int i=0;i<n-1;i++)
		{
			if(b[i]<b[i+1] && a[i]>a[i+1]){if(b[i+1]-b[i]<t2)t2=b[i+1]-b[i];}
		}
		if(t2<m)t2=m-t2;
        else t2=0;
        
		t1=max(t1,t2);
		printf("%lld\n",t1);
	}

	
	


}
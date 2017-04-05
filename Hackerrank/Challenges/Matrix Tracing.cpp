#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
double eps=1e-8;
typedef long long ll;
const ll mod=1000000007ll;
#define sc(x) scanf("%lld",&(x))
ll exp(ll a)
{	ll b=1000000005;ll c=mod;
	ll result=1;
if(a==0)return 0;

else{	while(b!=0)
	{	if(b%2==1)
		{
			result=((result)*a)%c;
			
		}
		b/=2;
		a=(a*a)%c;
	}
	return result;}
}

int main() 
{int t;
scanf("%d",&t);
ll* a=new ll[2000001];
a[0]=1;
a[1]=1;
ll product=1;
for(ll i=2;i<2000001;i++)
{
	product=(product*i)%mod;
	a[i]=product;
}
//cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<endl;;

for(int p=0;p<t;p++)
	{
		ll m,n;
		sc(m);sc(n);
		ll t1=a[m+n-2];//cout<<t1<<endl;
		ll t2=(a[m-1]*a[n-1])%mod;//cout<<t2<<endl;
		
		ll tt=exp(t2);//cout<<"tt "<<tt<<endl;
		tt=(t1*tt)%mod;//cout<<"tt "<<tt<<endl;
		cout<<tt<<endl;
	}
}

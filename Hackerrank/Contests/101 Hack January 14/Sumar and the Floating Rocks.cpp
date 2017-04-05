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
ll gcd ( ll a, ll b )
{
  ll c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main() 
{	
	int t;
	scanf("%d",&t);
	for(int p=0;p<t;p++)
	{
		ll x1,y1,x2,y2;
		cin>>x1;cin>>y1;cin>>x2;cin>>y2;
		ll t1=(x1-x2);
		if(t1<0)t1*=-1;
		ll t2=(y1-y2);
		if(t2<0)t2*=-1;
		if(t1>t2)
		{
			ll t=t2;
			t2=t1;
			t1=t;
		}
		int tt=gcd(t1,t2);
		if(tt>=1)cout<<tt-1<<endl;
		else cout<<"0"<<endl;

	}

}

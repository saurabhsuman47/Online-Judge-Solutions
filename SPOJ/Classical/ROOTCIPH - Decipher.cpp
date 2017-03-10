#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		ll t1=a*a-2*b;
		printf("%lld\n",t1);
	}

}
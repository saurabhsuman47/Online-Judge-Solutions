#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <sstream>
typedef long long ll;
#define scl(x) scanf("%lld",&(x))
ll f(ll a,ll b)
{
	if(a==0)return 0;
	else{
		ll r=1;
		while(b!=0)
		{
			if(b&1) r*=a;r=r%10;
			a=(a*a)%10;
			b/=2;
		}
		return r;
	}
}


int main() 
{	
	int t;
	scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	{	
		string s;
		ll b;
		cin>>s;
		scl(b);
		ll a=s[s.length()-1]-48;
		cout<<f(a,b)<<endl;

	}
	
}
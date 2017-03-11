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
typedef vector<int> vi;
typedef std::vector<long long> vl;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
ll comb(ll a,ll b)
{
	ll t1=a-b;
	if(t1<b)swap(t1,b);
	ll bb=b;
	ll result=1;
	for(ll i=1;i<=bb;i++)
	{
		result=(result*a)/i;
		a--;//b++;
	}
	return result;
}

int main() 
{	
	int t;
	scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	{
		ll m,n;
		scl(m);scl(n);
		ll t1=comb(m-1,n-1);
		cout<<t1<<endl;

	}
	
}
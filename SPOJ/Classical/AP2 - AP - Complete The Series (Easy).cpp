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
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))


int main() 
{	
	int t;
	scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	{
		ll t1,t2,sum;
		cin>>t1;cin>>t2;cin>>sum;
		ll n=(sum*2)/(t1+t2);
		ll d=(t2-t1)/(n-5);
		ll a=t1-2*d;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a+d*i<<" ";
		}
		cout<<endl;


	}
	
}
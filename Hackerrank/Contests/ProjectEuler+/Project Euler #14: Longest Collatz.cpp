#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;



const ll mod=1000000007ll;
double eps=1e-8;

	
#define sc(x) scanf("%lld",&(x))
#define scd(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(ll i=0;i<n;i++)
#define forj(n) for(ll j=0;j<n;j++)

ll a[5000005];

ll k=0;


ll handler(ll i)
{
	//cout<<"handler "<<i<<endl;
	ll count=0;k=0;
	while(true)
	{	
		if(i<=5000000){k=i;return count;}
		else
		{
			if(i%2==0){i/=2;count++;}
			else
			{
				i=3*i+1;count++;
			}
		}
	}
}

void foo(ll i)
{
	if(a[i]>0)return;
	if(a[i]==0)
	{
			if(i%2==0){foo(i/2);a[i]=1+a[i/2];}
			else
				{
				 	if((3*i+1)>5000000)
				 	{
				 		ll t1=handler(3*i+1);
				 		ll t2=k;
				 		foo(t2);
				 		a[i]=1+t1+a[t2];
						
				 	}
				 	else {foo(3*i+1);a[i]=1+a[3*i+1];}
				}
		
	}
}


////************
int main()
{
	//fori(5000005){a[i]=0;}
	a[1]=1;
	for(ll i=2;i<=5000000;i++)
	{
		foo(i);
	}
	ll max=1;ll im=1;
	for(int i=2;i<=5000000;i++)
	{
		if(a[i]>=max){im=i;max=a[i];}
		a[i]=im;
	}
	//fori(20)cout<<a[i]<<" ";cout<<endl;
	int tt;
	scd(tt);
	while(tt--)
	{
		int n;scd(n);
		cout<<a[n]<<endl;
	}

}

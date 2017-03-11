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
const int nn=1000005;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

ll bit1[1000005];
ll bit2[1000005];

ll query_bit1(int i,int n)
{
	ll sum=0;
	while(i>0)
	{
		sum+=bit1[i];
		i-=(i & -i);
	}
	return sum;
}
ll query_bit2(int i,int n)
{
	ll sum=0;
	while(i>0)
	{
		sum+=bit2[i];
		i-=(i & -i);
	}
	return sum;
}
void update_bit1(int i,ll value,int n)
{
	while(i<=n)
	{
		bit1[i]+=value;
		i+=(i & -i);
	}
}
void update_bit2(int i,ll value,int n)
{
	while(i<=n)
	{
		bit2[i]+=value;
		i+=(i & -i);
	}
}
 
////************
int main()
{
	int tt;
	sc(tt);
	while(tt--)
	{
		
		int n;int c;
		sc(n);sc(c);
		fori(n)bit2[i]=0;
		fori(n)bit1[i]=0;
		fori(c)
		{
			int t1;sc(t1);
			if(t1==0)
			{
				int l,r;ll v;
				sc(l);sc(r);scl(v);
				update_bit1(l,v,n);
				update_bit1(r+1,-v,n);
				update_bit2(l,(l-1)*v,n);
				update_bit2(r+1,-r*v,n);
			}
			else
			{
				int l,r;
				sc(l);sc(r);
				ll t2=((l-1)*query_bit1(l-1,n))-query_bit2(l-1,n);
				ll t3=((r)*query_bit1(r,n))-query_bit2(r,n);
				cout<<t3-t2<<endl;
			}
			
		}
	}
}
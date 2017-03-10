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

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)


int a[100005];
int foo(int b,int n,int c)
{	int count=0;
	int temp=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-temp>=b){count++;temp=a[i];}

	}
	if(count>=c-1)return 1;
	else return 0;	
}




int main()
{
	int tt;
	sc(tt);
	while(tt--)
	{
		int n,c;
		sc(n);sc(c);
		fori(100005)a[i]=0;
		fori(n)sc(a[i]);
		sort(a,a+n);
		int sol=0;
		int start=0;int end=1000000002;
		while(start<=end)
		{
			int mid=(start+end)/2;
			//cout<<"mid "<<mid<<endl;
			//cout<<"foo "<<foo(mid,n,c)<<endl;
			if(foo(mid,n,c)==1){sol=mid;start=mid+1;}
			else{end=mid-1;}
			//cout<<"sol "<<sol<<endl;
		}
		cout<<sol<<endl;


	}
}
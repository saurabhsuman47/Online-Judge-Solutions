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
const int nn=1000000;
	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

int a[1000001];
int se[100000];
int c[nn+1];


////************
int main()
{	
	fori(1000001){a[i]=0;}
	fori(100000)se[i]=0;
	a[0]=1;a[1]=1;
	int index=0;
	for(int i=2;i<=1000;i++)
	{	
		if(a[i]==1)continue;
		int k=2;
		for(int k=2;k<=nn/i;k++)
		{
			a[i*k]=1;
		}
	}
	fori(nn+1)
	{
		if(a[i]==0){se[index]=i;index++;}
	}
	/*cout<<index<<endl;
	fori(10)cout<<a[i]<<" ";
	cout<<endl;
	cout<<index<<endl;
	fori(10)cout<<se[i]<<" ";
	cout<<endl;*/


	/*fori(nn+1)
	{	if(a[i]==0){c[i]=i-1;continue;}
		int ind=0;
		int ii=i;
		int it=i;
		int t1=se[ind];
		while(t1*t1<=it)
		{
			if(it%t1==0)
			{

				ii/=t1;ii*=(t1-1);
				while(it%t1==0)it/=t1;
				int t2=it;
				if(a[t2]==0){ii/=t2;ii*=(t2-1);it==1;}
				
			}
			else{ind++;t1=se[ind];}
		}
		c[i]=ii;
	}*/
	//for(int i=0;i<20;i++)cout<<i<<" "<<c[i]<<endl;
	//cout<<c[1000000]<<endl;
	int tt;sc(tt);
	while(tt--)
	{	
		int i;sc(i);
		if(a[i]==0){printf("%d\n",i-1);continue;}
		int ind=0;
		int ii=i;
		int it=i;
		int t1=se[ind];
		while(t1*t1<=it)
		{
			if(it%t1==0)
			{

				ii/=t1;ii*=(t1-1);
				while(it%t1==0)it/=t1;
				int t2=it;
				if(a[t2]==0){ii/=t2;ii*=(t2-1);it==1;}
				
			}
			else{ind++;t1=se[ind];}
		}
		printf("%d\n",ii);
	}
}
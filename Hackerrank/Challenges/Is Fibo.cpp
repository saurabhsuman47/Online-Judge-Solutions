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

int main() 
{
	ll t1=1;
	ll t2=1;
	ll temp;
	int index=1;
	ll a[49];
	a[0]=1;
	while(t2<=10000000000)
	{
		temp=t2;
		t2=t1+t2;
		t1=temp;
		a[index]=t2;index++;
	}
	//cout<<index<<endl;
	int t;
	scanf("%d",&t);
	for(int p=0;p<t;p++)
		{
			ll t;
			sc(t);
			int flag=0;
			for(int i=0;i<=47;i++)
			{
				if(t==a[i])
					{flag=1;}
			}
			if(flag==0)cout<<"IsNotFibo"<<endl;
			else cout<<"IsFibo"<<endl;
		}
		
}

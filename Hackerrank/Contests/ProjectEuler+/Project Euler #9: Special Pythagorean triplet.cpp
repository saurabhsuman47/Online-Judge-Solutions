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
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

struct jam{
	int a;
	int b;
	int c;
	int sum;
	ll product;
};
jam arr[1000000];

bool structsorter(jam const& lhs,jam const& rhs)
{
	if(lhs.sum!=rhs.sum)return lhs.sum<rhs.sum;
	else
		return lhs.product>rhs.product;
};


////************
int main()
{
	int index=0;
	for(int i=1;i<1500;i++)
	{
		for(int j=1;j<1500;j++)
		{
			int t1=i*i+j*j;
			double t2=t1*1.0;
			t2=sqrt(t2);
			int t3=int(t2);
			if(t1==t3*t3)
			{	
				arr[index].a=i;
				arr[index].b=j;
				arr[index].c=t3;
				arr[index].sum=i+j+t3;
				arr[index].product=(ll)i*(ll)j*(ll)t3;
				index++;
			}

		}
	}
	sort(arr,arr+index,structsorter);
	//cout<<index<<endl;
	int tt;
	sc(tt);
	while(tt--)
	{
		int n;
		sc(n);
		int flag=0;
		fori(index)
		{
			if((arr[i].sum)==n){printf("%lld\n",arr[i].product);flag=1;break;}
		}
		if(flag==0)printf("%s\n","-1");

	}
}

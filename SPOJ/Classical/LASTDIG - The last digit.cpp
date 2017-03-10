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
#define sc(x) scanf("%d",&(x))
int funct(int a,int b)
{	a=a%10;
	int bb=b;
	int result=1;
	if(a==0)return 0;
	else if(b==0)return 1;
	
	else
	{
		while(bb!=0)
		{
			if(bb%2==1)
			{
				result=(result*a)%10;
			}
			bb/=2;
			a=(a*a)%10;
		}
		return result;
	}

}

int main() 
{
	int t;
scanf("%d",&t);
for(int p=0;p<t;p++)
	{int a,b;
	cin>>a;cin>>b;
	cout<<funct(a,b)<<endl;
	}

}
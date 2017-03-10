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

int main() 
{int t;
scanf("%d",&t);
for(int p=0;p<t;p++)
	{
		int x,y;
		sc(x);sc(y);
		if(x==y || (x-y)==2)
		{
			if(x%2==0)
			{
				cout<<x+y<<endl;
			}
			if(x%2==1)
			{
				cout<<x+y-1<<endl;
			}
		}
		else cout<<"No Number"<<endl;

	}
}
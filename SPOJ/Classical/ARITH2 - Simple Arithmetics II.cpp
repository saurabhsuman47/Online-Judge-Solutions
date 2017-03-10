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
		ll t1;
		scl(t1);
		char c1;
		cin>>c1;
		ll sol=t1;
		while(c1!='=')
		{
			scl(t1);
			if(c1=='+'){sol+=t1;}
			if(c1=='-'){sol-=t1;}
			if(c1=='*'){sol*=t1;}
			if(c1=='/'){sol/=t1;}
			cin>>c1;

		}
		cout<<sol<<endl;
	}

}
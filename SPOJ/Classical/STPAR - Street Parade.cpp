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
typedef std::vector<long long> vl;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))


int main() 
{	
	while(1)
	{	
		int n;
		scanf("%d",&n);
		if(n==0)break;
		stack<int> s;
		int index=1;
		for(int pp=0;pp<n;pp++)
		{
			int t;
			sc(t);
			if(t==index)
			{index++;
				while(1 && !s.empty())
				{
					int t11=s.top();
					if(t11==index){index++;s.pop();}
					else break;
				}
			}
			else s.push(t);
		}
		int flag=0;
		while(!s.empty())
		{int t1=s.top();
			if(t1==index){index++;s.pop();}
			else {flag=1;break;}
		}
		if(flag==1)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
		
	}

	
}
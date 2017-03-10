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
	{	int a[8]={0};
		int t1;sc(t1);
		string s;
		cin>>s;
		for(int i=0;i<=37;i++)
		{
			if(s[i]=='T' && s[i+1]=='T' && s[i+2]=='T')a[0]+=1;
			if(s[i]=='T' && s[i+1]=='T' && s[i+2]=='H')a[1]+=1;
			if(s[i]=='T' && s[i+1]=='H' && s[i+2]=='T')a[2]+=1;
			if(s[i]=='T' && s[i+1]=='H' && s[i+2]=='H')a[3]+=1;
			if(s[i]=='H' && s[i+1]=='T' && s[i+2]=='T')a[4]+=1;
			if(s[i]=='H' && s[i+1]=='T' && s[i+2]=='H')a[5]+=1;
			if(s[i]=='H' && s[i+1]=='H' && s[i+2]=='T')a[6]+=1;
			if(s[i]=='H' && s[i+1]=='H' && s[i+2]=='H')a[7]+=1;

		}
		cout<<t1<<" ";
		for(int i=0;i<=7;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;

	}
	
}
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <list>

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;

double eps=1e-8;
const ll mod=1000000007ll;

#define sc(x) scanf("%c",&(x))
#define scl(x) scanf("%lld",&(x))


int main() 
{	
	int t;
	scanf("%d",&t);
	char a[t][t];
	for(int pp=0;pp<t;pp++)
	{	char cc;
		sc(cc);
		for(int i=0;i<t;i++)
		{
			sc(a[pp][i]);
		}

	}
	
	for(int i=1;i<t-1;i++)
	{
		for(int j=1;j<t-1;j++)
		{
			if(a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1] && a[i][j]>a[i-1][j]  && a[i][j]>a[i+1][j] )
			{a[i][j]='b';}
		}
	}
	//if(a[1][1]>a[1][0])cout<<"yes"<<endl;
	for(int pp=0;pp<t;pp++)
	{
		for(int i=0;i<t;i++)
		{
			if(a[pp][i]=='b')printf("%c",'X');
			else printf("%c", a[pp][i]);
		}
		printf("\n");

	}
	
}

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
#define scc(x) scanf("%c",&(x))
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

char p[1000000];
void fun(int lps[])
{
	lps[0]=-1;
	int n=strlen(p);
	int k=-1;
	for(int i=1;i<=n-1;i++)
	{
		while(k>=0 && p[i]!=p[k+1])
			k=lps[k];
		if(p[i]==p[k+1])
			k++;
		lps[i]=k;
	}
}


////************
int main()
{
	int tt;
	while(cin>>tt)	
	{	scanf("%s",p);
		int len=strlen(p);
		//cout<<len<<endl;
		int lps[len];
		fun(lps);
		//fori(len)cout<<lps[i]<<" | ";
		char cc;
		scc(cc);
		scc(cc);
		//scc(cc);
		//cout<<endl;
		int k=-1;
		int count=0;
		while(cc!='\n')
		{
			while(k>=0 && p[k+1]!=cc)
				k=lps[k];
			if(p[k+1]==cc)
				k++;
			if (k==len-1)
				printf("%d\n",count-len+1);
			scc(cc);count++;
		}
		printf("\n");
	}


}
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
{	
	int k,l,m;
	scanf("%d",&k);sc(l);sc(m);
	int a[m];
	int b[1000001]={0};//0 losing position
	for(int i=1;i<=1000000;i++)
	{
		if((b[i-1]==0) || (b[i-k]==0 && i-k>=0) || (b[i-l]==0 && i-l>=0)) b[i]=1;
		else b[i]=0;
	}
	//for(int i=0;i<17;i++)
	//cout<<b[i]<<" ";
	//cout<<endl;
	for(int p=0;p<m;p++)
	{
		scanf("%d",&a[p]);
		if(b[a[p]]==1)cout<<"A";
		else cout<<"B";
	}

}
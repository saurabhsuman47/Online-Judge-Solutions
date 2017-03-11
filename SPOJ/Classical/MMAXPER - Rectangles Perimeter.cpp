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

int main() 
{int t;
scanf("%d",&t);
int a[t];int b[t];
for(int p=0;p<t;p++)
	{
		scanf("%d",&a[p]);
		scanf("%d",&b[p]);
	}
	int sol1=a[0];//
	int sol2=b[0];
	for(int i=1;i<t;i++)
	{
		int t1=sol1;
		int t2=sol2;
		sol1=max((t1+abs(b[i]-b[i-1])+a[i]),(t2+abs(b[i]-a[i-1])+a[i]));
		sol2=max((t1+abs(a[i]-b[i-1])+b[i]),(t2+abs(a[i]-a[i-1])+b[i]));
	}
	cout<<max(sol1,sol2)<<endl;



}
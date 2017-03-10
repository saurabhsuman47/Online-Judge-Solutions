#include <bits/stdc++.h>

using namespace std;
int a[31];
int main()
{
	a[0]=1;
	a[2]=3;
	for(int i=4;i<=30;i+=2)
	{
		a[i]=2;
		a[i]+=a[i-2]*3;
		int j=i-4;
		while(j>0)
		{
			a[i]+=a[j]*2;
			j-=2;
		}
	}
	
	int x;
	while(cin>>x)
	{
		if(x==-1)break;
		printf("%d\n",a[x]);

	}
}

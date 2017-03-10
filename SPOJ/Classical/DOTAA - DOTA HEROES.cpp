#include <iostream>
#include <stdio.h>

using namespace std;
#define sc(x) scanf("%d",&x)

int main()
{
	int pp;
	sc(pp);
	while(pp--)
	{
		int n,m,dam;
		sc(n);sc(m);sc(dam);
		int health[n];
		for(int i=0;i<n;i++)
		{
			sc(health[i]);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			int t1=(health[i]-1)/dam;
			count+=(t1);
		}
		if(count>=m)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

}
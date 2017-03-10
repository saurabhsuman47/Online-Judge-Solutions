#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x));

int main()
{	int pp;sc(pp);
	while(pp--)	
	{
		int n,k;
		sc(n);sc(k);
		//cout<<n<<" "<<k<<endl;
		int a[n];
		for(int i=0;i<n;i++)
		{
			sc(a[i]);
		}
		sort(a,a+n);
		int min=1000000500;
		for(int i=0;i<=n-k;i++)
		{
			int t1=a[i+k-1]-a[i];
			if(t1<min)min=t1;
		}
		printf("%d\n",min);
	}

}

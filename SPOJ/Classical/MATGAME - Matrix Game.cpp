#include <iostream>
using namespace std;
#include <cstdio>


double eps=1e-8;
typedef long long ll;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))

int a[51][51];

int main() 
{	//freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int p=0;p<t;p++){
		int n,m;
		sc(n);sc(m);
        
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
        int ans=0;
        for(int i=0;i<n;i++){
            int grundy=a[i][m-1];
            for(int j=m-2;j>=0;j--){
                if(a[i][j]>grundy){
                    grundy=a[i][j];
                }
                else{
                    grundy=a[i][j]-1;
                }
            }
            ans=ans^grundy;            
        }
       if (ans==0){
           printf("%s\n","SECOND");
       }
       else{
            printf("%s\n","FIRST");            
       }

            
	}
 
} 
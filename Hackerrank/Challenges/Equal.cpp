#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10005];
int dp[1000005];

int main() {
    dp[0]=0;dp[1]=1;dp[2]=1;dp[3]=2;dp[4]=2;
    for(int i=5;i<1000005;i++){
        dp[i]=1+min(min(dp[i-1],dp[i-2]),dp[i-5]);
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int inc=0;
        int ans=100000000;
       
        for(int j=0;j<5;j++ ){
            int temp = a[0]-j;
            int sol=0;
            for(int i=0;i<n;i++){
                int t1=a[i]-temp;
                sol+=dp[t1];                
            }
            ans=min(sol,ans);
        }
        
        cout<<ans<<endl;
            
    }
    return 0;
}


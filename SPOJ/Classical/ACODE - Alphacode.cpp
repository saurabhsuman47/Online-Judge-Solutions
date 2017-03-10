#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    string s;
    ll dp[5005];
    while(true){
        cin>>s;
        if(s.length()==1){
            if(s[0]=='0')break;
        }
        for(int i=0;i<=5005;i++){
            dp[i]=0;
        }
        dp[1]=1;dp[0]=1;
        for(int i=1;i<=s.length();i++){
            if(s[i]!='0')dp[i+1]=dp[i];
            ll t1=s[i]-'0';
            ll t2=s[i-1]-'0';
            ll t3=t2*10;
            t3+=t1;
            if(t3<=26 && t2>0){
                dp[i+1]+=dp[i-1];
            }
            
        }
//        for(int i=0;i<=s.length();i++){
//            cout<<dp[i]<<" ";
//        }
//        cout<<endl;
        cout<<dp[s.length()]<<endl;
    }
    return 0;
}

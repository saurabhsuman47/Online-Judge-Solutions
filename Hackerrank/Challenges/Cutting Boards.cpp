#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define sc(x) scanf("%d", &x)

long long mod = 1000000007;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t--){
        int m,n;
        sc(m);sc(n);
        m--; n--;
        int a[m];
        int b[n];
        for(int i = 0; i < m; i++){
            sc(a[i]);
        }
        for(int i = 0; i < n; i++){
            sc(b[i]);
        }
        sort(a, a + m, greater<int>());
        sort(b, b + n, greater<int>());
        int counta = 1, countb = 1;
        int ia = 0, ib = 0;
        long long result = 0;
        while(ia < m && ib < n){
            if(a[ia] > b[ib]){
                long long temp = ((long long)a[ia] * (long long)countb);
                temp = temp % mod;
                result = (result + temp) % mod;
                counta++;
                ia++;
            }
            else{
                long long temp =  ((long long)b[ib] * (long long)counta);
                temp = temp % mod;
                result = (result + temp) % mod;
                countb++;
                ib++;
            }
        }
        while(ia < m){
            long long temp = ((long long)a[ia] * (long long)countb);
            temp = temp % mod;
            result = (result + temp) % mod;
            ia++;
        }
        while(ib < n){
            long long temp =  ((long long)b[ib] * (long long)counta);
            temp = temp % mod;
            result = (result + temp) % mod;
            ib++;
        }
        cout<<result<<endl;
    }
    return 0;
}


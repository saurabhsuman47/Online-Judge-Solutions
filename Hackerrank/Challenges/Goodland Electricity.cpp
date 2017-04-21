#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, k;
    cin>>n>>k;
    for(int z = 1; z <= n; z++){
        cin>>a[z];
    }
    
    int count = 0;
    int idx = 1;
    int flag;
    while(idx <= n){
        flag = 0;
        for(int i = min(n, (idx + k -1)); i >= idx; i--){
            if(a[i] == 1){
                count++;
                flag = 1;
                idx = i + k;
                break;
                
            }
        }
        if(flag == 0){
            for(int i = max(1, (idx - 1)); i >= max(0, idx - k + 1); i--){
            if(a[i] == 1){
                count++;
                flag = 1;
                idx = i + k;
                break;
                
            }
        }
        }
        if(flag == 0){
            break;
        }
    }
    if(flag == 1)cout<<count<<endl;
    else cout<<"-1"<<endl;
    return 0;
}


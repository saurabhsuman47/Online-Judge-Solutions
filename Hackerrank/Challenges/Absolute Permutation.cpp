#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        int a[n];
        if(k ==0){
            for(int i=0;i<n;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
        else if(n % (2*k) == 0){
            for(int i = 0;i< n/k; i++){
                for(int kk = 0; kk < k; kk++){
                    if(i % 2 == 0){
                        a[i*k + kk] = (i*k + kk) + k + 1;
                    }
                    else a[i*k + kk] = (i*k + kk) - k + 1;
                }
            }
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}


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
typedef long long ll;

ll foo(ll n){
    ll t2=n-n%4;
    ll result=0;
    for(ll i=t2;i<=n;i++){
        result^=i;
    }
    return result;
}

ll calculate(ll n){
    ll nn=n/2;
    ll result=foo(nn);
    result*=2;
    if(n%2==1){        
        if(nn%2==0){
            result++;
        }
    }
    return result;
}


int main(){
   
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        ll L;
        ll R;
        cin >> L >> R;        
        ll t1 = (calculate(R))^(calculate(L-1));
        cout<<t1<<endl;
        
    }
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    sort(list, list + N);
    for(int i = 0; i < N + 1 - K; i++){
        unfairness = min(unfairness, (list[i + K -1] - list[i]));
    }
    cout << unfairness << "\n";
    return 0;
}


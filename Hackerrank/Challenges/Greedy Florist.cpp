/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){

 

//Helpers for input and output

    int N, K;
    cin >> N >> K;
    int C[N];
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }

    sort(C, C+N);
    int kk = 0;
    int x = 1;
    int result = 0;
    for(int i = N-1; i>= 0; i--){
        kk++;
        result += (x * C[i]);
        if(kk == K){
            x++;
            kk = 0;
        }
        
    }

    
    cout << result << "\n";

    return 0;
}


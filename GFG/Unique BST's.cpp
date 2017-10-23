#include <iostream>
using namespace std;

int number_unique_bst[15];

void solve(){
    number_unique_bst[0] = 1;
    number_unique_bst[1] = 1;
    for(int i = 2; i < 15; i++){
        number_unique_bst[i] = 0;
        for(int j = 0; j <= i - 1; j++){
            number_unique_bst[i] += number_unique_bst[j] * number_unique_bst[i - j - 1];
        }
    }
}

int main() {
	//code
	solve();
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<number_unique_bst[n]<<endl;
	}
	return 0;
}

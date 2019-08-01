#include<stack>
#include<unordered_map>
using namespace std;


int main()
 {
	//code
	int t;
	cin>>t;
	unordered_map<char, int> precedence;
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['+'] = 1;
	precedence['-'] = 1;
	precedence['^'] = 3;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    stack<char> mys;
	    for(int i = 0; i < n; i++){
	        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))cout<<s[i];
	        else if(s[i] == '(')mys.push(s[i]);
	        else if(s[i] == ')'){
	            while(mys.top() != '('){
	                cout<<mys.top();
	                mys.pop();
	            }
	            mys.pop();
	        }
	        else{
	            while(!mys.empty() && mys.top() != '('){
	                if(precedence[s[i]] <= precedence[mys.top()]){
	                    cout<<mys.top();
	                    mys.pop();
	                }
	                else{
	                    break;
	                }
	            }
	            mys.push(s[i]);
	        }
        }
        while(!mys.empty()){
            cout<<mys.top();
            mys.pop();
        }
        cout<<endl;
	}
	return 0;
}

#include<string>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    int sol = 1;
	    int soll = 0, solr = 0;
	    //odd
	    for(int mid = 0; mid < n; mid++){
	        int i = mid,j = mid;
	        while(i>=0 && j<n){
	            if(s[i] == s[j]){
	                int tempsol = (j-i+1);
	                if(tempsol>sol){soll = i; solr = j;} 
	                if(tempsol == sol && i < soll){soll = i; solr = j;}
	                sol = max(sol, (j-i+1));
	                j++, i--;
                }
                else break;
	        }
	    }
	    //even
	    for(int mid = 0; mid < n-1; mid++){
	        int i = mid,j = mid + 1;
	        while(i>=0 && j<n){
	            if(s[i] == s[j]){
	                int tempsol = (j-i+1);
	                if(tempsol>sol){soll = i; solr = j;} 
	                if(tempsol == sol && i < soll){soll = i; solr = j;}
	                sol = max(sol, (j-i+1));
	                j++, i--;
                }
                else break;
	        }
	    }
	    for(int i = soll; i <= solr; i++){
	        cout<<s[i];
	    }
	    cout<<endl;
	}
	return 0;
}

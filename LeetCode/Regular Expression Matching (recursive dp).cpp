/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/

class Solution {
public:
    vector<char> vect_pattern;
    vector<int> vect_multiple;
	vector<vector<int>> dp;
    string s;
    bool isMatch(string _s, string p) {
        s = _s; 
        for(int i = 0; i < p.length(); i++){
            if(p[i] == '.' || (p[i] != '.' && p[i] != '*')){
                vect_pattern.push_back(p[i]);
                if(i + 1 != p.length() && p[i+1] == '*'){
                    vect_multiple.push_back(1);
                }
                else vect_multiple.push_back(0);
            }
        }
		
		for(int i = 0; i <= s.length(); i++){
			vector<int> vect_temp;
			for(int j = 0; j < vect_pattern.size(); j++){
				vect_temp.push_back(-1);
			}
			dp.push_back(vect_temp);
		}
		return isMatchHelper(0, 0);
    }
    
    bool isMatchHelper(int sidx, int pidx){
        if(sidx < s.length() && pidx == vect_pattern.size()){
            return false;
        }
        if(sidx == s.length()){
            if(pidx == vect_pattern.size())return true;
            if(vect_multiple[pidx] == 0) return false;
            if(vect_multiple[pidx] == 1){
				if(dp[sidx][pidx] != -1) return dp[sidx][pidx];
				bool sol = isMatchHelper(sidx, pidx + 1);
				dp[sidx][pidx] = sol;
				return dp[sidx][pidx];
			} 
        }
		if(dp[sidx][pidx] != -1) return dp[sidx][pidx];
        bool sol = false;        
        if(vect_pattern[pidx] == '.'){
            if(vect_multiple[pidx] == 0){
				sol = isMatchHelper(sidx + 1, pidx + 1);				
			}
            else{
                sol = isMatchHelper(sidx, pidx + 1);
				int tsidx = sidx;
				while(tsidx < s.length()){
                    sol |= (isMatchHelper(++tsidx, pidx + 1));
                }                
            }
        }
        else{
            if(vect_multiple[pidx] == 0){
                if(s[sidx] == vect_pattern[pidx]){
                    sol = isMatchHelper(sidx + 1, pidx + 1);
                }
                else sol = false;
            }
            else{
                sol = isMatchHelper(sidx, pidx + 1);
				int tsidx = sidx;
                while(s[tsidx] == vect_pattern[pidx]){
                    sol |= (isMatchHelper(++tsidx, pidx + 1));
                }
            }                
        }
		dp[sidx][pidx] = sol;
		return dp[sidx][pidx];
    }
};


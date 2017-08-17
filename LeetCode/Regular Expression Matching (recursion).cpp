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
    vector<char> vp;
    vector<int> vm;
    string ss;
    bool isMatch(string s, string p) {
        ss = s; 
        for(int i = 0; i < p.length(); i++){
            if(p[i] == '.' || (p[i] != '.' && p[i] != '*')){
                vp.push_back(p[i]);
                if(p[i+1] == '*'){
                    vm.push_back(1);
                }
                else vm.push_back(0);
            }
        }
        return isMatchHelper(0, 0);
    }
    
    bool isMatchHelper(int sidx, int pidx){
        if(sidx < ss.length() && pidx == vp.size()){
            return false;
        }
        if(sidx == ss.length()){
            if(pidx == vp.size())return true;
            if(vm[pidx] == 0) return false;
            if(vm[pidx] == 1) return isMatchHelper(sidx, pidx + 1);
        }
                
        if(vp[pidx] == '.'){
            if(vm[pidx] == 0) return isMatchHelper(sidx + 1, pidx + 1);
            else{
                bool sol = isMatchHelper(sidx, pidx + 1);
				while(sidx < ss.length()){
                    sol |= (isMatchHelper(++sidx, pidx + 1));
                }
                return sol;
            }
        }
        else{
            if(vm[pidx] == 0){
                if(ss[sidx] == vp[pidx]){
                    return isMatchHelper(++sidx, ++pidx);
                }
                else return false;
            }
            else{
                bool sol = isMatchHelper(sidx, pidx + 1);
                while(ss[sidx] == vp[pidx]){
                    sol |= (isMatchHelper(++sidx, pidx + 1));
                }
                return sol;
            }
                
        }
    }
};

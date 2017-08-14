class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_char_idx;
        int left = 0;
        int sol = 0;
        for(int i = 0; i < s.length(); i++){
            char c1 = s[i];
            if(hash_char_idx.find(c1) != hash_char_idx.end()){ 
                int idx = hash_char_idx[c1];
                if(idx >= left){
                    left = idx + 1;
                }                
            }
            hash_char_idx[c1] = i;
            if(sol < (i - left + 1)){
                sol = i - left + 1; 
            }
        }
        return sol;
        
        
    }
};

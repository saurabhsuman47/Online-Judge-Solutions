#include <utility>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        vector<pair<int, int>> v_nums_idx;
        pair<int, int> pii;
        for(int i = 0; i < nums.size(); i++){
            pii = make_pair(nums[i], i);
            v_nums_idx.push_back(pii);
        }
        sort(v_nums_idx.begin(), v_nums_idx.end());
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int left = v_nums_idx[i].first;
            int right = v_nums_idx[j].first;
            if(left + right == target){
                sol.push_back(v_nums_idx[i].second);
                sol.push_back(v_nums_idx[j].second);
                return sol;
            }
            if(left + right < target){
                i++;
            }
            else{
                j--;
            }            
        }
        return sol;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> hash_num_idx;
        for(int i = 0; i < nums.size(); i++){
            if(hash_num_idx.find(target - nums[i]) != hash_num_idx.end()){
                sol.push_back(hash_num_idx[target - nums[i]]);
                sol.push_back(i);
                return sol;
            }
            hash_num_idx[nums[i]] = i;
        }
        return sol;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sol = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        while(l < r){
            int area = (r - l)*(min(height[l], height[r]));
            sol = max(sol, area);
            if(height[l] < height[r]){
                l++;
            }
            else r--;
        }
        return sol;
    }
};

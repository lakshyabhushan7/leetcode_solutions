class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = true;
        int max_i = 0;
        for(int i = 0; i < nums.size(); i++){
            if (i > max_i) {
                ans = false;
                break;
            }
            max_i = max(max_i, i + nums[i]);
        }
        if(max_i < nums.size() - 1) ans = false;
        
        return ans;
    }
};
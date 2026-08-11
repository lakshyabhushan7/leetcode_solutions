class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] == nums[i] + 1) {
                cnt++;
            } else {
                break;
            }
        }
        
        int sum = 0;
        for (int i = 0; i <= cnt; i++) {
            sum += nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        while (binary_search(nums.begin(), nums.end(), sum)) {
            sum++;
        }
        
        return sum;
    }
};
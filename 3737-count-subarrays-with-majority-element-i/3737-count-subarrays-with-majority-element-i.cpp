class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j]==target) cnt++;
                else cnt--;
                if(cnt > 0) ans++;
            }
        }
        return ans;
    }
};
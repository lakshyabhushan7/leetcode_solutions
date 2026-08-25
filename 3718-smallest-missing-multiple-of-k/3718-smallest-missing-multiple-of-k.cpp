class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int target = k;
        
        while (true) {
            if (mp.find(target) == mp.end()) {
                return target;
            }
            target += k;
        }
    }
};
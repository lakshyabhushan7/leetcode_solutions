class Solution {
public:
    int digi(int n) {
        int sm = 0;
        while (n > 0) {
            sm += n % 10;
            n /= 10;
        }
        return sm;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<pair<int, int>> p;
        
        for (int i = 0; i < n; i++) {
            p.push_back({digi(nums[i]), nums[i]});
            mp[nums[i]] = i;
        }
        
        sort(p.begin(), p.end());
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; i++) {
            int original_idx = mp[p[i].second];
            if (visited[i] || original_idx == i) continue;
            
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = mp[p[curr].second];
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};
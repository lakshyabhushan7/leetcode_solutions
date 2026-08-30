class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int k = 0;
        int j = 0;
        int n = nums.size();

        if (n == 1 || n == 2) return n;

        for (int i = 0; i < n; i++) {
            if (nums[i] < mn) {
                k = i;
                mn = nums[i];
            }
            if (nums[i] > mx) {
                j = i;
                mx = nums[i];
            }
        }

        int a = max(k, j) + 1;
        int b = n - min(k, j);
        int c = min(k, j) + 1 + n - max(k, j);

        return min({a, b, c});
    }
};
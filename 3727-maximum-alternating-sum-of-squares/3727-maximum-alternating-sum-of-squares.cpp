class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = 1LL * nums[i] * nums[i];
        }

        sort(a.begin(), a.end());

        long long k = n / 2;
        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans -= a[i];
        }

        for (int i = k; i < n; i++) {
            ans += a[i];
        }

        return ans;
    }
};
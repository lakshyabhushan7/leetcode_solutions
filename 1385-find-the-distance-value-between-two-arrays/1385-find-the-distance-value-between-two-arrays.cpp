class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        
        for (int i = 0; i < n; i++) {
            bool correct = true;
            int j = arr2.size() - 1;
            while (j >= 0) {
                if ((max(arr1[i], arr2[j]) - min(arr1[i], arr2[j])) <= d) {
                    correct = false;
                    break;
                }
                j--;
            }
            if (correct)
                ans++;
        }
        return ans;
    }
};
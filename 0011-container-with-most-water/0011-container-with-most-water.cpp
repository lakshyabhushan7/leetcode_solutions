class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int n = height.size();
        int ans = 0;
        int j = n - 1;

        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            ans = max(ans, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};
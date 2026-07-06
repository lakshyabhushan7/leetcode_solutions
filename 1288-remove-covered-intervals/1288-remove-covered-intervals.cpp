class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int n = a.size();
        
        sort(a.begin(), a.end());
        
        int remaining = n;
        int current_start = a[0][0];
        int current_end = a[0][1];
        
        for (int i = 1; i < n; i++) {
            if (a[i][0] == current_start) {
                remaining--;
                current_end = a[i][1];
            }
            else if (a[i][1] <= current_end) {
                remaining--;
            }
            else {
                current_start = a[i][0];
                current_end = a[i][1];
            }
        }
        
        return remaining;
    }
};
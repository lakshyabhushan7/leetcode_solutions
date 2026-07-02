class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            long long largest = arr[i];
            long long smallest = arr[i]; 
            
            for (int j = i + 1; j < n; j++) {
                largest = max(largest, (long long)arr[j]);
                smallest = min(smallest, (long long)arr[j]);
                ans += largest - smallest;
            }
        }
        return ans;
    }
};
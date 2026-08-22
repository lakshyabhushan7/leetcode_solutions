class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int cnt = 0;
        int prev = intervals[0][1]; 
        
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < prev) {
                cnt++;
                prev = min(prev, intervals[i][1]); //hum min isliye le rhe hai kyuki max wala hta dnege kyuki aage wo overlap kar sakta haii
            } else {
                prev = intervals[i][1];
            }
        }
        
        return cnt;
    }
};
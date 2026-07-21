class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        char target = '0' + digit; 
        
        for (int num : nums) {
            //using convertng to string method;
            string s = to_string(num);
            cnt += count(s.begin(), s.end(), target);
        }
        
        return cnt;
    }
};
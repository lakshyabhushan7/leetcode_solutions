class Solution {
public:
    bool ispallindrom(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                int currentLen = j - i + 1;
                if (ispallindrom(s, i, j) && currentLen > maxLen) {
                    maxLen = currentLen;
                    start = i; 
                }
            }
        }
        
        return s.substr(start, maxLen); 
    }
};
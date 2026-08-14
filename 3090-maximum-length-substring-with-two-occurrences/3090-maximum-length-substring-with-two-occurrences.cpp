class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLength = 0;
        
        for(int i = 0; i < s.length(); i++) {
            unordered_map<char, int> mp; 
            
            for(int j = i; j < s.length(); j++) {
                mp[s[j]]++;
                
                if(mp[s[j]] > 2) {
                    break; 
                }
                
                maxLength = max(maxLength, j - i + 1);
            }
        }
        return maxLength;
    }
};
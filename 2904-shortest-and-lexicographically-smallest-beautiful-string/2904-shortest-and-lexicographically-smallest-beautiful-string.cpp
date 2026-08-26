class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int one = 0;
        string ans = "";
        int j = 0;
        
        while(j < s.size()) {
            if(s[j] == '1') one++;
            
            while(one > k || (one == k && s[i] == '0')) {
                if(s[i] == '1') one--;
                i++;
            }
            
            if(one == k) {
                string temp = s.substr(i, j - i + 1);
                if(ans == "" || temp.length() < ans.length() || (temp.length() == ans.length() && temp < ans)) {
                    ans = temp;
                }
            }
            j++;
        }
        
        return ans;
    }
};
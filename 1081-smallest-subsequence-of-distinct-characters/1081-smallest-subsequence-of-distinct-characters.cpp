class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        vector<bool> vis(26, false);
        string ans = "";
        
        //har ek char ka number 
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        //main loop isme ek char uthake usko visit karke ans me push karenge
        for (char c : s) {
            cnt[c - 'a']--;
            
            if (vis[c - 'a']) {
                continue;
            }
            
            while (!ans.empty() && ans.back() > c && cnt[ans.back() - 'a'] > 0) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(c);
            vis[c - 'a'] = true;
        }
        
        return ans;
    }
};
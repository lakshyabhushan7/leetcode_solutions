class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //we have sorted the array for easier ccomparision 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0;
        int j = 0;
        
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;    // no of cookies iss more than greeed
            }
            j++;
        }
        
        return i;
    }
};
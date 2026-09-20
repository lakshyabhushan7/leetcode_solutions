class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; ++i) {
            mp['a' + i] = 26 - i;
        }

        int total=0;

        for(int i=0;i<s.length();i++){
         total+=mp[s[i]]*(i+1);
        }

        return total;
    }
};
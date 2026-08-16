class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0); // vector to stor all types of number in form of reminder devided by 3
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        //if 3 multiples are even
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        //if 3 multiples are odd 
        else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};
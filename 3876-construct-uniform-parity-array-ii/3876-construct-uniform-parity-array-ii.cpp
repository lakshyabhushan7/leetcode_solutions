class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool Odd = false;
        for (int i=0;i<nums1.size();i++) {
            if (nums1[i] < mn) {
                mn = nums1[i];
            }
            if (nums1[i] & 1) {
                Odd = true;
            }
        }
        if (mn & 1) {
            return true;
        }
        return !Odd;
    }
};
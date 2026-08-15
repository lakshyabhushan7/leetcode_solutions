class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int nonZeros = 0;
        
        for(int j = 0; j < nums.size(); j++){
            xr = xr ^ nums[j];
            if(nums[j] != 0) {
                nonZeros++;
            }
        }
        // if all are zero then ans will be zero
        if(nonZeros == 0) {
            return 0;
        }
        
        //if taking all element return non zero then whole array is ans
        if(xr != 0) {
            return nums.size();
        }
         
        // if whole xor is zero but removing 1 element makes non zero so ans will be ssize-1;
        return nums.size() - 1;
    }
};
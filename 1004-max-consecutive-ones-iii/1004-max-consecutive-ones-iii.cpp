class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int zero=0;
        int maxlen=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0) zero++;

            if(zero<=k){ 
                maxlen=max(maxlen,j-i+1);
            }

            if(zero>k){ 
                if(nums[i]==0) zero--;
                i++;
            }


        }
        return maxlen;
    }
};
class Solution {
public:

    int sm(int n){
        int sm=0;
        while(n>0){
            sm=sm+n%10;
            n=n/10;
        }
        return sm;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(i==sm(nums[i])){ 
                ans=i;
                break;
        }
        }

        return ans;
    }
};
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> freq(51,0);
        
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        
        if(k==n){
            int ans=-1;
            for(int i=0;i<n;i++) ans=max(ans,nums[i]);
            return ans;
        }
        else if(k==1){
            int ans=-1;
            for(int i=0;i<n;i++){
                if(freq[nums[i]]==1) ans=max(ans,nums[i]);
            }
            return ans;
        }
        else{
            int ans=-1;
            if(freq[nums[0]]==1) ans=max(ans,nums[0]);
            if(freq[nums[n-1]]==1) ans=max(ans,nums[n-1]);
            return ans;
        }
    }
};
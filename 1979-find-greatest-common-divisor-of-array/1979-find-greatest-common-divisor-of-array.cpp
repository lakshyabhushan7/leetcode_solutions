class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=INT_MAX;
        int largest=0;

        for(int i=0;i<nums.size();i++){
            largest=max(largest,nums[i]);
            smallest=min(smallest,nums[i]);
        }
        return gcd(largest,smallest);
    }
};
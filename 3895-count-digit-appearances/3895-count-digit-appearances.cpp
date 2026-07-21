class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            int a=nums[i];

            while(a>0){
               int b=a%10;
               a=a/10;
                if(b==digit) cnt++;
            }
        }
        return cnt;
    }
};
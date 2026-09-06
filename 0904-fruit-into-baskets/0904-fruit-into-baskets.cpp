class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> count(n, 0); 
        
        int left = 0;
        int ans = 0;
        int types = 0; 
        
        for(int i = 0; i < n; i++) {
           
            if(count[fruits[i]] == 0) {
                types++;
            }
            count[fruits[i]]++;
            
            while(types > 2) {
                count[fruits[left]]--;
                
                if(count[fruits[left]] == 0) {
                    types--;
                }
                left++;
            }
            
            ans = max(ans, i - left + 1);
        }
        
        return ans;
    }
};
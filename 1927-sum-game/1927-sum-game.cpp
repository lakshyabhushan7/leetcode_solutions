class Solution {
public:
    bool sumGame(string num) {
        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;
        int n = num.size();
        
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') q1++;
                else sum1 += num[i] - '0';
            } else {
                if (num[i] == '?') q2++;
                else sum2 += num[i] - '0';
            }
        }
        
        if ((q1 + q2) % 2 != 0) {
            return true;
        }
        
       int diff = sum1 - sum2;
       int needed = (q2 - q1) * 9 / 2;

       return diff != needed;
    }
};
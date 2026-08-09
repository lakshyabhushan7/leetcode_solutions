class Solution {
public:
    vector<int> binary(int n){
        vector<int> a;
        while(n > 0){
            int b = n % 2;
            a.push_back(b);
            n = n / 2; 
        }
        return a;
    }

    int minBitFlips(int start, int goal) {
        vector<int> a = binary(start);
        vector<int> b = binary(goal);

        
        while (a.size() < b.size()) a.push_back(0);
        while (b.size() < a.size()) b.push_back(0);

        int count = 0;
        for(int i = 0; i < a.size(); i++){
            if ((a[i] ^ b[i]) > 0) count++;
        }
        return count;
    }
};
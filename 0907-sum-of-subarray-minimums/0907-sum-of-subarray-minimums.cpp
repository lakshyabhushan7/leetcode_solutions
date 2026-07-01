class Solution {
    vector<int> findNSE(vector<int> arr) {
        vector<int> nse(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> arr) {
        vector<int> pse(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr), pse = findPSEE(arr);
        long long total = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            
            total = (total + (right * left * arr[i]) % mod) % mod;
        }
        return total;
    }
};
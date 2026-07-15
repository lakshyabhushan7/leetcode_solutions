class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long odd=n*n;

        long long even=n*(n+1);

       return gcd(odd,even);
    }
};
class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            int a=n%10;
            sum+=a;
            n=n/10;
        }
        return sum;
    }

    int prd(int n){
        int product=1;
        while(n>0){
            int a=n%10;
            product*=a;
            n=n/10;
        }
        return product;
    }
    bool checkDivisibility(int n) {
        int a=digitsum(n)+prd(n);

        return n%a==0;
    }
};
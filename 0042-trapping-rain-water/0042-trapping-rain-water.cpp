class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();

        int lmax=0,rmax=0,total=0;
        int l=0;
        int r=n-1;

        while(l<r){
            if(v[l]<v[r]){
                if(lmax>v[l]) total+=lmax-v[l];

                else lmax=v[l];

                l++;
            }

            else{
                if(rmax>v[r]) total +=rmax-v[r];

                else rmax=v[r];

                r--;
            }
        }
        return total;
    }
};
class Solution {
public:
    void helper(vector<int> &v,vector<vector<int>> &ans,vector<int>& arr,int target,int index ){
         if(index==arr.size()){
            if(target==0){
            ans.push_back(v);
            }
            return;
         }
    
         if(arr[index]<=target){
            v.push_back(arr[index]);
            helper(v,ans,arr,target-arr[index],index);
            v.pop_back();
         }
         helper(v,ans,arr,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(v,ans,candidates,target,0);
        return ans;
    }
};
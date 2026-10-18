class Solution {
public:
int n;
void solve (int idx,vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
    if(idx>=n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    solve (idx+1,nums,temp,ans);
    temp.pop_back();
    solve(idx+1,nums,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve (0,nums,temp,ans);
        return ans;
        
    }
};
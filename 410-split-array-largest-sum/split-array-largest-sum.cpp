class Solution {
public:
int n;
int solve(int idx,vector<int>&nums,int k,vector<vector<int>>&dp){
    if(k==1){int sum=0;
    for(int i=idx;i<n;i++){
        sum+=nums[i];
    }
    return sum;
    }
    if (dp[idx][k]!=-1)return dp[idx][k];
    int sum=0;
    int ans=INT_MAX;
   
    for (int i=idx;i<n;i++){
        sum+=nums[i];
      int remain=solve(i+1,nums,k-1,dp);
      int curr=max(sum,remain);
      
      ans=min(ans,curr);
      

    }
    return dp[idx][k]=ans;
}
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
      
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve (0,nums,k,dp);



        
    }
};
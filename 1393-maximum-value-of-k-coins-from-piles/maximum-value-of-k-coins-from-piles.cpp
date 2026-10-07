class Solution {
public:
int solve (vector<vector<int>>&piles,int i,int k,vector<vector<int>>&dp){
    if (k<=0)return 0;
    if (i==piles.size())return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    int nottake = solve (piles,i+1,k,dp);
    int sum=0;
    int result =0;
    for (int j=0;j<min((int)piles[i].size(),k);j++){
        sum+=piles[i][j];
        result =max(result,sum+solve(piles,i+1,k-(j+1),dp));
    }
    return dp[i][k]=max(nottake,result);
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve (piles,0,k,dp);
    }
};
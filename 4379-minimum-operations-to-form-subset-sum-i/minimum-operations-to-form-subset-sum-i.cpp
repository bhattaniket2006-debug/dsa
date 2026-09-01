class Solution {
public:

    int solve(int idx, vector<int>& nums, int sum,
              vector<vector<int>>& dp) {

        if (sum == 0)
            return 0;

        if (idx == nums.size())
            return 1e9;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        // Don't take this element
        int ans = solve(idx + 1, nums, sum, dp);

        int x = nums[idx];
        int op = 0;

        
        while (x <= sum) {

            int temp = solve(idx + 1, nums, sum - x, dp);

            if (temp != 1e9)
                ans = min(ans, op + temp);

            
            x *= 2;
            op++;
        }

  
        x = nums[idx];
        op = 0;

        while (x > 0) {

            if (x <= sum) {
                int temp = solve(idx + 1, nums, sum - x, dp);

                if (temp != 1e9)
                    ans = min(ans, op + temp);
            }

            x /= 2;
            op++;
        }

        return dp[idx][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {

        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(sum + 1, -1)
        );

        int ans = solve(0, nums, sum, dp);

        return ans == 1e9 ? -1 : ans;
    }
};
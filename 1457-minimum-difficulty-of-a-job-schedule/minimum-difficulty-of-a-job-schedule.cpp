class Solution {
public:
    int n;

    int solve(int idx, int d, vector<int>& jobDifficulty,
              vector<vector<int>>& dp) {

        if (d == 1) {
            int maxi = 0;

            for (int i = idx; i < n; i++) {
                maxi = max(maxi, jobDifficulty[i]);
            }

            return maxi;
        }

        if (dp[idx][d] != -1)
            return dp[idx][d];

        int maxi = 0;
        int result = INT_MAX;

        for (int i = idx; i <= n - d; i++) {

            maxi = max(maxi, jobDifficulty[i]);

            result = min(result,
                         maxi + solve(i + 1, d - 1,
                                      jobDifficulty, dp));
        }

        return dp[idx][d] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> dp(n, vector<int>(d + 1, -1));

        return solve(0, d, jobDifficulty, dp);
    }
};
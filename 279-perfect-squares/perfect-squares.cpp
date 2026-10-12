
class Solution {
public:
    int solve(vector<int>& arr, int idx, int value, vector<vector<int>>& dp) {
        if (value == 0) {
            return 0;
        }

        if (idx == 0) {
            return value;
        }

        if (dp[idx][value] != -1) {
            return dp[idx][value];
        }

        int nottake = solve(arr, idx - 1, value, dp);

        int take = INT_MAX;
        if (arr[idx] <= value) {
            take = 1 + solve(arr, idx, value - arr[idx], dp);
        }

        return dp[idx][value] = min(take, nottake);
    }

    int numSquares(int n) {
        vector<int> arr;

        for (int i = 1; i * i <= n; i++) {
            arr.push_back(i * i);
        }

        int m = arr.size();

        vector<vector<int>> dp(m, vector<int>(n + 1, -1));

        return solve(arr, m - 1, n, dp);
    }
};

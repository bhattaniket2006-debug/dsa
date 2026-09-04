class Solution {
public:
    vector<long long> dp;

    long long solve(int x) {
        if (x == 1)
            return 0;

        if (dp[x] != -1)
            return dp[x];

        long long ans = 1e18;

        for (int a = 1; a < x; a++) {
            int b = x - a;

            ans = min(ans,
                      solve(a) + solve(b) + 1LL * a * b);
        }

        return dp[x] = ans;
    }

    int minCost(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};
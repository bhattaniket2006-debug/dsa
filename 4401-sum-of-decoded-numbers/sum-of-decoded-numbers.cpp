class Solution {
public:

    long long power(long long x, long long y) {
        long long MOD = 1000000007;
        long long ans = 1;

        while (y > 0) {
            if (y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {

        long long MOD = 1000000007;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            int width = nums[i] % 10;
            long long d = nums[i] / 10;

            vector<int> arr;

            while (d > 0) {
                int digit = d % 10;
                arr.push_back(digit);
                d /= 10;
            }

            reverse(arr.begin(), arr.end());

            long long x = 0;
            int cnt = 0;

            while (cnt < width) {
                x = x * 10 + arr[cnt];
                cnt++;
            }

            long long y = 0;

            while (cnt < arr.size()) {
                y = y * 10 + arr[cnt];
                cnt++;
            }

            ans = (ans + power(x, y)) % MOD;
        }

        return ans;
    }
};
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        vector<long long> pref(2 * n + 1);

        for (int i = 1; i < 2 * n; i++) {
            pref[i ] = pref[i-1] + nums[i];
        }

        int ans = 0;

        for (int k = 0; k < n; k++) {

            long long first = pref[k + n/2] - pref[k];

            long long second = pref[k + n] - pref[k + n/2];

            if (first > second)
                ans++;
        }

        return ans;
    }
};
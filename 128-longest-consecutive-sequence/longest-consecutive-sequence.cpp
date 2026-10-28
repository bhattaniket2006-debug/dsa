class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int maxi = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                continue;
            }

            if (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                curr++;
            }
            else {
                curr = 1;
            }

            maxi = max(curr, maxi);
        }

        return maxi;
    }
};
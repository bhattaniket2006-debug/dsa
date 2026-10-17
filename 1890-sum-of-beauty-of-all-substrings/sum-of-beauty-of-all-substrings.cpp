
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {
                char ch = s[j];
                mp[ch]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (auto x : mp) {
                    maxi = max(maxi, x.second);
                    mini = min(mini, x.second);
                }

                sum += maxi - mini;
            }
        }

        return sum;
    }
};

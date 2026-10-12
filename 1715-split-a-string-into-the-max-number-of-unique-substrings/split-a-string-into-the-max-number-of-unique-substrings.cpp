
class Solution {
public:
    int solve(string s, int idx, unordered_map<string, int>& mp) {
        if (idx == s.length()) {
            return 0;
        }

        int ans = 0;

        for (int i = idx; i < s.length(); i++) {
            string str = s.substr(idx, i - idx + 1);

            if (mp[str] == 0) {
                mp[str]++;

                int temp = 1 + solve(s, i + 1, mp);
                ans = max(ans, temp);

                mp[str]--;
            }
        }

        return ans;
    }

    int maxUniqueSplit(string s) {
        unordered_map<string, int> mp;
        return solve(s, 0, mp);
    }
};

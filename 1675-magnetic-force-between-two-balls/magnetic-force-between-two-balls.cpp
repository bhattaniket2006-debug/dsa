class Solution {
public:

    bool ispossible(vector<int>& position, int m, int f) {

        long long lastpos = position[0];
        int count = 1;

        for (int i = 1; i < position.size(); i++) {

            if (position[i] - lastpos >= f) {
                count++;
                lastpos = position[i];
            }

            if (count >= m) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position[0];

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (ispossible(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
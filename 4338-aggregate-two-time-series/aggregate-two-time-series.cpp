class Solution {
public:

    int find(vector<vector<int>>& a, int t) {
        int low = 0;
        int high = a.size() - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (a[mid][0] >= t) {
                idx = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return idx;
    }

    vector<vector<int>> aggregateTimeSeries(
        vector<vector<int>>& series1,
        vector<vector<int>>& series2) {

        set<int> st;

        for (auto x : series1)
            st.insert(x[0]);

        for (auto x : series2)
            st.insert(x[0]);

        vector<vector<int>> ans;

        for (int t : st) {

            int idx1 = find(series1, t);
            int idx2 = find(series2, t);

            int val1 = 0;
            int val2 = 0;

            if (idx1 != -1)
                val1 = series1[idx1][1];

            if (idx2 != -1)
                val2 = series2[idx2][1];

            ans.push_back({t, val1 + val2});
        }

        return ans;
    }
};
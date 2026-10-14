class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n =grid.size();
        int m=grid[0].size();
        unordered_map<int,int>mp;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                mp[grid[i][j]]++;

            }
        }
        int missing =-1;
        int rep=-1;
        for (int i=1;i<=n*n;i++){
            if(mp[i]==0){
                missing =i;
            }
            if(mp[i]==2)rep=i;
        }
        vector<int>ans;
        ans.push_back(rep);
        ans.push_back(missing);
        return ans;
        
    }
};
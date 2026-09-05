class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        vector<int>diff(n,0);
        for (auto query :queries){
            int left=query[0];
            int right =query[1];
            int x =1;
            diff[left]+=1;
            if(right+1<n){
            diff[right+1]-=1;}
        }
        vector<int>ans(n);
        int cumsum=0;
        for (int i=0;i<n;i++){
            cumsum+=diff[i];
            ans[i]=cumsum;
        }
        for (int i=0;i<n;i++){
            if(nums[i]>ans[i])return false;
        }
        return true ;
        
    }
};
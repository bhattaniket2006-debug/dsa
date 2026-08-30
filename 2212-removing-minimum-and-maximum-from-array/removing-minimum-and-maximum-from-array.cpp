class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int index1=0;
        int index2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi)index2=i;
            if(nums[i]==mini)index1=i;
        }
        int ans=INT_MAX;
      
        int left=max(index1,index2)+1;
        int right =max(n-index1,n-index2);
        int mix= min(index1,index2)+1+n-max(index1,index2);
        ans=min(left,right);
        ans=min(ans,mix);
       
       

        return ans;
    }
};
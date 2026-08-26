class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>factors(n);
        for (int i=0;i<n;i++){
            int x=nums[i];
            for(int p =2;p*p<=x;p++){
                if(x%p==0){
                    factors[i].push_back(p);
                    while(x%p==0){
                        x/=p;
                    }
                }
            }
            if(x>1){
                factors[i].push_back(x);
            }
        }
        int ans=INT_MIN;
        int left=0;
        int distinct=0;
        unordered_map<int,int>mp;
        for (int right=0;right<n;right++){
            for (int x:factors[right]){
                if(mp[x]==0){
                distinct++;}
                mp[x]++;
            }
            while (distinct>k){
                for (int x:factors[left]){
                    mp[x]--;
                    if(mp[x]==0){
                        distinct--;
                    }
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;

        
    }
};
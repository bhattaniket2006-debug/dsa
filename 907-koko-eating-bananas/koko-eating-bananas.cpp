class Solution {
public:
bool helper(vector<int>& piles, int h,int k){
long long hours = 0;
for (int p : piles) {
hours += (p + k - 1) / k;
if (hours > h) return false; 
}
return hours <= h;
}


    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int ans=-1;
        int high =*max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
     return ans;
        
    }
};
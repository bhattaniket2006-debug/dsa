class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int idx=0;
        for (int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
            
            nums[idx]=nums[i];
            idx++;
            }
        }
        return idx;
        
    }
};
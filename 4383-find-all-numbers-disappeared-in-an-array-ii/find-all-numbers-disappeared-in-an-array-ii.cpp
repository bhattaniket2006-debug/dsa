class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
const int nax=1e5;
vector<bool>arr(nax+1);
for (int x:nums)arr[x]=true;
vector<vector<int>>range;
int start=lower;
while (start<=upper){
    int end=start;
    while(end<=upper&&!arr[end])end++;
    if(end!=start)range.push_back({start,end-1});
    start=end+1;
}
return range;

        
    }
};
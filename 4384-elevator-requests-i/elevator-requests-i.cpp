class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int p=requests.size();
        int ans =0;
        int currentfloor=0;
        for (int i=0;i<p;i++){
            ans+=abs(currentfloor-requests[i]);
            currentfloor=requests[i];


        }
        return ans;
        
    }
};
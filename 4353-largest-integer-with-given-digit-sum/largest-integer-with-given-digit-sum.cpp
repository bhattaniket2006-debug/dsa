class Solution {
public:
    int largestInteger(int n, int s) {
        if (s>n*9)return -1;
        int ans=0;
        int cnt=0;
        while(s!=0){
            int x=min(9,s);
            ans=ans*10+min(9,s);
            s-=x;
            cnt++;

        }
        while(cnt<n){
            ans*=10;
            cnt++;
        }

        return ans;
        
    }
};
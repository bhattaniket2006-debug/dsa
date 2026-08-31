class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        bool check=true;
        for (int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
           for(int j=1;j<n;j++){
            if(i>=strs[j].size()||strs[j][i]!=c)
            check=false;
           }
           if(check){
            ans+=c;
           }

        }
        return ans;
        
    }
};
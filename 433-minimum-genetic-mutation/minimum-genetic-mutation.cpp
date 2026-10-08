class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>st(bank.begin(),bank.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(start);
        visited.insert(start);
        int level =0;
        while (!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==end)return level;
                for (auto ch:"ACGT"){
                    for (int i=0;i<curr.length();i++){
                        string neigh=curr;
                        neigh[i]=ch;
                        if(visited.find(neigh)==visited.end()&&st.find(neigh)!=st.end()){
                            q.push(neigh);
                            visited.insert(neigh);
                           
                        }
                    }
                }


            }
            level++;
        }
        return -1;
        

    }
};
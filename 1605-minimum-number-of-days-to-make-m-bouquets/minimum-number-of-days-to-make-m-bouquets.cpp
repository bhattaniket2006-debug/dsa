class Solution {
public:
 bool possible (vector<int>& bloomDay, int m, int k, int day){
   int cnt =0;
   int no =0;
    for  (int i=0; i<bloomDay.size(); i++){
        if (bloomDay[i]<=day){
            cnt++;
        }else {
            no+=cnt/k;
            cnt=0;
        }
    }
     no+=cnt/k;
    if(no>=m){return true;}
    else {return false;} 
 }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
        
        int s = *min_element (bloomDay.begin(),bloomDay.end());
         int e = *max_element (bloomDay.begin(),bloomDay.end());
         int ans=-1;
         while (s<=e){
            int mid= s+(e-s)/2;
            if (possible(bloomDay,m,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{s=mid+1;}


         }
         return ans;
    }
};
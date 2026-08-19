/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;

        }
        ListNode*ans=head;
        int ans1=0;
        if(ans->next==NULL)return ans;

        
        while(ans){
            ans1++;
            ans=ans->next;
            if(ans1==cnt/2)break;
            
        }
        return ans;
        
    }
};
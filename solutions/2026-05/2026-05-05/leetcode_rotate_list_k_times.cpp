
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode*a=head;
        if(!head)return head;
        ListNode* pr=NULL;
        while(a){
            n++;
            pr=a;
            a=a->next;
        }
        k=k%n;
        if(k==0)return head;
        pr->next=head;
        k=n-k;
        a=head;
        pr=NULL;
        while(k--){
            pr=a;
            a=a->next;
        }
        pr->next=NULL;
        return a;
    }
};
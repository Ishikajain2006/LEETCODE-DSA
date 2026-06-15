class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* temp=head;
        ListNode* front=NULL;
        ListNode* prev=NULL;
        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    int pairSum(ListNode* head){
        if(head == NULL) return 0 ;
        if(head->next == NULL) return head->val ;
        if(head->next->next == NULL ) return head->val + head->next->val ;
      ListNode* slow = head ;
      ListNode* fast = head ;
      while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        } 
      ListNode* second = rev(slow);

        int ans = 0;
        ListNode* first = head;

        while(second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};

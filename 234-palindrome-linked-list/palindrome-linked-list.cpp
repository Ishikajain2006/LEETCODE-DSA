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
    ListNode* rev(ListNode* head){
        ListNode* temp = head ;
        ListNode* prev = NULL ;
        while(temp!=NULL){
            ListNode* nxt = temp->next ;
            temp->next = prev ;
            prev = temp ;
            temp = nxt ;
        }
        return prev ;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true ;
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast!=NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        ListNode* head2 = rev(slow) ;
        slow->next = NULL ;
        slow = head ;
        while(slow!= NULL){
            if(slow->val != head2->val) return false ;
            slow=slow->next ;
            head2=head2->next ;
        }
        return true ;
    }
};
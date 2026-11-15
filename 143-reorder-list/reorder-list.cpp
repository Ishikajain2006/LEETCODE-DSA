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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        ListNode* head2 = rev(slow->next) ;
        slow->next = NULL ;
        ListNode* Dhead1 = head ;
        ListNode* Dhead2 = head2 ;
        while(Dhead2 != NULL) {
            ListNode* nxt1 = Dhead1->next;
            ListNode* nxt2 = Dhead2->next;

            Dhead1->next = Dhead2;
            Dhead2->next = nxt1;

            Dhead1 = nxt1;
            Dhead2 = nxt2;
        }

    }
};
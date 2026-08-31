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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) 
                return {-1, -1}; 
        ListNode* prev = head; 
        ListNode* curr = head->next; 
        ListNode* nxt = curr->next;
        int i=0 ;
        vector<int>idx ;
        while(nxt != NULL){
            if(curr->val > prev->val && curr->val > nxt->val ||curr->val < prev->val && curr->val < nxt->val )
                idx.push_back(i);
            prev = curr ;
            curr = nxt ;
            nxt = nxt->next ;
            i++ ;
        }
        int minVal = INT_MAX , maxVal = INT_MIN ;
        if(idx.size() < 2) return {-1, -1};
        for(int j=1 ; j<idx.size() ; j++){
           int distance = idx[j] - idx[j-1]; 
           minVal = min(minVal, distance); 
           maxVal = max(maxVal, idx.back() - idx.front());
        }
        return {minVal , maxVal};
    }
};
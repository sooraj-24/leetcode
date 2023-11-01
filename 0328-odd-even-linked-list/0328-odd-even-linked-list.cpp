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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr = head;
        //ListNode* evenT, oddT;
        ListNode* evenH = new ListNode();
        ListNode* oddH = new ListNode();
        ListNode* evenT = evenH;
        ListNode* oddT = oddH;
        int ind = 1;
        while(curr){
            if(ind%2 == 0){
                evenT->next = curr;
                evenT = curr;
            } else {
                oddT->next = curr;
                oddT = curr;
            }
            curr = curr->next;
            ind++;
        }
        oddT->next = evenH->next;
        evenT->next = NULL;
        return oddH->next;
    }
};
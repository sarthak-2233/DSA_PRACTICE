/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *list1, ListNode *list2) {
       if(!list1 || !list2) return NULL;
        int c1=0;
        int c2=0;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        while(temp1)
        {
            c1++;
            temp1=temp1->next;
        }

        while(temp2)
        {
            c2++;
            temp2=temp2->next;
        }
        temp1=list1;
        temp2=list2;
        if(c1 > c2) {
            int diff = c1 - c2;
            while(diff--) {
                temp1 = temp1->next;
            }
        } else if(c2 > c1) {
            int diff = c2 - c1;
            while(diff--) {
                temp2 = temp2->next;
            }
        }
        // ab equal ab check
        while(temp1 && temp2)
        {
            if(temp1==temp2)
            return temp1;
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return NULL;
    }
};
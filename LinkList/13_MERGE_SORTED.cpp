
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tail=new ListNode(0);
        ListNode* head=tail;

        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                tail->next=list1;
                list1=list1->next;
                tail=tail->next;
            }
            else
            {
                tail->next=list2;
                list2=list2->next;
                tail=tail->next;
            }
        }
        // ab kuch bach gaya
      if(list1)
      {
        tail->next=list1;
        list1=list1->next;
      }

      if(list2)
      {
        tail->next=list2;
        list2=list2->next;
      }

        // ab tail ban gayi
        tail=head;
        head=tail->next;

        delete tail;

        return head;

    }
};
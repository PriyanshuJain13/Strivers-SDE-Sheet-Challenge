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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0,n2 = 0;
        ListNode* temp = headA;
        while(temp != NULL)
        {
            temp = temp->next;
            n1++;
        }

        temp = headB;
        while(temp != NULL)
        {
            temp = temp->next;
            n2++;
        }

        int n = abs(n1-n2);

        if(n1 > n2)
        {
            while(n--)
            {
                headA = headA->next;
            }
        }else{
            while(n--)
            {
                headB = headB->next;
            }
        }

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};
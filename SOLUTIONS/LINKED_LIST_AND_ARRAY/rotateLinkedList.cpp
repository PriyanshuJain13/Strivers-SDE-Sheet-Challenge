class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* cur = head;
        int n = 1;
        while(cur->next != NULL)
        {
            n++;
            cur = cur->next;
        }

        k = k%n;
        cur->next = head;
        cur = head;
        int end = n-k;
        while(end > 1)
        {
            cur = cur->next;
            end--;
        }

        head = cur->next;
        cur->next = NULL;
        return head;
    }
};

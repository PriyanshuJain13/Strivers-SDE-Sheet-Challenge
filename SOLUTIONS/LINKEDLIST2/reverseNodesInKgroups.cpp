class Solution {
public:

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    
    dummy->next = head;
    ListNode* beforeGroup = dummy;
    ListNode* afterGroup = head;
    ListNode* current = nullptr;
    ListNode* previous = nullptr;
    ListNode* nextNode = nullptr;

    while (true) {
        ListNode* cursor = afterGroup;
        for (int i = 0; i < k; i++) {
            if (cursor == nullptr) {
                return dummy->next;
            }
            cursor = cursor->next;
        }

        current = afterGroup;
        previous = beforeGroup;
        for (int i = 0; i < k; i++) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        afterGroup->next = current;
        beforeGroup->next = previous;
        beforeGroup = afterGroup;
        afterGroup = current;
    }
}
};

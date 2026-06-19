class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 element is already sorted
        if (!head || !head->next) {
            return head;
        }
        
        // 1. Split the list into two halves
        ListNode* left = head;
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // Disconnect the two halves
        
        // 2. Recursively sort both halves
        left = sortList(left);
        right = sortList(right);
        
        // 3. Merge the sorted halves
        return merge(left, right);
    }

private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; 
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
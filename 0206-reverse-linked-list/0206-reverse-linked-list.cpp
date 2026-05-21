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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // Using nullptr is best practice in modern C++
        ListNode* temp = head;

        while (temp != nullptr) {
            // Step 1: Save the next node before breaking the link
            ListNode* front = temp->next;

            // Step 2: Reverse the link (Point current node backward)
            temp->next = prev;

            // Step 3: Move the pointers one step forward
            prev = temp;
            temp = front;
        }

        // After the loop, 'prev' is at the new head of the reversed list
        return prev; 
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // हेल्पर फंक्शन: लिस्ट के दूसरे हिस्से को रिवर्स करने के लिए
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next_node = nullptr;
        while (curr != nullptr) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // स्टेप 1: मिडल नोड ढूंढें
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // स्टेप 2: आधी लिस्ट को रिवर्स करें
        ListNode* newHead = reverseLinkedList(slow->next);
        
        ListNode* first = head;
        ListNode* second = newHead;
        bool palindrome = true;
        
        // स्टेप 3: दोनों हिस्सों की तुलना करें
        while (second != nullptr) {
            if (first->val != second->val) { // 'data' की जगह 'val' किया
                palindrome = false; 
                break; // अगर मैच नहीं हुआ तो सीधे बाहर आएं
            }
            first = first->next;
            second = second->next;
        }
        
        // स्टेप 4: लिस्ट को वापस उसकी असली स्थिति में लाएं (गुड प्रैक्टिस)
        reverseLinkedList(newHead);
        
        return palindrome;
    }
};
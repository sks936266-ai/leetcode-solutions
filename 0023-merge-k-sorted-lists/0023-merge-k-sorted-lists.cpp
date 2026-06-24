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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 1. The loop ONLY handles the step-by-step comparison
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            // Move the tail forward after a node is attached!
            tail = tail->next; 
        }
        
        // 2. The leftover check happens completely OUTSIDE the loop, just once
        if(list1 != nullptr){
            tail->next = list1;
        }
        else{
            tail->next = list2;
        }
        
        return dummy.next;
    }
    ListNode* divideandconquer(vector<ListNode*>& lists, int start,int end){
        if(start>end) return nullptr;
        if(start==end) return lists[start];
        int mid= start + (end-start)/2;
        ListNode* lefthalf=divideandconquer(lists,start,mid);
        ListNode* righthalf=divideandconquer(lists,mid+1,end);
        return mergeTwoLists(lefthalf,righthalf);
    }
      
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return divideandconquer(lists,0,lists.size()-1);
    }
};
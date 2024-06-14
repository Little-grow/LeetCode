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
    int pairSum(ListNode* head) {
        int max_sum = INT_MIN;
        ListNode* fast = head; ListNode* slow = head;
        while(fast && slow){
            fast = fast->next->next;
            slow = slow ->next;
        }
        ListNode* second = reverse(slow);
        ListNode* first = head;
        
        while(first && second){
            max_sum = max(max_sum, first->val + second->val);
            first = first->next;
            second = second->next;
        }     
        return max_sum;
    }
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr)
                return head;    
        ListNode* prev = nullptr;
        ListNode* nextNode = head;
        while(nextNode != nullptr) {       
            ListNode* temp = nextNode->next;
            nextNode->next = prev;
            prev = nextNode;
            nextNode = temp;
        }
        return prev;
    }
};
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
    int getDecimalValue(ListNode* head) {
        // Step 1: Count the length
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        // The most significant bit has power = length - 1
        int power = length - 1;
        int result = 0;

        // Step 2: Compute decimal value
        while (head != nullptr) {
            if (head->val == 1) {
                result += (1 << power); // Use bit shifting instead of pow()
            }
            power--;
            head = head->next;
        }

        return result;
    }
};
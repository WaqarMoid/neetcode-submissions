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
        vector<int> nums;
        
        // Traverse list1 and store values in vector
        while (list1 != NULL) {
            nums.push_back(list1->val);
            list1 = list1->next;
        }

        // Traverse list2 and store values in vector
        while (list2 != NULL) {
            nums.push_back(list2->val);
            list2 = list2->next;
        }

        // Sort the vector
        sort(nums.begin(), nums.end());

        // If vector is empty, return NULL
        if (nums.size() == 0) return NULL;

        // Create new linked list from sorted vector
        ListNode* head = new ListNode(nums[0]);
        ListNode* current = head;

        for (int i = 1; i < nums.size(); i++) {
            current->next = new ListNode(nums[i]);
            current = current->next;
        }

        return head;
    }
};

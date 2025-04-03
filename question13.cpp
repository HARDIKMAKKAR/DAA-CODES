#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second->next) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

// Helper functions to create and print the linked list

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case 1: Input [1,2,3,4]
    vector<int> vals1 = {1, 2, 3, 4};
    ListNode* head1 = createList(vals1);
    cout << "Original List 1: ";
    printList(head1);
    Solution().reorderList(head1);
    cout << "Reordered List 1: ";
    printList(head1);

    // Test case 2: Input [1,2,3,4,5]
    vector<int> vals2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(vals2);
    cout << "Original List 2: ";
    printList(head2);
    Solution().reorderList(head2);
    cout << "Reordered List 2: ";
    printList(head2);

    // Test case 3: Input [1]
    vector<int> vals3 = {1};
    ListNode* head3 = createList(vals3);
    cout << "Original List 3: ";
    printList(head3);
    Solution().reorderList(head3);
    cout << "Reordered List 3: ";
    printList(head3);

    return 0;
}

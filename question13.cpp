#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; 

        vector<ListNode*> v;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            v.push_back(temp);
            prev = temp;
            temp = temp->next;
            prev->next = nullptr;
        }

        int i = 1, j = v.size() - 1;
        ListNode* curr = head;
        bool end = true;

        while (i <= j) {
            if (end) {
                curr->next = v[j];
                curr = curr->next;
                end = false;
                j--;
            } else {
                curr->next = v[i];
                curr = curr->next;
                end = true;
                i++;
            }
        }
    }
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}

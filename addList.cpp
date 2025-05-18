#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverseList(ListNode* &head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }  
    head = prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    reverseList(l1);
    reverseList(l2);

    ListNode* result = new ListNode(0);
    ListNode* current = result;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    reverseList(result->next);
    return result->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(0);
    l2->next = new ListNode(0);
    l2->next->next = new ListNode(1);

    ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}

#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
};


 void display(ListNode* head) {
            while(head) {
                cout << head->val << " -> ";
                head = head->next;
            }
            cout << "NULL\n";
        }

class Solution {
    public:
        ListNode* reverse_list_iteratively(ListNode* head) {
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* temp;

            while(curr) {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev;
        }

        ListNode* reverse_list_recursively(ListNode* head) {
            if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverse_list_recursively(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
        }
};

int main() {
    ListNode* headNextNext = new ListNode(30);
    ListNode* headNext = new ListNode(20, headNextNext);
    ListNode* head = new ListNode(10, headNext);

    display(head);
    Solution solution;
    ListNode* newHead = solution.reverse_list_iteratively(head);
    display(newHead);
    newHead = solution.reverse_list_recursively(newHead);
    display(newHead);
    return 0;
}
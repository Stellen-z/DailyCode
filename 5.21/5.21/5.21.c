#define _CRT_SECURE_NO_WARNINGS
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <cstddef>
class PalindromeList {
public:

    ListNode* FindMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }


    ListNode* ReverseList(ListNode* head) {
        ListNode* newhead = nullptr;
        ListNode* newtail = nullptr;
        ListNode* pcur = head;
        while (pcur) {
            ListNode* next = pcur->next;
            if (newhead == NULL) {
                newhead = pcur;
                newtail = pcur;
            }
            else {
                pcur->next = newhead;
                newhead = pcur;
            }
            pcur = next;
        }
        newtail->next = nullptr;
        return newhead;
    }

    bool chkPalindrome(ListNode* A)
    {
        if (A == nullptr) return true;
        //中间节点
        ListNode* mid = FindMid(A);

        //反转链表
        ListNode* newhead = ReverseList(mid);

        while (A && newhead)
        {
            if (A->val != newhead->val) return false;
            A = A->next;
            newhead = newhead->next;
        }
        return true;

    }
};
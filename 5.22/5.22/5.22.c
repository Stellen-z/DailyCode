#define _CRT_SECURE_NO_WARNINGS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode* fast = head,*slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }  
    return false;  
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* FindMeet(struct ListNode* head)
{
    struct ListNode* fast = head, * slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return fast;
    }
    return NULL;
}

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* meet = FindMeet(head);

    if (meet == NULL) return NULL;

    struct ListNode* newhead = meet->next;
    meet->next = NULL;

    //meet / head
    struct ListNode* curm = newhead, * curh = head;
    int cntm = 1, cnth = 1;
    while (curm)
    {
        cntm++;
        curm = curm->next;
    }
    while (curh)
    {
        cnth++;
        curh = curh->next;
    }

    struct ListNode* longlist = newhead, * shortlist = head;
    if (cntm < cnth)
    {
        longlist = head;
        shortlist = newhead;
    }

    int gap = abs(cnth - cntm);

    while (longlist && gap--)
    {
        longlist = longlist->next;
    }
    while (shortlist && longlist && shortlist != longlist)
    {
        shortlist = shortlist->next;
        longlist = longlist->next;
    }
    return shortlist;
}
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
class Solution
{
public:
    void append(ListNode *&head, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            ListNode *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    ListNode *buildList(vector<int> values)
    {
        ListNode *head = nullptr;
        for (int v : values)
        {
            append(head, v);
        }
        return head;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *merged = nullptr;
        ListNode *current1 = list1;
        ListNode *current2 = list2;

        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->val < current2->val)
            {
                append(merged, current1->val);
                current1 = current1->next;
            }
            else
            {
                append(merged, current2->val);
                current2 = current2->next;
            }
        }

        while (current1 != nullptr)
        {
            append(merged, current1->val);
            current1 = current1->next;
        }
        while (current2 != nullptr)
        {
            append(merged, current2->val);
            current2 = current2->next;
        }

        return merged;
    }
};
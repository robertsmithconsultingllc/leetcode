// C++CopyListWithRandomPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class Node 
{
public:

    int val;
    Node* next;
    Node* random;

    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution 
{
public:

    Node* copyRandomList(Node* head) 
    {
        unordered_map<int, int> idx;
        vector<Node*> seen{};
        Node* tmp1 = head, * ans = new Node(INT_MAX), * tmp2{}; tmp2 = ans; int j{};

        while (tmp1)
        {
            idx[j++] = tmp1->val;
            tmp2->next = new Node(tmp1->val);
            seen.push_back(tmp2->next);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tmp1 = ans->next; tmp2 = head;
        while (tmp2)
        {
            if (tmp2->random)
            for (auto n : idx)
            {
                if (n.second == tmp2->random->val)
                {
                    tmp1->random = seen[n.first];
                    break;
                }
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return ans->next;
    }
};

int main()
{
    Solution myptr;

    Node* list1;
    list1 = new Node(3);
    list1->next = new Node(3);
    list1->next->next = new Node(3);
    list1->random = NULL;
    list1->next->random = list1;
    list1->next->next->random = NULL;

    Node* ans{};

    ans = myptr.copyRandomList(list1);

    cout << "List contents: " << endl;

    while (ans)
    {
        cout << "val: " << ans->val << " addr: " << ans << " next: " << ans->next << " random: " << ans->random << endl;
        ans = ans->next;
    }

    return 0;
}

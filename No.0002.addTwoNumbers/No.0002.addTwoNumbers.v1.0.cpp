#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a = 0;
		int b = 0;
		int carry = 0;
		m_pHead = new ListNode(0);
		ListNode *pTail = m_pHead;

		while (l1 || l2) {
			if (l1)
				a = l1->val;
			if (l2)
				b = l2->val;

			int c = a + b + carry;
			carry = c / 10;
			c = c % 10;

			ListNode *p = new ListNode(c);
			pTail->next = p;
			pTail = p;

			a = b = 0;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;

			if (!l1 && !l2 && carry != 0) {
				ListNode *p = new ListNode(carry);
				pTail->next = p;
			}
		}

		return m_pHead->next;
	}


public:
	ListNode *m_pHead = nullptr;
};

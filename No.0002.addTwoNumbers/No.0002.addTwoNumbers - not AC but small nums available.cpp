#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		long long a = 0;
		long long b = 0;

		a = this->listToNum(l1);
		b = this->listToNum(l2);

		long long res = a + b;
		long long t = res;

		// BUG2: can work when res != 0, but improper
		//ListNode head(0);
		//head.next = NULL;
		//ListNode *pTail = &head;

		ListNode *pTail = m_pHead;

		if (0 == res) {

			//return &head;// BUG1: cannot work, because head is a Local variable

			// BUG2: can work, but improper
			//ListNode *temp = new ListNode(0);
			//return temp;

			m_pHead = new ListNode(0);
			return m_pHead;
		}

		while (res != 0) {
			t = res % 10;
			res = res / 10;
			ListNode *l = new ListNode(static_cast<int>(t));
			pTail->next = l;
			pTail = l;
		}

		//return head.next;// BUG2: can work when res != 0, but improper
		return m_pHead->next;
	}

	long long listToNum(ListNode *p)
	{
		vector<long long> radix;
		while (p != NULL) {
			radix.push_back(p->val);
			p = p->next;
		}
		long long a = 0;
		for (int i = 0; i != radix.size(); i++) {
			a = radix[i] * pow(10, i) + a;
			//a = 10 * a + i; // remember: list is reverse!
		}
		return a;
	}

public:
	ListNode *m_pHead = nullptr;
};

//long long createNum(const vector<int>& numVec)
//{
//	long long res;
//	for (int i = 0; i != numVec.size(); i++) {
//		res = numVec[i] * pow(10, i) + res;
//	}
//	return res;
//}

int main()
{
	vector<int> NumVec1{ 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 9 };
	vector<int> NumVec2{ 5, 6, 4, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 9, 9, 9, 9 };


	ListNode l1(2);
	ListNode l2(4);
	ListNode l3(3);

	l2.next = &l3;
	l1.next = &l2;

	ListNode l4(5);
	ListNode l5(6);
	ListNode l6(4);

	l5.next = &l6;
	l4.next = &l5;

	ListNode lZero1(0);
	ListNode lZero2(0);

	Solution s;

	ListNode *p = s.addTwoNumbers(&l1, &l4);
	//ListNode *p = s.addTwoNumbers(&lZero1, &lZero2);

	while (p != NULL) {
		cout << p->val << endl;
		if (p->next != NULL)
			p = p->next;
		else
			break;
	}

	return 0;

}
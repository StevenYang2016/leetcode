#pragma once
#include "stdio.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class addTwoNumbers
{
public:
	
	addTwoNumbers();
	~addTwoNumbers();
	
	ListNode* addTwoNumbers_f(ListNode* l1, ListNode* l2);
	ListNode* addRecursion(ListNode* l1, ListNode* l2,int carry);
	ListNode* add(ListNode* l1, ListNode* l2);
	ListNode* creatListNotes(int n);
	void printListNotes(ListNode* l);
};


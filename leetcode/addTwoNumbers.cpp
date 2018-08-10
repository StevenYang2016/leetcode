#include "stdafx.h"
#include "addTwoNumbers.h"


addTwoNumbers::addTwoNumbers()
{
	//printf("stat to creat the list \n");
	ListNode * l1 = creatListNotes(2);
	printListNotes(l1);
	ListNode * l2 = creatListNotes(4);
	printListNotes(l2);
	//printf("stat to print the list \n");
	//cont << 5 << endl;
	//ListNode* result = addTwoNumbers_f(l1,l2);
	//ListNode* result = addRecursion(l1,l2,0);
	ListNode* result = add(l1, l2);
	printListNotes(result);
}


addTwoNumbers::~addTwoNumbers()
{
}

ListNode* addTwoNumbers::creatListNotes(int n) {
	ListNode * note=NULL,*ret=NULL,*newNote=NULL;
	int i = 0;
	while (i < n) {
		if (i == 0) {
			note = new ListNode(i);
			ret = note;
		}
		else {
			newNote = new ListNode(i);
			note->next = newNote;
			note = note->next;
		}
		i++;
		// = note->next;
	}
	return ret;
}

void addTwoNumbers::printListNotes(ListNode* l) {

	while (l!= NULL) {
		printf("%d \n",l->val);
		l = l->next;
	}
}


ListNode* addTwoNumbers::addTwoNumbers_f(ListNode* l1, ListNode* l2) {
	int temp = 0;
	ListNode* ret;
	ListNode* note = new ListNode(0);
	ret = note;
	if (l1 == NULL && l2 != NULL)
		return l2;
	if (l1 != NULL && l2 == NULL)
		return l1;
	if ((l1 == NULL) && (l2 == NULL))
		return NULL;
	while ((l1 != NULL) && (l2 != NULL)) {
		if (temp) {
			note->val = (l1->val + l2->val) + 1;
			temp = 0;
		}
		else {
			note->val = l1->val + l2->val;
		}
		if (note->val >= 10) {
			temp = 1;
			note->val = (note->val) % 10;
		}
		l1 = l1->next;
		l2 = l2->next;
		//printf("%d \n", note->val);
		if ((l1 != NULL) || (l2 != NULL)) {
			ListNode* newNote = new ListNode(0);
			printf("%d \n", note->val);
			note->next = newNote;
			note = note->next;
		}
	}
	while ((l1 == NULL) && (l2 != NULL)) {
		if (temp) {
			note->val = l2->val + 1;
			temp = 0;
		}
		else {
			note->val = l2->val;
		}
		if (note->val >= 10) {
			temp = 1;
			note->val = (note->val) % 10;
		}

		l2 = l2->next;
		if (l2 != NULL) {
			ListNode* newNote = new ListNode(0);
			note->next = newNote;
			note = note->next;
		}

	}
	while ((l1 != NULL) && (l2 == NULL)) {
		if (temp) {
			note->val = l1->val + 1;
			temp = 0;
		}
		else {
			note->val = l1->val;
		}
		if (note->val >= 10) {
			temp = 1;
			note->val = (note->val) % 10;
		}

		l1 = l1->next;
		if (l1 != NULL) {
			ListNode* newNote = new ListNode(0);
			note->next = newNote;
			note = note->next;
		}

	}
	if ((l1 == NULL) && (l2 == NULL)) {
		if (temp) {

			ListNode* newNote = new ListNode(1);
			//printf("%d \n",note->val);
			note->next = newNote;
			note = note->next;
			//printf("last %d \n", note->val);
		}
	}
	return ret;
}
ListNode * addTwoNumbers::addRecursion(ListNode * l1, ListNode * l2, int carry)
{
	if (l1 == NULL && l2 == NULL) {
		return carry == 0 ? NULL : new ListNode(carry);
	}
	if (l1 == NULL && l2 != NULL) {
		l1 = new ListNode(0);
	}
	if (l2 == NULL && l1 != NULL) {
		l2 = new ListNode(0);
	}
	int sum = l1->val + l2->val + carry;
	ListNode * curr = new ListNode(sum % 10);
	curr->next = addRecursion(l1->next, l2->next, sum / 10);
	return curr;
}

ListNode * addTwoNumbers::add(ListNode * l1, ListNode * l2)
{
	ListNode *dummyHead = new ListNode(0);
	if (l1 == NULL && l2 == NULL) {
		return dummyHead;
	}
	int sum = 0, carry = 0;
	ListNode * curr = dummyHead;
	while (l1 != NULL || l2 != NULL) {
		int num1 = l1 == NULL ? 0 : l1->val;
		int num2 = l2 == NULL ? 0 : l2->val;
		sum = num1 + num2 + carry;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
		carry = sum / 10;
		l1 = l1 == NULL ? NULL : l1->next;
		l2 = l2 == NULL ? NULL : l2->next;
	}
	if (carry != 0) {
		curr->next = new ListNode(carry);
	}
	return dummyHead->next;
}

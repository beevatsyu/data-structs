#include <iostream>
#include "linked_list.hpp"

typedef LinkedList<int> List;
typedef LinkedList<int>::Node Node;

/*
 * http://www.ideserve.co.in/learn/sum-of-two-linked-lists-using-recursion-set-2
 *
 * In this problem, a number is represented in reverse fashion, that is its unit
 * digit is placed at the beginning of the linked list.
 * For example, number 98734 is represented as 4->3->7->8->9. Given this
 * representation, write a program that takes input as two linked lists
 * (which represent two numbers) and returns output as the linked list which is
 * sum of two numbers represented by input linked lists.

 * Example:
 * Input: 1->7->9->9->9->null(number 99971), 8->9->9->null(number 998).
 * Output: 9->6->9->0->0->1->null(number 100969)
 */

List operator+(List const& L1, List const& L2) {
	List S;
	Node *p1 = L1.head;
	Node *p2 = L2.head;
	Node **p = &S.head;
	int carry = 0;

	while (p1 || p2) {
		if (p1) {
			carry += p1->data;
			p1 = p1->next;
		}
		if (p2) {
			carry += p2->data;
			p2 = p2->next;
		}
		*p = new Node(carry % 10);
		p = &(*p)->next;
		carry /= 10;
	}
	if (carry) {
		*p = new Node(carry);
		p = &(*p)->next;
	}
	*p = NULL;
	return S;
}

/*
 * Minimalistic code for inserting an element into a sorted linked list
 * using pointer to pointer.
 */

void insert_into_sorted(List& L, int item) {
	Node **ptr = &L.head;
	while ((*ptr)->data < item) {
		ptr = &(*ptr)->next;
	}
	Node *node = new Node(item);
	node->next = *ptr;
	*ptr = node;
}

/*
 * Intersection node
 */
Node* find_intersection(List& L1, List& L2) {
	Node *node = NULL;
	Node *slow = L1.head;
	Node *fast = L2.head;

	while (1) {
		if (slow == fast) {
			node = slow;
			break;
		}
		slow = slow->next ? slow->next : L1.head;
		fast = fast->next && fast->next->next ?
			fast->next->next : L2.head;
		if (slow == L1.head && fast == L2.head) {
			break; /* completed the cycle */
		}
	}

	return node;
}

/*
 * Reverse list in groups
 */
Node* rev_group(Node *head, int k) {
	Node *beg = head;
	Node *end = beg;
	for (int i = 0; i < k - 1 && end->next; i++) {
		end = end->next;
	}
	if (end->next == NULL) {
		return head;
	}
	Node *beg1 = end->next;
	Node *end1 = beg1;
	for (int i = 0; i < k - 1 && end1->next; i++) {
		end1 = end1->next;
	}
	Node *node = rev_group(beg1, k);
	end1->next = beg;
	end->next = NULL;
}

int main(int argc, const char *argv[])
{
	List L1;
	L1.Append(2);
	L1.Append(5);
	L1.Append(7);
	L1.Append(9);
	L1.Append(4);
	L1.Append(3);
	L1.Append(8);
	L1.Append(6);
	std::cout << L1;
	return 0;
}

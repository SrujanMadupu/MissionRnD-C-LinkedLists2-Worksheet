/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
int findlen(struct node*);
struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head != NULL){
		struct node *temp = head;
		int len = findlen(head),medium;
		if (len == 1){
			medium = temp->num;
			return medium;
		}
		int t = len / 2;
		while (t > 1){
			temp = temp->next;
			t--;
		}
		if (len % 2 == 0){
			medium = ((temp->num) + (temp->next->num))/2;
			return medium;
		}
		else{
			medium = (temp->next)->num;
			return medium;
		}
	}
	else{
		return -1;
	}
}
int findlen(struct node *q){
	int l = 0;
	while (q != NULL){
		l++;
		q = q->next;
	}
	return l;
}
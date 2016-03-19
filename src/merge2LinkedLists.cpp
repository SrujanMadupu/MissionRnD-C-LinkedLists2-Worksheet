/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 != NULL || head2 != NULL){
		struct node *merge;
		if (head1 == NULL){
			return head2;
		}
		else if (head2 == NULL){
			return head1;
		}
		else{
			struct node  *tempA, *tempB, *rA, *rB;
			tempA = head1;
			tempB = head2;
			int lenA = 0, lenB = 0;
			while (tempA != NULL&&tempB != NULL){
				if (tempA->num <= tempB->num){
					if (tempA->next != NULL){
						if (tempB->num < tempA->next->num){
							rA = tempA->next;
							tempA->next = tempB;
							tempA = rA;
						}
						else{
							tempA = tempA->next;
							lenA++;
						}
					}
					else{
						tempA->next = tempB;
						if (lenB > 0 && lenA==0){
							merge = head2;
						}
						else{
							merge = head1;
						}
						tempA = NULL;
					}
				}
				else{
					if (tempB->next != NULL){
						if (tempA->num <= tempB->next->num){
							rB = tempB->next;
							tempB->next = tempA;
							tempB = rB;
						}
						else{
							tempB = tempB->next;
							lenB++;
						}
					}
					else{
						tempB->next = tempA;
						if (lenA > 0 && lenB==0){
							merge = head1;
						}
						else{
							merge = head2;
						}
						tempB = NULL;
					}
				}
			}
			return merge;
		}
	}
	else{
		return NULL;
	}
}

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
	int val;
	struct node *next;
}
node;

void print(node *list) {
	if (list == NULL) {
		printf("Stack is empty");
	}
	else {
		for (node *p = list; p != NULL; p = p->next) {
			printf("%d\n", p->val);
		}
		printf("\n");
	}
}

void push(node **list, int x) {
	node *p = malloc(sizeof(node));
	p->val = x;
	if (list == NULL) {
		*list = p;
	}
	else {
		p->next = *list;
		*list = p;
	}
}

int pop(node **list) {
	if (*list == NULL) {
		printf("Stack is empty");
		return 0;
	}
	else {
		int x;
		node *p = *list;
		*list = p->next;
		x = p->val;
		free(p);
		return x;
	}
}

int main(void) {
	node *list = NULL;
	int punkt;
	int x;

	do {
		printf("What do you want to do?\n");
		printf("1. Add item\n");
		printf("2. Remove item\n");
		printf("3. Print item\n");
		printf("Enter > ");
		scanf_s("%d%*c", &punkt);

		while (((punkt < 1 || punkt > 3)) && (punkt != 0)) {
			printf("Incorrect item, try again: ");
			scanf_s("%d%*c", &punkt);
		}

		switch (punkt) {
		case 1:
			printf("Write a number: ");
			scanf_s("%d", &x);
			push(&list, x);
			break;

		case 2:
			pop(&list);
			break;

		case 3:
			print(list);
			break;
		}
		printf("\n");
	} while (punkt != 0);
	return 0;
}

//cift yönlü listeler

#include <stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next= NULL;
	struct node* prev=NULL;
};
//cift yonlu bagli liste(double linked list)
struct node* createNode(int x) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;
	yeni->next = yeni ->prev=NULL;
	return yeni;
}
void printList(struct node* head) {
	struct node* tmp = head;
	while (tmp != NULL) {
		printf("%d\t", tmp->data);
		tmp = tmp->next;
		printf("\n");
	}
	
}
void arayaEkle(struct node* head, int x, int y) {
	struct node* yeni = createNode(x);
	struct node* tmp = head;
	while (tmp->data != y) {
		tmp = tmp->next;
	}
	yeni->next = tmp->next;
	yeni->prev = tmp;
	tmp->next->prev = yeni;
	tmp->next = yeni;
}
int main() {
	struct node* yeni1 = createNode(5);
	struct node* yeni2 = createNode(15);
	struct node* yeni3 = createNode(25);
	yeni1->next = yeni2;
	yeni2->next = yeni3;
	yeni3->prev = yeni2;
	yeni2->prev = yeni1;
	printList(yeni1);
	arayaEkle(yeni1,32,15);
	printList(yeni1);
	return 0;
}


//Bagli liste olusturma 
//bagli listede islemler

#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
};
 struct node* createNode(int a) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = a;
	yeni->next = NULL;
	//(*yeni).next = NULL;  bu eski yazımıdır c dilinde ama artık -> daha kolay olduğundan -> da yıldız barındırır 
	return yeni;
};
void printList(struct node* head) {
	struct node* tmp = head;
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}
void basaEkle(struct node**head,int a) {
	struct node* yeni = createNode(a);
	yeni->next = *head;
	*head = yeni;
}
void arayaEkle(struct node * head ,int x, int y) {
	struct node* yeni = createNode(x);
	struct node* tmp= head;
	while (tmp->data != y) {
		tmp = tmp->next;
	}
	yeni->next = tmp -> next;
	tmp->next = yeni;
}
void sonaEkle(struct node* head, int a) {
	struct node* yeni = createNode(a);
	struct node* tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = yeni;
}
void bastanSil(struct node** headinadresi) {
	struct node* tmp = *headinadresi;
	*headinadresi = tmp->next;
	free(tmp);
}
void aradanSil(struct node* head, int x) {
	struct node* tmp = head;
	while (tmp->next->data != x) {
		tmp = tmp->next;
	}
	struct node* sil = tmp->next;
	tmp->next = tmp->next->next;
	free(sil);
}
void sondanSil(struct node* head) {
	struct node* tmp = head;
	while (tmp->next->next != NULL) {
		tmp = tmp -> next;
	}
	free(tmp->next);
	tmp->next = NULL;
}
int main() {
	struct node* dugum1 = createNode(01);
	struct node* dugum2 = createNode(32);
	struct node* dugum3 = createNode(06);
	dugum1->next = dugum2; dugum2->next = dugum3;
	printList(dugum1);
	printf("\n");

	basaEkle(&dugum1, 33);
	printList(dugum1);
	printf("\n");
	
	arayaEkle(dugum1, 80, 32);
	printList(dugum1);
	printf("\n");
	
	sonaEkle(dugum1, 42);
	printList(dugum1);
	printf("\n");
	
	bastanSil(&dugum1);
	printList(dugum1);
	printf("\n");

	aradanSil(dugum1, 06);
	printList(dugum1);
	printf("\n");

	sondanSil(dugum1);
	printList(dugum1);
	printf("\n");
}
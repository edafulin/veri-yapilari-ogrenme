//cevrimsel (Dairesel) Baglı Liste (Haftanın Ana Konusu)
//Bagli Listeyi Ters cevirme (Reverse a Linked List)
//iki Listeyi Fermuar Gibi Birleştirme (Merge / Interleave)
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* createNode(int a){
	struct node* yeni = (struct node*)calloc(1,sizeof(struct node));
	yeni->data = a;
	yeni->next = NULL;
	return yeni;
}
void printList(struct node* head) {
	struct node* tmp = head;
	do {
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	} while (tmp != head);
	printf("\n");

	/*while (tmp->next != head) {
		printf("%d\n", tmp->data);
	}
	printf("%d", tmp->data);
	de yazsak oluyoooor*/
}
void basaEkle(struct node ** headinadresi,int a) {
	struct node* yeni = createNode(a);
	struct node* tmp = *headinadresi;
	while (tmp->next != *headinadresi) {
		tmp = tmp->next;
	}
	tmp->next = yeni;
	yeni->next = *headinadresi;
	*headinadresi = yeni;
}
void arayaEkle(struct node* head, int a,int b) {
	struct node* yeni = createNode(a);
	struct node* tmp = head;
	while (tmp->data != b) {
		tmp = tmp->next;
	}
	yeni->next = tmp->next;
	tmp->next = yeni;
}
void sonaEkle(struct node* head, int a) {
	struct node* yeni = createNode(a);
	struct node* tmp = head;
	while (tmp->next != head) {
		tmp = tmp->next;
	}
	tmp->next = yeni;
	yeni->next = head;
}
void bastanSil(struct node** headinadresi) {
	struct node* tmp = *headinadresi;
	struct node* sil = *headinadresi;
	while (tmp->next != *headinadresi) {
		tmp = tmp->next;
	}
	*headinadresi = sil->next;
	free(sil);
	tmp->next = *headinadresi;
}
void aradanSil(struct node* head, int a) {
	struct node* tmp = head;
	struct node* sil;
	while (tmp->next->data != a) {
		tmp = tmp->next;
	}
	sil = tmp->next;
	tmp->next = sil->next;
	free(sil);
}
void sondanSil(struct node* head) {
	struct node* tmp = head;
	while (tmp->next->next != head) {
		tmp = tmp->next;
	}
	struct node* sil;
	sil = tmp->next;
	tmp->next = head;
	free(sil);
}
int main() {
	struct node * dugum1 = createNode(12);
	struct node* dugum2 = createNode(34);
	struct node* dugum3 = createNode(56);
	dugum1->next = dugum2;
	dugum2->next = dugum3;
	dugum3->next = dugum1;
	printList(dugum1);

	basaEkle(&dugum1, 11);
	printList(dugum1);

	arayaEkle(dugum1, 41, 34);
	printList(dugum1);

	sonaEkle(dugum1, 81);
	printList(dugum1);

	bastanSil(&dugum1);
	printList(dugum1);

	aradanSil(dugum1, 41);
	printList(dugum1);

	sondanSil(dugum1);
	printList(dugum1);
}
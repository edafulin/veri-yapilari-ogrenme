#include <stdio.h>
#include<stdlib.h>
void yerDegistir(int* a, int* b) {
	int hafiza = *a;
	*a = *b;
	*b = hafiza;
}
int main() {
	int sayi1 = 10;
	int sayi2 = 32;
	int* ptr1 = &sayi1;
	int* ptr2 = &sayi2;
	yerDegistir(ptr1,ptr2);

	int* dinamikDizi = (int*)malloc(3 * sizeof(int));
	int* ilkAdres = dinamikDizi;
	*ilkAdres = 10;
	*++ilkAdres =20;
	*++ilkAdres = 30;
	yerDegistir(dinamikDizi+1, (dinamikDizi + 2));
	printf("%d\n%d\n%d\n",*dinamikDizi,*(dinamikDizi+1),*(dinamikDizi+2));
	printf("%d\n", *dinamikDizi);
	printf("%d\n", *(dinamikDizi+1));
	printf("%d\n", *(dinamikDizi+2));
	free(dinamikDizi);

	void* jokerptr = NULL;
	char harf = 'e';
	jokerptr = &sayi1;
	printf("%d\n", jokerptr);
	printf("%d\n", *(int*)jokerptr);
	jokerptr = &harf;
	printf("%c\n", *(char*)jokerptr);

	int sayi3 = 36;
	int* adres1 = &sayi3;
	int** adres2 = &adres1;
	int*** adres3 = &adres2;
	printf("%d\n", ***adres3);
	printf("%d\n", **adres3);
	
	int* dinamikDizi2 = (int*)calloc(5, sizeof(int));
	int* p = dinamikDizi2;
	int* q = dinamikDizi2+4;
	printf("%d\n", (q - p));
	free(dinamikDizi2);

}
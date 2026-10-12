//author:edafulin

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sayi1 = 16;
	String kelime = "eda";
	int sayi2 = 27;
	int* ptr1 = &sayi1;
	int* ptr2 = &sayi2;
		(*ptr1)++;
		printf("%d", * ptr1);
		(*ptr2) += 5;
		printf("%d", * ptr2);
	int toplam = *ptr2 + *ptr1;
	printf("%d",toplam);
	printf(kelime);

}


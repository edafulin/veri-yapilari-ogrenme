
#include <stdio.h>;
#include <stdlib.h>;
void hesapla(int* s2, int s1) {
	*s2 += 10;
	s1 += 10;
}
int main() {
	int sayi1 = 10;
	int sayi2 = 20;
	int *ptr1 = &sayi1;
	int *ptr2 = &sayi2;
	int** ptr3 = &ptr1;
	printf("sayi1 in bellekteki konumu = %d\n", ptr1);
	printf("pointer1 in ciktisi = %d\n", *ptr1);
	printf("sayi2 nin bellekteki konumu  = %d\n", ptr2);
	printf("pointer2 nin ciktisi = %d\n", *ptr2);
	printf("iki yildizli pointerin pointer1 den sekmesi = %d\n", **ptr3);
	printf("pointer1 i artirdik = %d\n", ++*ptr1);
	printf("pointer1 in icindeki adres = %d\n", ptr1);
	printf("sayi1 in degeri = %d\n", *ptr1);
	printf("pointer2 i sonra artirdik = %d\n", *ptr2++);
	printf("pointer2 in icindeki adres = %d\n", ptr2);
	printf("sayi2 in degeri = %d\n", *ptr2);

	
	// Artirma azaltma
	printf("\n\n*********************************2.KISIM******************************************\n");
	int a = 2;
	int dizi[2] = { 10,20 };
	int* p1 = &a;
	int* p2 = &dizi[0];
	printf("a nin degerini bir artir = %d\n", ++ * p1);
	printf("a nin degerini bir azalt ama yazdirdiktan sonra = %d\n", *p1--);
	printf("ptr2 nin degerini bir artir = %d\n", *++p2);
	printf("ptr2 nin icindeki degeri yaz = %d\n", *p2);
	printf("ptr2 yi bir geri al ve yaz = :%d\n", *(--p2));


	//**************VOID POINTER************
	printf("\n\n******************************************VOID POINTER*********************************\n");
	int sayii = 5;
	char harff = 'E';
	void* gp;
	gp = &sayii;
	printf("void i int olarak yazalim = %d\n", *(int*)gp);
	gp = &harff;
	printf("void i int olarak yazalim = %c\n", *(char*)gp);
	//void pointerda aritmetik yapýlamaz. çünkü compiler ne üzerinde çalýþtýðýný bilmez .
	//void pointerda aritmetik yapýlamaz. çünkü compiler ne üzerinde çalýþtýðýný bilmez .
	//üstelik void pointerda ++ ya da -- yoktur çünkü derleyici deðiþkenin ne kadar yer kapladýðýný bilemez.
	
	
	//******************POINTER FARKINDAN ELEMAN SAYISI BULMAK*********
	printf("\n\n*********************************POINTER FARKINDAN ELEMAN SAYISI BULMAK***************************\n");
	//bunun için pointerlarýn ayný veri tipinde olmasý gerekir
	int dizi2[5] = { 10,32,80,60,33 };
	int* point = dizi2;
	int* pointson = &dizi2[5];
	//pointer dan pointer çýkardýðýmýzda bölme iþlemini bilgisayar otomatik olarak arkaplanda kendisi yapar.
	printf("dizinin kac elemani oldugunu bul = %d\n", (pointson - point));
	
	
	//*****************MALLOC-CALLOC-FREE-KULLANIMI**********************
	printf("\n\n*******************************************MALLOC-CALLOC-FREE-KULLANIMI***********************************************\n");
	//malloc dersek dizinin elelmanlarý ya rastgele ya da eskiden kalan elemanlarla doludur.
	//malloc(toplam_byte_sayisi)
	int elemansayisi = 5;
	int* dizi3 = (int*)malloc(5 * sizeof(elemansayisi));
	printf("malloc ile olusan dizinin elemanlari\n");
	for (int i = 0; i < 5; i++) {
		printf("%d\n",dizi3[i]);
	}
	//realloc( eski_pointer , yeni_toplam_byte )
	dizi3 = (int*)realloc(dizi3, 40);

	//calloc(eleman_sayisi , eleman_byte_uzunlugu)
	dizi3 = (int*)calloc(10 , sizeof(elemansayisi));
	printf("calloc ile olusan dizinin elemanlari\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\n", dizi3[i]);
	}
	printf("elemanlari dolduralim\n");
	for (int i = 0; i < 10; i++) {
		dizi3[i] = (i + 1);
		printf("%d\n", dizi3[i]);
	}

	//*******************ADRESLE-REFERANSLACAGÝRMA****************
	printf("\n\n*****************************ADRESLE-REFERANSLACAGIRMA****************************\n");
	//fonksiyoan bir degerin adresini parametre olarak yollarsak 
	//o degiskenin orj. üzerinde iþlem yapýlýr.
	//ancak o degisken gibi adres olmadan degisken yollanirsa 
	//bilgisayar yeni bir sahte degisken yapar ve onun üzerinde islemler yapilip sonuc bulunur
	//orj. degiskenin degeri aynen kalir.
	// ----------- OLUSTURULAN FONKSÝYON EN USTTE MAÝNÝN DISINA KONULMUSTUR.-------------
	int gonderilensayi1 = 2;
	printf("gonderilensayi1 = %d\n", gonderilensayi1);
	int* gonderilensayi2 = 4;
	printf("gonderilensayi2 = %d\n", gonderilensayi2);
	int* gonderilenadres = &gonderilensayi2;
	printf("sayi1 kopyalanarak yani referansla gonderildi.\nsayi2 adresle gonderildi.\n");
	hesapla(gonderilenadres, gonderilensayi1);
	printf("gonderilensayi1 = %d\n", gonderilensayi1);
	printf("gonderilensayi2 = %d\n", gonderilensayi2);

	//*************************SIZEOF-KULLANIMI**************************
	printf("\n\n******************************SIZEOF-KULLANIMI*****************************\n");
	int dizi4[4] = { 01,32,06,80 };
	int* adrress = dizi4;
	printf("dizinin uzunlugu = %lu\n", sizeof(dizi4));
	printf("pointerýn uzunlugu = %lu\n", sizeof(adrress));
	printf("pointerin icindeki adreste bulunan degerin uzunlugu = %lu\n", sizeof(*adrress));
	
	//normalde &dizi[0] ile dizi ayný anlama gelir 
	//iki istisna haric:
	printf("dizi ile yazdirirsak = %lu\n", sizeof(dizi4));
	printf("&dizi[0] ile yazdirirsak = %lu\n", sizeof(&dizi[0]));
	printf("dizi[0] ile yazdirirsak = %lu\n", sizeof(dizi[0]));
}


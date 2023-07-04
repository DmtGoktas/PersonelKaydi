/*
 * structOrn.c
	kullanıcıdan kaç personel kaydı yapılacağı bildgisini al.
	girilen sayı kadar kullanıcıdan personel bilgisini alıp her personeli
	persons adlı bir dizide biriktir.
	sonra bu dizideki her kişinin bilgilerini ekrana bas.
	
 */


#include <stdio.h>
#include <stdlib.h>

struct Person{
	char isim[60];
	char cinsiyet;
	int yas;
	int kilo;
	int boy;
};

struct Person **persons = NULL;
struct Person *getPerson(void);
void printPerson(struct Person *pp
);

int main(int argc, char **argv)
{

	size_t sz_persons;
	
	printf("kac kullanici girilecegini belirleyiniz:");
	scanf("%dl",&sz_persons);
	
	persons = (struct Person **)malloc(sizeof(struct Person *) * sz_persons);
	
	for(int i = 0; i < sz_persons; i++)
	{
		persons[i] = getPerson();
	}
	
	for(int i = 0; i < sz_persons; i++)
	{
		printPerson(persons[i]);
		
		free(persons[i]);
	}
	free(persons);
	return 0;
}

struct Person *getPerson(void)
{
	struct Person *buff;
	
	buff = (struct Person *)malloc(sizeof(struct Person));
	
	printf("\nisim>> ");
	scanf("%29s", buff->isim);
	fflush(stdin);
	printf("cinsiyet>> ");
	scanf("%c", &buff->cinsiyet);
	printf("yas>> ");
	scanf("%d", &buff->yas);
	printf("kilo>> ");
	scanf("%d",&buff->kilo);
	printf("boy>> ");
	scanf("%d",&buff->boy);

	return buff;
}
void printPerson(struct Person *pp)
{
	printf("Ad Soyad :%s\n",pp->isim);
	printf("cinsiyet E/K :%c\n",pp->cinsiyet);
	printf("Yas :%d\n",pp->yas);
	printf("Boy :%d\n",pp->boy);
	printf("Kilo:%d\n",pp->kilo);
}

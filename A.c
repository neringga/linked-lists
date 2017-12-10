//Neringa Geigalaite
//n6. Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo didžiausią
//elementą.
//sukurti sarasa, ideti elementa, isimti elementa, spausdinti
//su switch
//visos funkcijos turi grazinti klaidos koda
//sukurk = tik ten gali null
//gali turi buti vienas kad pakaortutu meniu
//KLAIDOS, HEAD KAI KUR BE 2 ZV, SPAUSDINTI GALIMA IR NEPKAKEITUS

#include <stdio.h>
#include <stdlib.h>

struct el {
	int data;
	struct el *next;
	};
	
typedef struct el LIST;

void create_the_list(LIST **);
void insert_element(LIST **,int );
void delete_max(LIST **);
void display_list(LIST *);
void delete_element(LIST **, int);
void delete_list(LIST **);

int main () {
	LIST *head;
	int n;
	int nr;
	int m;
	int created = 0;
	
	printf("Galimybes:\n1 Sukurti sarasa\n2 Iterpti elementa\n3 Isimti elementa\n4 Isimti max elementa\n5 Spausdinti sarasa\n6 Istrinti sarasa\n7 Pakartoti meniu\nNorint uzbaigti ivesti 0\n");
	
	while (n != 0) {
		scanf ("%d", &n);
	
		switch (n) {
			case 1:
			create_the_list (&head);
			break;
		
			case 2:
			printf ("Iveskite elementa: ");
			scanf ("%d", &m);
			insert_element (&head, m);
			break;
		
			case 3:
			printf ("Iveskite elemento, kuri norite istrinti, eiles nr.: ");
			scanf ("%d", &nr);
			delete_element (&head, nr);
			break;
		
			case 4:
			delete_max (&head);
			break;
			
			case 5:
			display_list (head);
			break;
			
			case 6:
			delete_list (&head);
			break;
			
			case 7:
			printf ("Galimybes:\n1 Sukurti sarasa\n2 Iterpti elementa\n3 Isimti elementa\n4 Isimti max elementa\n5 Spausdinti sarasa\n6 Istrinti sarasa\n7 Pakartoti meniu\nNorint uzbaigti ivesti 0\n");
			break;
		}
		
	}
	
	return 0;
}

void create_the_list(LIST **head) {   								 //funkcija, kuri sukuria sarasa
	*head = NULL;	
}

void insert_element(LIST **head, int n) {
	LIST *temp;
	LIST *p;
	
	temp=(LIST *)malloc(sizeof(LIST));
	temp->data = n;
	temp->next = NULL;
		
		if (*head == NULL) {
			*head = temp;
		}
		else {
			p = *head;
			
			while (p->next != NULL) {
				p = p->next;
			}
			
			p->next = temp;
		}
		
}

void delete_element(LIST **head, int n) {     							//funkcija, kuri panaikina didziausia elementa is saraso
	LIST *temp;
	LIST *p = *head;
	int i;
	int elements = 0;
	
	printf ("dar ok1");
	while ( (p->next != NULL) && (p != NULL)) {							//skaiciuoju, kiek elementu yra ivesta sarase
		printf ("dar ok2");
		p = p->next;
		elements++;
	}
	printf ("dar ok3");
	printf("\n%d", elements);
	
	if (n > (elements+1)) {									//tikrinu ar vartotojo norimas istrinti elemento nr nera didesnis nei is viso yra elementu
		return ;
	}
	
	p = *head;
	
	if (n == 0) {													//jeigu elementas yra pirmas sarase - isskirtinis atvejis
		*head = p->next;
		free(p);
	}
	else {
		
		for (i = 0; i<n-1; i++) {
			p = p->next;
		}
		
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	
}

void delete_max (LIST **head) {  										//funkcija, kuri randa didziausio elemento sarase eiles nr
	LIST *p = *head;
	int max = p->data;
	int i;
	int max_position = 0;

	while (p != NULL) {	
	
		if (max < (p->data)) {
			max = p->data;
		}
		
		p = p->next;
	}
	
	p = *head;                      								//pagal rasta max randamas jo eiles nr sarase
	
	while ((p->data) != max) {
		max_position++;
		p = p->next;
	}
	
	delete_element(head, max_position);
	
}

void display_list(LIST *head) {            	 						//funkcija, kuri spausdina pertvarkyta sarasa

	if (head == NULL) {
		printf("Sarasas nesukurtas");
	}
	else {
		
		while (head != NULL) {
			printf ("\n%d", head->data);
			head = head->next;
		}
			
	}
	
	printf("\n");	
}

void delete_list(LIST **head) {
	
	while (*head != NULL) {
		*head = (*head)->next;
		free (*head);
	}
	
}

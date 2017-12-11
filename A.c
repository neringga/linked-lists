//Neringa Geigalaite
//n6. Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo didžiausią
//elementą.

#include <stdio.h>
#include <stdlib.h>

struct el {
	int data;
	struct el *next;
	};
	
typedef struct el LIST;

void create_the_list(LIST **);
void insert_element(LIST **,int );
void delete_max(LIST **, int *);
void display_list(LIST *);
void delete_element(LIST **, int , int *);
void delete_list(LIST **);

int main () {
	LIST *head;
	int n;
	int nr;
	int m;
	int created = 0;
	int mistake = 0;
	int mistake1 = 0;
	
	printf("1 Create list\n2 Insert element\n3 Delete element\n4 Delete max element\n5 Print list\n6 Delete list\n7 Repeat meniu\n0 for escape\n");
	
	while (n != 0) {
		scanf ("%d", &n);
	
		switch (n) {
			case 1:
			create_the_list (&head);
			break;
		
			case 2:
			printf ("Insert element: ");
			scanf ("%d", &m);
			insert_element (&head, m);
			break;
		
			case 3:
			printf ("Insert number of the element that you want to delete: ");
			scanf ("%d", &nr);
			delete_element (&head, nr, &mistake);
			
			if (mistake == 1) {
				printf("No element to delete\n");
			}
			
			break;
		
			case 4:
			delete_max (&head, &mistake1);
			
			if (mistake1 == 1) {
				printf("Max element can't be deleted\n");
			}
			
			break;
			
			case 5:
			display_list (head);
			printf("\n");
			break;
			
			case 6:
			delete_list (&head);
			break;
			
			case 7:
			printf("1 Create list\n2 Insert element\n3 Delete element\n4 Delete max element\n5 Print list\n6 Delete list\n7 Repeat meniu\n0 for escape\n");
			break;
		}
		
	}
	
	return 0;
}

void create_the_list(LIST **head) {   								 //function to create the list
	*head = NULL;	
}

void insert_element(LIST **head, int n) {							//function to insert element to the end of the list
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

void delete_element(LIST **head, int n, int *mistake) {     			//function that deletes max element
	LIST *temp;
	LIST *p = *head;
	int i;
	int elements = 0;
	
	if (p == NULL) {
		*mistake = 1;
		return;
	}
	
	while ( (p->next != NULL) ) {
		p = p->next;
		elements++;
	}
	
	if (n > (elements+1)) {									//checking if the element is in the list
		*mistake = 1;
		return;
	}
	
	p = *head;
	
	if (n == 0) {													//if the element is first in the row
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

void delete_max (LIST **head, int *mistake1) {  							//function that deletes max element
	LIST *p = *head;
	int max;
	int i;
	int max_position = 0;
	
	if (p == NULL) {
		*mistake1 = 1;
		return;
	}
	
	max = p->data;

	while (p != NULL) {	
	
		if (max < (p->data)) {
			max = p->data;
		}
		
		p = p->next;
	}
	
	p = *head;                      								
	
	while ((p->data) != max) {
		max_position++;
		p = p->next;
	}
	
	delete_element(head, max_position, &mistake1);
}

void display_list(LIST *head) {            	 						//function to display list
		
		while (head != NULL) {
			printf ("\n%d", head->data);
			head = head->next;
		}
	
}

void delete_list(LIST **head) {										//function to delete list
	
	while (*head != NULL) {
		*head = (*head)->next;
		free (*head);
	}
	
}

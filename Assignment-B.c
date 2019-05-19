
#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
	int number;

	struct linkedlist* next;

} linkedlist;

void insert(struct linkedlist *);

struct linkedlist * head = NULL;

void main(int argch, char * argh[]){


if (argch<3)
	{
		printf("Please run as %s [filename]", argh[0]);
		return;
	}
    FILE *fi;
    FILE *wi;
    if (!(fi = fopen(argh[1], "r")))
	{
		printf("File %s does not exist", argh[1]);
		return;
	}

    struct linkedlist * node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
	if (node==NULL)
	{
		printf("Cannot do dynamic memory management");

		return;
	}

    printf("file content in %s:\n", argh[1]);
    wi = fopen(argh[2],"wi");


	while (fscanf(fi, "%d", &(node->number) )!=EOF)
	{
	
        node->next = NULL;
        insert(node);
        node = (struct linkedlist*) malloc(sizeof(struct linkedlist));

		if (node==NULL)
		{
			printf("Cannot do dynamic memory management");

			return;
		}

	}
    free(node);


	printf("content in the linked list\n");
    	while (head!=NULL)
	{
		node = head;
		head = head->next;

		printf("%d\n", node->number);
        fprintf(wi,"%d ",node->number);
        free(node);
			
	}
    	
    fclose(fi);
    fclose(wi);  
}


void insert(struct linkedlist * element)
{
	printf("inset");
	struct linkedlist * temp = head;
	struct linkedlist * pretemp = NULL;

	while (temp != NULL && temp->number < element->number)
	{
		pretemp = temp;
		temp = temp->next;
	}


	if (pretemp==NULL)
	{
		
		element->next = head;
		head = element;
	}
	else
	{
	
		pretemp->next = element;
		element->next = temp;
	}
}

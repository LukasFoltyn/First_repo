#include <stdio.h>
#include <stdlib.h>



typedef struct brack_list{
	char zavorka;
	struct brack_list *next;
	}brack_list;

typedef struct beginning{
	struct brack_list *head;
	}beg_list;

void pop(beg_list *zacatek);
brack_list *create_slot(char bracket);
void push(char bracket, beg_list *zacatek);
char top(beg_list *zacatek);
int listEmpty(beg_list *zacatek);
void print_list(beg_list *zacatek);

int main()
{
	beg_list zacatek;
	zacatek.head = NULL;
	char znak;
	while(scanf("%c", &znak) == 1)
	{
		if(znak == '{' || znak == '(' || znak == '[')
		{	
			push(znak, &zacatek);
		
		}
		else if(znak == '}' || znak == ')' || znak == ']')
		{
			if(listEmpty(&zacatek) || znak != top(&zacatek)) 
			{
				fprintf(stderr,"Error with parentheses\n");
				return 1;
			}
			else
				pop(&zacatek);
		}
	}
	if(listEmpty(&zacatek))	
		printf("The file is OK!\n");
	else	
	{	
		fprintf(stderr,"Error with parentheses\n");
		return 1;
	}
	return 0;
}
void print_list(beg_list *zacatek)
{
	brack_list *temp = zacatek->head;
	while(temp != NULL)
	{
		printf("Zavorka je %c\n", temp->zavorka);
		temp=temp->next;
	}
}
void pop(beg_list *zacatek)
{
	brack_list *temp = zacatek->head;
	zacatek->head = zacatek->head->next;
	free(temp);
}
brack_list *create_slot(char bracket)
{
	brack_list *new;
	new = malloc(sizeof(struct brack_list));
	if(new != NULL)
	{
		if(bracket == '(')
			new->zavorka = bracket+1;
		else
			new->zavorka = bracket+2;
		new->next = NULL;
		return new;
	}
	else
		return NULL;
}

void push(char bracket, beg_list *zacatek)
{
	if(zacatek->head == NULL)
		zacatek->head = create_slot(bracket);
	else
	{	
		brack_list *new = create_slot(bracket);
		if(new != NULL)
		{	
			brack_list *temp = zacatek->head;
			zacatek->head = new;
			new->next = temp;
		}
		else
		{
			fprintf(stderr, "Problem with allocation\n");
			return;
		}
	}
}
char top(beg_list *zacatek)
{
	return zacatek->head->zavorka;
}
int listEmpty(beg_list *zacatek)
{
	if(zacatek->head != NULL)
		return 0;
	else
		return 1;
}


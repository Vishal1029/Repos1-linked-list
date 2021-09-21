#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void CreateCLL()
{
	struct node*temp,*newnode;
	int choice = 1;
	printf("Create a circular linklist ^~^\n");
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0)
		{
			head = temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		temp->next=head;
		printf("Do U want to continue 1/0 : ");
		scanf("%d",&choice);
	}

	printf(")\n");
}

Display()
{
	struct node*temp,*newnode;
	int count=1;
	if(head==0)
	{
		printf("\nList is Empty *~* ");
	}
	else
	{
		temp=head;
		printf("\nCreated Circular Linklist : ");
		while(temp->next!=head)
		{
			printf("%d->",temp->data);
			temp = temp->next;
			count++;
		}
		printf("%d",temp->data);
	}
}
InsertatBeg()
{
	struct node*temp,*newnode,*tail;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(tail==0)
	{
		tail = newnode;
		tail->next=newnode;
	}
	else
	{
		newnode->next=tail->next;
		tail->next=newnode;
	}
	
}

int main()
{
	CreateCLL();
	Display();
	InsertatBeg();
	Display();	
	return 0;
}

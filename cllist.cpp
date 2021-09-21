#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*tail;
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
	printf("\nFor Conformation list starts From : (%d",temp->next->data);
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
	struct node*temp,*newnode;
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
	Display();
}

InsertatEnd()
{
	struct node*temp,*newnode;
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
		tail=newnode;
	}
	Display();
}

InsertatPos()
{
	struct node*temp,*newnode;
	int pos,i=1,l;
	printf("Enter the position : ");
	scanf("%d",&pos);
	l=10;
	if(pos<0||pos>l)
	{
		printf("Invalid Position *~* ");
	}
	else if(pos==1)
	{
		InsertatBeg();
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data : ");
	    scanf("%d",&newnode->data);
	    newnode->next=0;
	    temp=temp->next;
	    while(i<pos-1)
	    {
	    	temp=temp->next;
	    	i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
int main()
{
	CreateCLL();
	Display();
	InsertatBeg();
	Display();	
	InsertatEnd();
	Display();	
	InsertatPos();
	Display();
	return 0;
}        

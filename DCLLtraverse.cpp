#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*tail;
void CreateDLL()
{
	struct node*newnode;
	int choice= 1;
	head=0;
	printf("Create a Doubly Circular linklist ^~^\n");
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0)
		{
			head=tail=newnode;
			head->next=head;
			head->prev=head;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			newnode->next=head;
			head->prev=newnode;
			tail=newnode;
		}
		printf("Do U want to continue 1/0 : ");
		scanf("%d",&choice);
	}
	printf("\nFor Conformation list :  \tStarts From : (%d",tail->next->data);
	printf(")\tAnd End At : (%d",tail->data);
	printf(")\n");
}

Display()
{
	struct node*temp;
	int count=1;
	temp = head;
	printf("\nCreated a Doubly Circular linklist : ");
	while(temp!=tail)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		count++;
	}
	printf("%d",temp->data);
	printf("\nTotal no. of nodes : %d",count);
}
//count the no. of nodes
int Getcount(struct node *head)
{
	// Base case 
    if(head==0)
    return 0;
    //count is 1 + count of remaining list
    return 1+Getcount(head->next);
}
int main()
{
	CreateDLL();
	Display();
	return 0;
}

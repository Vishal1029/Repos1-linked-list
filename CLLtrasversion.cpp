#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*tail,*temp,*newnode;
void CreateCLL()
{
	int choice = 1;
	printf("Create a circular linklist ^~^\n");
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(tail==0)
		{
			tail=newnode;
			tail->next=newnode;
		}
		else
		{
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
		}
		printf("Do U want to continue 1/0 : ");
		scanf("%d",&choice);
	}
	printf("\nFor Conformation list starts From : (%d",tail->next->data);
	printf(")\n");
}
Display()
{
	int count=1;
	if(tail==0)
	{
		printf("\nList is Empty *~* ");
	}
	else
	{
		temp=tail->next;
		printf("\nCreated Circular Linklist : ");
		while(temp->next!=tail->next)
		{
			printf("%d->",temp->data);
			temp = temp->next;
			count++;
		}
		printf("%d",temp->data);
		printf("\nCount Value : %d",count);
	}
}
int main()
{
	CreateCLL();
	Display();
	return 0;
}

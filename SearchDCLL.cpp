#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*tail;
void CreateDCLL()
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
Searching()
{
	struct node*temp;
	int num,cho=1,coun=1;
	temp=head;
	while(cho==1)
	{
		printf("\nWhich Element You Want to Search : ");
		scanf("%d",&num);
		printf("element is : %d",num);
		while(temp!=0)
		{
			if(temp->data==num)
			{
				printf("\nSuccess'~'\nElement is found at Position :%d",coun);
				break;
			}
			temp=temp->next;
			coun++;
		}	
		printf("\nDo You want to Search any Element 0/1 : ");
		scanf("%d",&cho);
	}
}
int main()
{
	CreateDCLL();
	Display();
	Searching();
	return 0;
}

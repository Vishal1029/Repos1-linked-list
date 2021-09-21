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
	CreateCLL();
	Display();
	Searching();
	return 0;
}

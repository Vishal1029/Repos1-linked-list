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
	printf("Create a Doubly linklist ^~^\n");
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(tail==0)
		{
			head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
		printf("Do U want to continue 1/0 : ");
		scanf("%d",&choice);
	}

}

Display()
{
	struct node*temp;
	int count=1;
	temp = head;
	printf("\nCreated a Doubly linklist : ");
	while(temp->next!=0)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		count++;
	}
	printf("%d",temp->data);
	printf("\nTotal no. of nodes : %d",count);
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
	CreateDLL();
	Display();
	Searching();
	return 0;
}       

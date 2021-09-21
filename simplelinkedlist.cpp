#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
	struct node
{
	int data;
	struct node *link;
};
	struct node *head,*newnode,*temp;



	int choice = 1;
	int count=1;
	void create() 
{
    do
    {
		head = 0;
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->link = 0;
		if(head == 0)
		{
			head = temp = newnode;
		}
		else
		{
			temp->link = newnode;
			temp = newnode;
		}
		printf("Do you want to continue 0/1 ?");
		scanf("%d",&choice);
		
	}
    while(choice==1);
}
void display()
{ 
	temp = head;
	while(temp->link!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("%d->",temp->data);	
	printf("NULL\n");
	printf("Total no. of nodes : %d",count);
	
}
int main()
{
    create();
    display();
    return 0;
}

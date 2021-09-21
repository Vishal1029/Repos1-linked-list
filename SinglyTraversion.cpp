#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
	struct node
	{
		int data;
		struct node *link;
	};
	struct node *head,*newnode,*temp;
	head = 0;
	int choice = 1;
	int count=0;
    while(choice)
	{
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
        if(choice==1)
        {
            continue;
        }
        else
        {
            break;
        }
	} 
	temp = head;
	printf("List is : ");
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("Null");
	printf("\nTotal no. of nodes : %d",count);
		return 0;
}

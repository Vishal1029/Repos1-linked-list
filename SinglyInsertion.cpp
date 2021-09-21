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
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("NULL\n");
	printf("Total no. of nodes : %d",count);


	//here display the link list is complete.
	// insert at beginning is start from here.
	int count1=count+1;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data U want to insert at begin : ");
	scanf("%d",&newnode->data);
	newnode->link = head;
	head = newnode;
	temp = head;
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("NULL\n");
	printf("Total no. of nodes : %d",count1);


	//here display the instert at beginning link list is complete.
	// insert at ending is start from here.
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data U want to insert at end : ");
	scanf("%d",&newnode->data);
	newnode->link = 0;
	temp =head;
	while(temp->link!=0)
	{
	 	temp = temp->link;
    }
	temp->link=newnode;
		temp = head;
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("NULL\n");
	printf("Total no. of nodes : %d",count1+1);

	//here display the insert at ending link list is complete.
	// insert at after a given location is start from here.
	int pos,i=1;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the position after which U insert at  : ");
	scanf("%d",&pos);
	if(pos>count+1)
	{
		printf("invalid Position '~' ");
	}
	else
	{
		temp=head;
		while(i<pos)
		{
			temp=temp->link;
			i++;
		}
		printf("\nEnter the data U want to insert at  : ");
	    scanf("%d",&newnode->data);
	    newnode->link=temp->link;
	    temp->link=newnode;
	    temp=head;
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("NULL\n");
	printf("Total no. of nodes : %d",count1+2);
	}
	return 0;
}

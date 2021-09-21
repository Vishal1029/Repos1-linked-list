#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
	struct node
	{
		int data;
		struct node *link;
	}*temp,*head,*newnode;
CreateLL()
{
	head = 0;
	int choice = 1;
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
}
Display()
{
	int count=0;
	temp = head;
	printf("\nList is : ");
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	}
	printf("NULL");
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
			}
			temp=temp->link;
			coun++;
		}	
		printf("\nDo You want to Search any Element 0/1 : ");
		scanf("%d",&cho);
	}
}
int main()
{
	CreateLL();
	Display();
	Searching();
	return 0;
}

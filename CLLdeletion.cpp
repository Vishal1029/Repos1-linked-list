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

DeleteFromBeg()
{
	temp=temp->next;
	if(tail==0)
	{
		printf("\nList is Empty '~' ");
	}
	else if(temp->next==temp)
	{
		tail=0;
		free(temp);
	}
	else
	{
		tail->next=temp->next;
		free(temp);
	}
}

DeleteFromEnd()
{
	struct node *current,*previous;
	current=tail->next;
	if(tail==0)
	{
		printf("\nList is Empty '~' ");
	}
	else if(current->next==current)
	{
		tail=0;
		free(current);
	}
	else
	{
		while(current->next!=tail->next)
		{
			previous=current;
			current=current->next;
		}
		previous->next=tail->next;
		tail=previous;
		free(current);
	}
}

DeleteAtPos()
{
    struct node*current,*nextnode;
	int pos,i=1,l;
	printf("Enter the position : ");
	scanf("%d",&pos);
	l=20;
	if(pos<1||pos>l)
	{
		printf("Invalid Position *~* ");
	}
	else if(pos==1)
	{
		DeleteFromBeg();
	}
	else
   	{
   		current=tail->next;
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    	}
	Display();
}

DeleteNode()
{
    int choice1=1,choice=1;
    while(choice)
    {
	
   	    printf("\nWant do Delete something ^~^ ");
    	printf("\n1. Delete at beg : \n2.Delete  at end : \n3. Delete at specified Position : \n");
        scanf("%d",&choice1);
        switch(choice1)
        {
        	case 1:
        		DeleteFromBeg();
        		Display();
            	break;
            case 2:
            	DeleteFromEnd();
            	Display();
	            break;
			case 3:
				DeleteAtPos();
			    break;
		}
		printf("\nDo U want to continue 1/0 : ");
    	scanf("%d",&choice);
	}
}

int main()
{
	CreateCLL();
	Display();
	DeleteNode();
	Display();
	return 0;
}           

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*newnode,*tail,*temp;
void CreateDCLL()
{
	int choice= 1;
	head=0;
	printf("Create a Doubly linklist ^~^\n");
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
DeleteFromBeg()
{
	temp=head;
	if(head==0)
	{
		printf("\nList is Empty '~' ");
	}
	else if(temp->next==temp)
	{
		head=tail=0;
		free(temp);
	}
	else
	{
		head=head->next;
		head->prev=tail;
		tail->next=head;
		free(temp);
	}
}

DeleteFromEnd()
{
	temp=tail;
	if(tail==0)
	{
		printf("\nList is Empty '~' ");
	}
	else if(tail->next==tail)
	{
		head=tail=0;
		free(temp);
	}
	else
	{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
		free(temp);
	}
}
int Getcount(struct node *head)
{
	// Base case 
    if(head==0)
    return 0;
    //count is 1 + count of remaining list
    return 1+Getcount(head->next);
}
DeleteAtPos()
{
	temp=head;
	int pos,i=0;
	printf("Enter the position : ");
	scanf("%d",&pos);
	int l=Getcount(head);
	if(pos<1||pos>l)
	{
		printf("Invalid Position *~* ");
	}
	else if(pos==1)
	{
		DeleteFromBeg();
	}
	else if(pos==l)
	{
		DeleteFromEnd();
	}
	else
   	{
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->next->prev;
        free(temp);
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
	CreateDCLL();
	Display();
	DeleteNode();
	Display();
	return 0;
}           

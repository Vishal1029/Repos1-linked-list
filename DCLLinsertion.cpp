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
int Getcount(struct node *head)
{
	// Base case 
    if(head==0)
    return 0;
    //count is 1 + count of remaining list
    return 1+Getcount(head->next);
}
InsertatBeg()
{
	struct node*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=tail;
		tail->next=newnode;
		head=newnode;
	}
	Display();
}

InsertatEnd()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
	}
	else
	{
		newnode->prev=tail;
		tail->next=newnode;
		newnode->next=head;
		head->prev=newnode;
		tail=newnode;
	}
	Display();
}

InsertatPos()
{
	struct node*temp;
	temp=head;
	int pos,l,i=1;
	printf("Enter the Position : ");
	scanf("%d",&pos);
	l=Getcount(head);
	if(pos<1||pos>l)
	{
		printf("\nInvalid Position *~*");
	}

	else if(pos==1)
	{
		InsertatBeg();
	}
	else if(pos==l)
	{
		InsertatEnd();
	}
	else
	{
		newnode->next=0;newnode->prev=0;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data  : ");
		scanf("%d",&newnode->data);
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
	}
}
InsertNode()
{ 
    int choice1=1,choice2 = 1;;
   	printf("\nWant do Insert something ^~^ ");
   	while(choice2)
	{
    	printf("\n1. Insert at beg : \n2. Insert at end : \n3. Insert at specified Position : \n4. Not want to Insert anything : \n");
        scanf("%d",&choice1);
        switch(choice1)
        {
        	case 1:
        		InsertatBeg();
            	break;
            case 2:
            	InsertatEnd();
	            break;
			case 3:
				InsertatPos();
			    break;
			case 4:
				break; 	
		}
     	printf("\nDo U want to continue 1/0 : ");
    	scanf("%d",&choice2);
	}
}
int main()
{
	CreateDCLL();
	Display();
	InsertNode();
	Display();	
	return 0;
}

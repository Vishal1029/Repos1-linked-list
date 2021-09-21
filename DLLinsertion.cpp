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
//count the no. of nodes
int Getcount(struct node *head)
{
	// Base case 
    if(head==0)
    return 0;
    //count is 1 + count of remaining list
    return 1+Getcount(head->next);
}
InsertAtBeg()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;newnode->prev=0;	
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
}
InsertAtEnd()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;newnode->prev=0;	
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
}
InsertAtPos()
{
	struct node*newnode;
	int pos,i=1,l;
	printf("Enter the position : ");
	scanf("%d",&pos);
	l=Getcount(head);
	if(pos<1||pos>l)
	{
		printf("Invalid Position *~* ");
	}
	else if(pos==1)
	{
		InsertAtBeg();
	}
	else if (pos==l)
	{
		InsertAtEnd();
	}
	else
	{
		struct node*temp;
		temp=head;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data : ");
	    scanf("%d",&newnode->data);
	    while(i<pos-1)
	    {
	    	temp=temp->next;
	    	i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
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
        		InsertAtBeg();
        		Display();
            	break;
            case 2:
            	InsertAtEnd();
            	Display();
	            break;
			case 3:
				InsertAtPos();
				Display();
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
	CreateDLL();
	Display();
	InsertNode();
	Display();
	return 0;
}       

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


DeleteAtBeg()
{
	struct node*temp;
	if(head==0)
	{
		printf("List is Empty *~* ");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=0;
		free(temp);
	}
}
DeleteAtEnd()
{
	struct node*temp;
	if(tail==0)
	{
		printf("List is Empty *~* ");
	}
	else
	{
		temp=tail;
		tail->prev->next=0;
		tail=tail->prev;
		free(temp);
	}
}
DeleteAtPos()
{
	struct node*temp;
	int pos,i=1,l;
	temp=head;
	printf("Enter the position : ");
	scanf("%d",&pos);
	l=Getcount(head);
	if(pos<1||pos>l)
	{
		printf("Invalid Position *~* ");
	}
	else if(pos==1)
	{
		DeleteAtBeg();
	}
	else if(pos==l)
	{
		DeleteAtEnd();
	}
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
}
DeleteNode()
{ 
    int choice1=1,choice2 = 1;;
   	printf("\nWant do Insert something ^~^ ");
   	while(choice2)
	{
    	printf("\n1. Delete at beg : \n2. Delete at end : \n3. Delete from specified Position : \n4. Not want to Delete anything : \n");
        scanf("%d",&choice1);
        switch(choice1)
        {
        	case 1:
        		DeleteAtBeg();
        		Display();
            	break;
            case 2:
            	DeleteAtEnd();
            	Display();
	            break;
			case 3:
				DeleteAtPos();
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
	DeleteNode();
	Display();
	return 0;
}       

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

InsertatBeg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(tail==0)
	{
		tail = newnode;
		tail->next=newnode;
	}
	else
	{
		newnode->next=tail->next;
		tail->next=newnode;
	}
	Display();
}

InsertatEnd()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(tail==0)
	{
		tail = newnode;
		tail->next=newnode;
	}
	else
	{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	Display();
}

InsertatPos()
{
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
		InsertatBeg();
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data : ");
	    scanf("%d",&newnode->data);
	    newnode->next=0;
	    temp=temp->next;
	    while(i<pos-1)
	    {
	    	temp=temp->next;
	    	i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	Display();
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
	int l;
    printf("Enter the Maximum no. of Nodes for list : ");
    scanf("%d",&l);
	CreateCLL();
	Display();
	InsertNode();
	Display();
	return 0;
}           


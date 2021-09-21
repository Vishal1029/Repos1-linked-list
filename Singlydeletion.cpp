#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
	struct node *head,*newnode,*temp;
	int choice = 1;
	int count=0;
void create()
{ printf("Create a linklist ^~^ \n");
  head = 0;
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
		printf("Do you want to continue 0/1 ? ");
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
displayNode()
{
	  temp = head;
      printf("Created linklist \n");
	  while(temp!=0)
	 {
		printf("%d->",temp->data);
		temp = temp->link;
		count++;
	 }
	 	printf("NULL\n");
	    printf("\nTotal no. of nodes : %d",count);
}
deleteNode()
{   struct node *prev_node,*next_node;
    int choice1,pos,i=1;
    printf("\nWant do delete something ^~^\n1.delete at beg : \n2. delete at end : \n3.delete at specified Position : \n4. Not want to delete anything : \n");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:
            temp=head;
            head=head->link;
            free(temp);
            break;
        case 2:
            temp=head;
            while(temp->link!=0)
            {
                prev_node=temp;
                temp=temp->link;
            }
            if(temp==head)
            {
                head=0;
            }
            else
            {
                prev_node->link=0;
            }
            free(temp);
            break;
        case 3:
            temp=head;
            printf("Enter the  Position : ");
            scanf("%d",&pos);
            while(i<pos-1)
            {
                temp=temp->link;
                i++;
            }
            next_node=temp->link;
            temp->link=next_node->link;
            free(next_node);
            break;
        case 4:
            break;
    }

}

int main()
{
    create();
    displayNode();
    deleteNode();
    displayNode();
    return 0;
}

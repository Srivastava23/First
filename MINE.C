#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int insertion();
int insbeg();
int inspos();
int insend();
int deletion();
int delbeg();
int delpos();
int delend();
void display();

struct node
{
    int data;
    struct node* next;
};

struct node *head,*newnode,*temp; int i,pos,choice=1,cho,flag=1;

int main()
{
    int ch;
    while(flag==1)
    {
        printf("==>MENU<==\n");
        printf("1 Insertion\n2 Deletion\n3 Display\n4 Exit\n=>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertion();
            break;
        
            case 2: deletion();
            break;
        
            case 3: display();
            break;

            case 4: flag=0;
            break;

            default: printf("Invalid Choice\n");
        }
    }
    getch();
}

//INSERTION MENU
int insertion()
{
    int incho;
    while(flag==1)
    {
        printf("1 Beginning\n2 Specific Position\n3 End\n4 Previous Menu\n=>");
        scanf("%d",&incho);
        switch(incho)
        {
            case 1: insbeg();
            break;

            case 2: inspos();
            break;

            case 3: insend();
            break;

            case 4: return 0;
            break;

            default: printf("Invalid Choice\n");  
        }
    }

}

//INSERTION AT THE BEGINNING
int insbeg()
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data\n=>");
        scanf("%d",&newnode->data);
       
        if(head==0)
        {
            head=temp=newnode;
        }
        else 
        {
            newnode->next=head;
            head=newnode;
        }
        printf("1 to Continue\n0 to Previous Menu\n=>"); 
        scanf("%d",&cho);
        if(cho==1)
        {
            choice=1;
        }
        else if(cho==0)
        {
            break;
        }
        else printf("Invalid Choice");
    }
}


//INSERTION AT A SPECIFIC POSITION
int inspos() 
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Position\n=>");
        scanf("%d",&pos);
        printf("Enter Data\n=>");
        scanf("%d",&newnode->data);
        if (pos==0) 
        {
            newnode->next = head;
            head = newnode;
        }
        else 
        {
            temp=head; i=1;
            while(temp!=NULL && i<pos-1)
            {
                temp = temp->next;
                i++;
            }
             if(temp == NULL) 
             {
                printf("Invalid Position\n");
                free(newnode);
             }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        printf("1 to Continue\n0 to Previous Menu\n=>"); 
        scanf("%d",&cho);
        if(cho==1)
        {
            choice=1;
        }
        else if(cho==0)
        {
            break;
        }
        else printf("Invalid Choice");
    }
}

//INSERTION AT THE END
int insend()
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter Data\n=>");
            scanf("%d",&newnode->data);
            if(head==NULL)
            {
                head=temp=newnode;
            }
            else 
            {
                while(temp->next!=NULL)
                {
                    temp=temp->next;                
                }
                temp->next=newnode;
                newnode->next=NULL;
            }
        printf("1 to Continue\n0 to Previous Menu\n=>"); 
        scanf("%d",&cho);
        if(cho==1)
        {
            choice=1;
        }
        else if(cho==0)
        {
            break;
        }
        else printf("Invalid Choice");
    }

}

//DELETION
int deletion()
{
    int delcho;
    while(flag==1)
    {
        printf("Deletion From?\n");
        printf("1 Beginning\n2 Specific Position\n3 End\n4 Previous Menu\n=>");
        scanf("%d",&delcho);
        switch(delcho)
        {
            case 1: delbeg();
            break;

            case 2: delpos();
            break;

            case 3: delend();
            break;

            case 4: return 0;
            break;

            default: printf("Invalid Choice\n");  
        }
    }
}

//DELETION AT THE BEGINNING
int delbeg()
{
    if(head==0)
    {
        printf("Underflow\n");
    }    
    else
    {
        temp=head;
        printf("Deleted Element: %d\n",temp->data);
        head=temp->next;
        free(temp);
    }
}

//DELETION AT A SPECIFIC POSITION
int delpos()
{
    if(head==0)
    {
        printf("Underflow\n");
    }   
    else
    {
        struct node *prev;
        temp=head; i=1;
        printf("Enter Position\n=>");
        scanf("%d",&pos);
        if(pos==1)
        {
            printf("Deleted Element: %d\n",temp->data);
            head=temp->next;
            free(temp);
        }
        else
        {
            while(temp!=NULL && i<pos)
            {
                prev=temp;
                temp=temp->next;
                i++;
            }
            if(temp==NULL)
            {
                printf("Invalid Position\n");
            }
            else
            {
                printf("Deleted Element: %d\n",temp->data);
                prev->next=temp->next;
                free(temp);
            }
        }
    }
}

// DELETION AT THE END
int delend() 
{
    if(head==0)
    {
        printf("Underflow\n");
    }   
    else
    {
        struct node *prev;
        temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;                
        }
        printf("Deleted Element: %d\n",temp->data);
        prev->next=NULL;
        free(temp);
    }
}

//DISPLAY
void display()
{
    if(head==0)
    {
        printf("Underflow\n");
    }   
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/////////////////////////////////////////////////////////////
//
// Function name : 
// input         : integer
// Output        : integer
// Discption     : DSA
// Auther        : Tahakik Sanket Rajendra
// Date          : 13/06/2023
//
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//
// Problem Statement : Display, Count, InsertFrist and InsertLast, DeleteFrist, DeleteLast, InserAtPos, DeleteAtPos
//
/////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

struct Node
{
    int data;
    struct Node * next;
};


// 1: Allocate memory for Node
// 2: Initalise the Node
// 3: Check whether LL is empty of Not
// 4: If LL is empty store address of newNode in Frist
// 5: Otherwise store the address of newNode nside next pointer of old node
// 6: Update frist pointer with the address of new node

void InsertFrist(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE)); // 1

    newn -> data = iNo; // 2
    newn -> next = NULL;    

    if(*Head == NULL)   // 3
    {
        *Head = newn;
    }
    else    // 4
    {
        newn -> next = *Head;   // 5
        *Head = newn;   //6
    }
}

void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE)); // 1

    PNODE temp = *Head;
    newn -> data = iNo; // 2
    newn -> next = NULL;    

    if(*Head == NULL)   // 3
    {
        *Head = newn;
    }
    else    // 4
    {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        
    }

}

void Display(PNODE Head)
{
    printf("Element of LinkedList are : \n");

    while (Head != NULL)
    {
        printf("|%d| ->", Head->data);
        Head = Head -> next;
    }
    printf("NULL \n");
    
}

int Count(PNODE Head)
{
    int iCount = 0;

    while (Head != NULL)
    {
        iCount++;
        Head = Head -> next;
    }
    return iCount;
}

void DeleteFrist(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)   // LL is Empty
    {
        return;
    }
    else if((*Head) -> next == NULL)    // LL contain one node
    {
        free(*Head);
        *Head = NULL;
    }
    else    // LL contain more than one node
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)   // LL is Empty
    {
        return;
    }
    else if((*Head) -> next == NULL)    // LL contain one node
    {
        free(*Head);
        *Head = NULL;
    }
    else    // LL contain more than one node
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int iNo, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);     // Calculet length of LL
    PNODE temp = *Head;

    PNODE newn = NULL;

    // Filter
    if((iPos < 1) || (iPos > iLength + 1))  // Invalid position
    {
        printf("Invalid Position\n");
        return;
    }
    // InsertFrist
    if( iPos == 1)
    {
        InsertFrist(Head, iNo);
    }
    // InsertLast
    else if(iPos == iLength)
    {
        InsertLast(Head, iNo);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo; 
        newn -> next = NULL;    

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iLength = 0;
    PNODE temp = *Head;
    PNODE tempX = *Head;
    iLength = Count(*Head);     // Calculet length of LL
    // Filter
    if((iPos < 1) || (iPos > iLength))  // Invalid position
    {
        printf("Invalid Position\n");
        return;
    }
    // InsertFrist
    if( iPos == 1)
    {
        DeleteFrist(Head);
    }
    // InsertLast
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }

    else
    {
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        tempX = temp -> next;
        // Sequance is important
        temp -> next = temp -> next -> next;
        free(tempX);
    }
}


int main()
{
    PNODE Frist = NULL;
    
    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;

    while (1)
    {
        printf("-----------------------------------------------------------\n");

        printf("Please enter your choice : \n");

        printf("1 : Insert node at frist postion\n");
        printf("2 : Insert node at Last postion\n");
        printf("3 : Insert node at given postion\n");
        printf("4 : Delete node at frist postion\n");
        printf("5 : Delete node at last postion\n");
        printf("6 : Delete node at given postion\n");
        printf("7 : Display element of  LL \n");
        printf("8 : Count number of node LL\n");
        printf("9 : Terminate the application\n");

        printf("-----------------------------------------------------------\n");

        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the value that you want to insert : \n");
                scanf("%d",&iValue);
                InsertFrist(&Frist, iValue);
                break;
            
            case 2:
                printf("Enter the value that you want to insert : \n");
                scanf("%d", &iValue);
                InsertLast(&Frist, iValue);
                break;
            
            case 3:
                printf("Enter the value that you want to insert : \n");
                scanf("%d",&iValue);
                printf("Enter the Position : \n");
                scanf("%d", &iPosition); 
                InsertAtPos(&Frist, iValue, iPosition);
                break;
            
            case 4:
                DeleteFrist(&Frist);
                break;

            case 5: 
                DeleteLast(&Frist);
                break;

            case 6:
                printf("Enter the position : ");
                scanf("%d",&iPosition);
                DeleteAtPos(&Frist, iPosition);
                break;

            case 7:
                Display(Frist);
                break;
            
            case 8:
                printf("Count of Element is : %d\n", Count(Frist));
                break;
            
            case 9:
                printf("Thank You");
                return 0;
             
            default:
                printf("Invalid choise");
                break;
        }
        
    }
    
    return 0;
}
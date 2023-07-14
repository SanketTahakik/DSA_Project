/////////////////////////////////////////////////////////////
//
// Function name : 
// input         : integer
// Output        : integer
// Discption     : DSA
// Auther        : Tahakik Sanket Rajendra
// Date          : 29/06/2023
//
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//
// Problem Statement : C++ language DSA
//
/////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE Frist;    // characteristics
    
        int iCount;     // characteristics

    public:

        SinglyLL();
        ~SinglyLL();

        void InsertFrist(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFrist();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

// Implimentation of all behaviours

/*
    Return_value Class_Name :: Function_Name(Parametetr_List)
    {
        Function_Body;
    }
*/

void SinglyLL :: InsertFrist(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;    // newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(Frist == NULL)   // LL is empty
    {
        Frist = newn;
    }
    else    // LL contain at leat one node in it
    {
        newn -> next = Frist;
        Frist = newn;
    }
    iCount++;
}


void SinglyLL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;    // newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(Frist == NULL)   // LL is empty
    {
        Frist = newn;
    }
    else    // LL contain at leat one node in it
    {
        PNODE temp = Frist;

        while(temp -> next != NULL)
        {
            temp = temp -> next ;
        }
        temp -> next = newn;
    }
    iCount++;
}


void SinglyLL :: DeleteFrist()
{
    if(Frist == NULL)   // LL is empty
    {
        return;
    }
    else if(Frist -> next == NULL)      // LL is 
    {
        delete Frist;
        Frist = NULL;
    }
    else
    {
        PNODE temp = Frist;

        Frist = Frist -> next;
        delete temp;
    }
    iCount--;
}

void SinglyLL :: DeleteLast()
{
    if(Frist == NULL)   // LL is empty
    {
        return;
    }
    else if(Frist -> next == NULL)      // LL is 
    {
        delete Frist;
        Frist = NULL;
    }
    else
    {
        PNODE temp = Frist;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp-> next;
        temp -> next = NULL;
    }
    iCount--;
}


void SinglyLL :: Display()
{
    PNODE temp = Frist;

    cout << "Element of LL are : " << "\n";

    while(temp != NULL)
    {
        cout << " | " << temp -> data <<  " |-> ";
        temp = temp -> next;
    }
    cout << "NULL"<< "\n";
}

int SinglyLL :: Count()
{
    return iCount;
}

SinglyLL :: SinglyLL()
{
    cout << "Inside Constructor\n";

    Frist = NULL;
    iCount = 0;
}

SinglyLL :: ~SinglyLL()
{
    cout << "Inside Distructor\n";
    PNODE temp = Frist;

    for(int iCnt = 0; iCnt <= iCount; iCnt++)
    {
        temp = Frist;
        Frist = Frist -> next;
        delete temp;
    }
}


void SinglyLL :: InsertAtPos(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout << "Invalid";
        return;
    }

    if(iPos == 1)
    {
        InsertFrist(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE temp = Frist ;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        PNODE newn = new NODE;
        newn -> data = iNo;
        newn -> next = NULL;

        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid";
        return;
    }

    if(iPos == 1)
    {
        DeleteFrist();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = Frist ;
        PNODE tempX = NULL ;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp -> next;
        temp -> next = temp -> next -> next;

    }
}

/////////////////////////////////////////////////////////////////////


int main()
{
    SinglyLL obj;

    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;
    
    while(1)
    {
        cout << "--------------------------------------------------";

        cout << "Please enter your choice : \n";

        cout << "1 : Insert node at frist postion\n";
        cout << "2 : Insert node at Last postion\n";
        cout << "3 : Insert node at given postion\n";
        cout << "4 : Delete node at frist postion\n";
        cout << "5 : Delete node at last postion\n";
        cout << "6 : Delete node at given postion\n";
        cout << "7 : Display element of  LL \n";
        cout << "8 : Count number of node LL\n";
        cout << "9 : Terminate the application\n";

        cin >> iChoice;

        cout << "--------------------------------------------------";

        switch(iChoice)
        {
            case 1:
                cout << "Enter the value that you want to insert : \n";
                cin >> iValue;
                obj.InsertFrist(iValue);
                break;

            case 2:
                cout << "Enter the value that you want to insert : \n";
                cin >> iValue;
                obj.InsertLast(iValue);
                break;

            case 3:
                cout << "Enter the value that you want to insert : \n";
                cin >> iValue;
                cout << "Enter the position : ";
                cin >> iPosition;

                obj.InsertAtPos(iValue, iPosition);
                break;

            case 4:
              
                obj.DeleteFrist();
                break;
            
            case 5:
               
                obj.DeleteLast();
                break;

            case 6:
                
                cout << "Enter the position : ";
                cin >> iPosition;

                obj.DeleteAtPos(iPosition);
                break;
            
            case 7:
                obj.Display();
                break;

            case 8:
                cout << "Number of element are : " << obj.Count() << "\n";
                break;

            case 9:
                cout << "Thank You ";
                return 0;

            default:
                cout<< "Invalid Choice\n";
                break;
        }
    }

    
    return 0;
}
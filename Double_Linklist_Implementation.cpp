#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
    node *pre;
};
class Linklist
{
private:
    node *start, *current, *n;
    int node_count, position;

public:
    Linklist()
    {
        start = current = n = NULL;
        node_count = 0;
        position = 0;
    }
    void create_nodes()
    {
        if (start == NULL)
        {
            start = new node;
            cin >> start->data;
            start->pre = NULL;
            start->next = NULL;
            current = start;
            node_count++;
        }
        else
        {
            n = new node;
            cin >> n->data;
            n->pre = current;
            n->next = NULL;
            current->next = n;
            current = n;
            node_count++;
        }
    }
    void Insert_Start()
    {
        n = new node;
        cout << "\nEnter Integer:";
        cin >> n->data;
        n->pre = NULL;  
        n->next = start;
        start->pre =n;
        start = n;
        node_count++;
    }
    void Insert_Specific()
    {
        n = new node;
        node *temp;
        int data;
        cout << "\nEnter Integer:";
        cin >> n->data;
        current = n;
        node_count++;
        cout << "\nEnter Position Of Node To Inserted." << endl;
        cin >> position;
        if (position > node_count || position < 0)
        {
            cout << "\nInvalid Position" << endl;
        }
        else
        {
            current = start;
            for (int i = 1; i < position - 1; i++)
            {
                current = current->next;
            }
            temp=current->next;
            n -> pre =  current;
            current->next = n;
            n->next=temp;
        }
    }
    void Insert_End()
    {
        current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        n = new node;
        cout << "\nEnter Integer:";
        cin >> n->data;
        n->pre = current;
        n->next = NULL;
        current->next = n;
        current = n;
    }
    void Delete_Start()
    {
        node *temp = NULL;
        temp = start;
        start = start->next;
        start->pre = NULL;
        delete (temp);
    }
    void Delete_Specific()
    {
        cout << "\nEnter Position Of Node To Deleted.";
        cin >> position;
        if (position > node_count || position < 0)
        {
            cout << "\nInvalid Position" << endl;
        }
        else
        {
            current = start;
            for (int i = 1; i < position - 1; i++)
            {
                current = current->next;
            }
            node *temp = NULL;
            temp = current->next->next;
            delete (current->next);
            current->next = temp;
        }
    }
    void Delete_End()
    {
        current = start;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        node *temp = NULL;
        temp = current->next;
        current->next = NULL;
        current->pre = NULL;
        delete (temp);
    }
    void search()
    {
        int number;
        bool flag = false;
        if (start == NULL)
        {
            cout << "\nNo Node Created.\n";
        }
        else
        {
            current = start;
            cout << "\nEnter Data You want to Search: \n";
            cin >> number;
            while (current != NULL)
            {
                if (current->data = number)
                    cout << "\nValue Found : " << current->data << endl;
                	flag = true;
                	break;
            }
            current = current->next;
        }
        if (flag == false)
        {
            cout << "\nIt's not in the list\n";
        }
    }
   void display()
    {
        if (start == NULL)
        {
            cout << "No Node Created." << endl;
        }
        else
        {
            int count = 1;
            current = start;
            while (current != NULL)
            {
                cout << "Node[" << count << "] = " << current->data << endl;
                count++;
                current = current->next;
            }
        }
    } 
void printReverse()
{
    int count=1;
    //struct node *temp;
    //temp = current;
    while (current != NULL)
    {
        cout << "Node[" << count << "] = " << current->data << endl;
        current = current->pre;
        count++;
    }
    cout << endl;
}


};
int main()
{
    Linklist obj;
    cout << "\n\t   Welcome To Double Linklist\n";
    int size;
    cout << "==================================================\n";
    cout << "Enter The Size Of Linked List: ";
    cin >> size;
    cout << "==================================================\n";
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value (Integer) of Node " << i << ": ";
        obj.create_nodes();
    }
    cout << "Linked List Created Successfully..." << endl;
    system("CLS");
    int op = -1;
    int op2;
    while (op != 7)
    {
        cout << "==================================================\n";
        cout << "Linked List Operations\n";
        cout << "==================================================\n";
        cout << "Enter operation you want to perform: \n1. Traverse\n2. Inserting\n3. Deleteting\n4. Searching \n5. Print Reverse \n6. Clear Screen\n7. Exit \n";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Linked List:\n";
            obj.display();
            break;
        case 2:
            cout << "1. Insert At Start\n2. Insert At Specific Position\n3. Insert At End\n";
            cin >> op2;
            if (op2 == 1)
            {
                obj.Insert_Start();
                obj.display();
                cout << "Node Inserted Successfully....\n\n";
                break;
            }
            else if (op2 == 2)
            {
                obj.Insert_Specific();
                obj.display();
                cout << "Node Inserted Successfully....\n\n";
                break;
            }
            else
            {
                obj.Insert_End();
                obj.display();
                cout << "Node Inserted Successfully....\n\n";
                break;
            }
        case 3:
            cout << "1. Delete At Start\n2. Delete At Specific Position\n3. Delete At End\n";
            cin >> op2;
            if (op2 == 1)
            {
                obj.Delete_Start();
                obj.display();
                cout << "Node Deleted Successfully....\n\n";
                break;
            }
            else if (op2 == 2)
            {
                obj.Delete_Specific();
                obj.display();
                cout << "Node Deleted Successfully....\n\n";
                break;
            }
            else
            {
                obj.Delete_End();
                obj.display();
                cout << "Node Deleted Successfully....\n\n";
                break;
            }
        case 4:
            obj.display();
            obj.search();
            cout << "\nSearch Done Successfully....\n\n";
            break;
        case 5:
            cout << "Linked List:\n";
            obj.printReverse();
            break;
        case 6:
            system("CLS");
            break;

        default:
            break;
        }
    }
}

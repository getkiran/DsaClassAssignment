#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
public:
    Node* next;
    int data;
};

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList()
    {
        this->length = 0;
        this->head = NULL;
    }

    ~LinkedList()
    {
        cout << "LIST DELETED";
    }

    //Funtion to add value to the begining of the list.
    void addAtBegining(int data)
    {
        Node* node = new Node();
        node->data = data;
        node->next = this->head;
        this->head = node;
        this->length++;
    }
    
    //Funtion to add value to the end of the list.
    void addAtEnd(int data)
    {
        Node* temp = this->head;
        Node* node = new Node();

        node->data = data;
        node->next = NULL;

        if (this->head == NULL){
            this->head = node;
            return;
        }

        while (temp->next !=NULL)
        {
            temp = temp->next;
        }

        temp->next = node;
        this->length++;
    }

    //Funtion to check if given data valude is present in the list or not.
    //Returns false if not found and true if found.
    bool isPresent(int data)
    {
        Node* temp = this->head;

        if ( temp == NULL){
            return false;
        } else {
            while (temp->next !=NULL)
            {
                if (temp->data != data) {
                    temp = temp->next;
                    continue;
                } else {
                    return true;
                }
            }
        }
        return false;
    }

    //Funtion to delete a node which has given data.
    //Returns -1 on Error and 0 on Success.
    int DeleteData(int data)
    {
        Node* temp = this->head;
        Node* prePtr = NULL;

        if ( temp == NULL){
            return -1;
        } else {
            while (temp->next !=NULL)
            {
                if (temp->data != data) {
                    prePtr = temp;
                    temp = temp->next;
                    continue;
                } else {
                    prePtr->next = temp->next;
                    if (temp == this->head)
                    {
                        this->head = prePtr;
                    }
                    delete temp;
                    return 0;
                }
            }
        }
        return 1;
    }
    // Funtion to delete a given node.
    // Returns -1 on Error and 0 on Success.
    int DeleteNode(Node* n)
    {
        Node* temp1 = this->head;
        Node* prePtr = NULL;

        if (n == NULL || temp1 == NULL)
            return -1;

        Node* temp = n->next;

        n->next = temp->next;
        n->data = temp->data;

        delete temp;
        return 0;
    }

    //Funtion to reverse a linkded list using recursion.
    Node* ReverseRecursive(Node** head, Node* n1)
    {
        if (n1 == NULL)
            return NULL;

        if (n1->next == NULL)
        {
            *head = n1;
            return n1;
        }

        Node* node = ReverseRecursive(head, n1->next);
        node->next = n1;
        n1->next = NULL;
        return n1;
    }

    //Funtion to reverse a linkded list using 3 pointers.
    void ReverseIterative(void)
    {
        Node* p = NULL, *c = NULL, *n = NULL;
        c = this->head;

        while (c != NULL)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        this->head = p;
    }

    //Function to print the data elements in the list.
    void print()
    {
        Node* temp = this->head; 
        while (temp != NULL) { 
            cout << temp->data << "->"; 
            temp = temp->next; 
        } 
        cout<<endl;
    }
};

int main() 
{ 
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list->addAtEnd(i);      //preparing a list by adding elements at the end of the list.
    }
    cout << "Given linked list\n";
    list->print();
  
    list->ReverseRecursive(&list->head, list->head); //Reversing the linked list using recursion.
    cout << "\nReversed Linked list \n";
    list->print();

    list->addAtBegining(30);//Adding an element at the begening.
    list->print();

    list->isPresent(5) ?cout<<"5 PRESENT"<<endl: cout<<"5 NOT PRESENT"<<endl; // Check if 5 is present in the list
    list->print();
    list->isPresent(105) ?cout<<"105 PRESENT"<<endl: cout<<"105 NOT PRESENT"<<endl; // Check if 105 is present in the list
    list->print();


    list->DeleteNode(list->head->next->next->next); // Delete a node.
    list->DeleteNode(list->head);
    list->print();
    list->ReverseIterative();
    list->print();
  
    return 0; 
}

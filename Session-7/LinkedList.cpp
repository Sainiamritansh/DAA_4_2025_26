#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

// Node  *push(Node *head, int val)
// {
//     Node *newNode = new Node;
//     newNode->data = val;
//     newNode->next = NULL;

//     if(head == NULL)
//     {
//         return newNode;
//     }
    
//     Node *temp = head;
//     while(temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     return head;

// }

Node* del(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return head;
    }

    int element;
    cin >> element;

    cout<<"Enter the element you want to delete"<<endl;
    if (head->data == element)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == element)
        {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return head;
        }
        temp = temp->next;
    }

    cout << "Element not found\n";
    return head;
}

Node* insertAfterValue(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    int target, newVal;
    cout << "Enter data after which you want to insert: ";
    cin >> target;
    

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == target) {
            Node* newNode = new Node;
            cout << "Enter new value to insert: ";
            cin >> newVal;
            
            newNode->data = newVal;
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    cout << "Target value not found\n";
    return head;
}




Node *print(Node *head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<<temp->data;
        cout<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    return head;
}

int main()
{
    // Node *head = NULL;
    // int val;
    // cin>>val;

    // head = push(head,val);
    
    Node *head = new Node;
    Node *second = new Node;
    Node *Third = new Node;
    Node *Fourth = new Node;
    
    head->data = 1;
    second->data = 2;
    Third->data = 3;
    Fourth->data = 4;
    head->next = second;
    second->next = Third;
    Third->next = Fourth;
    Fourth->next = NULL;


    print(head);
    cout<<endl;
    // del(head);

    insertAfterValue(head);
    print(head);
}
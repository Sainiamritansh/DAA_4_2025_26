#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


Node* del(Node* head, int choice) {
    int target;

    if (head == NULL) {
        cout << "List empty\n";
        return NULL;
    }

    if (choice == 4) {  // Delete from beginning
        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
        return head;
    }

    if (choice == 5) {  // Delete from end
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
        return head;
    }

    if (choice == 6) {  // Delete by value
        cin >> target;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == target) {

                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = temp->prev;

                delete temp;
                return head;
            }
            temp = temp->next;
        }
        cout << "Value not found\n";
        return head;
    }

    return head;
}


Node* insert(Node* head, int choice) {
    int val, target;

    if (choice == 1) {  
        cin >> val;

        Node* newNode = new Node;
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        return newNode;
    }

    if (choice == 2) {  
        cin >> val;

        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            return newNode;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }

    if (choice == 3) {  
        cin >> target >> val;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == target) {
                Node* newNode = new Node;
                newNode->data = val;

                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != NULL)
                    temp->next->prev = newNode;

                temp->next = newNode;
                return head;
            }
            temp = temp->next;
        }
        cout << "Value not found\n";
        return head;
    }

    return head;
}

int main() {
    Node* head = NULL;
    int choice;

    while (true) {
        cout << "\n1.Insert Begin  2.Insert End  3.Insert After\n";
        cout << "4.Delete Begin  5.Delete End  6.Delete Value\n";
        cout << "7.Print  8.Exit\n";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
            head = insert(head, choice);

        else if (choice >= 4 && choice <= 6)
            head = del(head, choice);

        else if (choice == 7)
            print(head);         

        else if (choice == 8)
            break;   
               
        else
            cout << "Invalid choice\n";
    }

    return 0;
}

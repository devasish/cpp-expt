#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
} *start;

int menu() {
    int m;
    cout << endl;
    cout << "0. Quit" << endl;
    cout << "1. Create New List" << endl;
    cout << "2. Display Node" << endl;
    cout << "3. Insert At End" << endl;
    cout << "4. Insert At Start" << endl;

    cout << "Enter Your Selection: ";
    cin >> m;
    cout << endl;
    return m;
}

class LinkedList {
public:
    node* create_node();
    void create_new_list();
    void display_list();
    void insert_at_end();
    void insert_at_start();

};

node* LinkedList::create_node() {
    node* temp;
    temp = new (struct node);

    if (temp) {
        cout << "Insert Data (integer) : ";
        cin >> temp->data;
        temp->next = NULL;
        return temp;
    } else {
        cout << "Unable to create node;";
        return NULL;
    }
}

void LinkedList::create_new_list() {
    node* new_node = create_node();
    
    start = new_node;
    
    cout << "New list created." << endl;
    display_list();
}

void LinkedList::display_list() {
    node* trav;
    cout << endl;
    if (start == NULL) {
        cout << "List in empty";
    } else {
        cout << "List : [";
        trav = start;
        while (trav != NULL) {
            cout << trav->data;
            if (trav->next != NULL)
                cout << "->";
            trav = trav->next;
        }
        cout << "]";
    }

    cout << endl;

}

void LinkedList::insert_at_end() {
    node* new_node = create_node();
    node* trav;

    if (start == NULL) {
        start = new_node;
    } else {
        trav = start;

        while (trav->next != NULL) {
            trav = trav->next;
        }

        trav->next = new_node;
    }
    
    cout << "New node inserted at the end." << endl;
    display_list();
}

void LinkedList::insert_at_start() {
    node* new_node = create_node();
    
    if (start == NULL) {
        start = new_node;
    }
    else {
        new_node->next = start;
        start = new_node;
    }
    
    cout << "New node inserted at start." << endl;
    display_list();
}

int main() {
    start = NULL;
    int m = menu();
    LinkedList L;
    while (m > 0) {
        switch (m) {
            case 1:
                L.create_new_list();
                break;
            case 2:
                L.display_list();
                break;
            case 3:
                L.insert_at_end();
                break;
            case 4:
                L.insert_at_start();
                break;
        }

        m = menu();
    }

    return 0;
}
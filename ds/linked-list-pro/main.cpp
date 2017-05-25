/* 
 * File:   main.cpp
 * Author: Devasish Ghosh
 *
 * Created on 21 March, 2017, 5:04 PM
 */

#include <iostream>
#include <cstdlib>
#include "Lsort.h"
using namespace std;

struct node {
    int data;
    node* next;
} *start;

int menu() {
    int m;
    cout << endl;
    cout << "------------------------------" << endl;
    cout << "0. Quit" << endl;
    cout << "1. Create New List" << endl;
    cout << "2. Display Node" << endl;
    cout << "3. Insert At End" << endl;
    cout << "4. Insert At Start" << endl;
    cout << "5. Insert At Position [1 to N]" << endl;
    cout << "6. Insert After Element" << endl;
    cout << "7. Insert Before Element" << endl;

    cout << "11. Auto Create List" << endl;
    cout << "------------------------------" << endl;

    cout << "Enter Your Selection: ";
    cin >> m;
    cout << endl;
    return m;
}

class LinkedList {
public:
    int auto_create;
    LinkedList();
    node* create_node();
    void create_new_list();
    void display_list();
    void insert_at_end();
    void insert_at_start();
    void insert_at_position();
    void insert_after_element();
    void insert_before_element();

    void auto_create_list() {
        auto_create = 1;
        int size = 5;
        create_new_list();
        for (int i = 0; i < size; i++)
            insert_at_end();

        auto_create = 0;
        display_list();
    }

    int length();

    //void sort();

};

LinkedList::LinkedList() {
    auto_create = 0;
}

int LinkedList::length() {
    int l = 0;
    node *trav = start;

    while (trav != NULL) {
        l++;
        trav = trav->next;
    }

    return l;
}

node* LinkedList::create_node() {
    node* temp;
    temp = new (struct node);

    if (temp) {
        if (auto_create) {
            temp->data = rand() % 100 + 1;
        } else {
            cout << "Insert Data (integer) : ";
            cin >> temp->data;
        }
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
    if (!auto_create)
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

    if (!auto_create) {
        cout << "New node inserted at the end." << endl;
        display_list();
    }
}

void LinkedList::insert_at_start() {
    node* new_node = create_node();

    if (start == NULL) {
        start = new_node;
    } else {
        new_node->next = start;
        start = new_node;
    }

    cout << "New node inserted at start." << endl;
    display_list();
}

void LinkedList::insert_at_position() {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    int p, q, len = length();

    cout << "Enter Position [1 to " << len + 1 << "]:";
    cin >> p;
    q = p;

    if (p < 1) {
        cout << "Invalid Position" << endl;
        return;
    }

    int i = 0;
    node *prev_node, *next_node, *cur_node;

    prev_node = NULL;
    cur_node = start;
    next_node = start->next;
    while (++i != p && cur_node != NULL) {
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

    if (cur_node == NULL && p != len + 1) {
        cout << "Invalid position";
        return;
    }

    node* new_node = create_node();
    new_node->next = cur_node;

    if (prev_node == NULL) {
        start = new_node;
    } else {
        prev_node->next = new_node;
    }

    cout << "New node inserted at position " << q << endl;
    display_list();

}

void LinkedList::insert_after_element() {

}

void LinkedList::insert_before_element() {

}

int main(int argc, char** argv) {
    Lsort ls;
    
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
            case 5:
                L.insert_at_position();
                break;
            case 11:
                L.auto_create_list();
                break;
        }

        m = menu();
    }

    return 0;
}

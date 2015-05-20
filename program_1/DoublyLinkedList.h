/** 
 * @file DoublyLinkedList.h Declaration of a Doubly Linked List
 *
 * @brief
 *    Implementation of a Doubly Linked List used to hold
 *    song names.
 *
 * @author Jason Boutte
 * @date 2/6/14
 */

#ifndef PROGRAM1_DOUBLYLINKLIST_H_
#define PROGRAM1_DOUBLYLINKLIST_H_

#include <string>

using std::string;

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool empty();                // checks if list is empty
    void append(string&);        // appends a new node after tail
    void insertBefore(string& s);// inserts new node before current node
    void insertAfter(string& s); // inserts new node after current node
    void remove(string& s);      // removes node
    void begin();                // sets current to head
    void end();                  // sets current to tail
    bool next();                 // moves current to next node
    bool prev();                 // moves current to prev node
    bool find(string& s);        // finds node
    const string& getData();     // gets data of current node

private:
    class Node {
    public:
        Node();
        ~Node();

        void linkBefore(Node* n);// links node before
        void linkAfter(Node* n); // links node after
        
        Node* next_;             // next node
        Node* prev_;             // previous node
        string* data_;           // song name stored in string
    };

    Node* head_;                 // head node of list
    Node* tail_;                 // tail node of list
    Node* current_;              // current node of list
};

#endif // PROGRAM1_DOUBLYLINKEDLIST_H_

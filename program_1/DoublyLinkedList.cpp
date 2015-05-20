/** 
 * @file DoublyLinkedList.cpp  Implementation of Doubly Linked List
 *      
 *
 * @brief
 *    Implementation of a Doubly Linked List used to store song names
 *
 * @author Jason Boutte
 * @date 2/6/14
 */

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() 
    :   head_(NULL),
        tail_(NULL),
        current_(NULL)
{ 

}

DoublyLinkedList::~DoublyLinkedList() {
    current_ = head_;

    while (head_ != NULL) {
        head_ = head_->next_;

        delete current_;

        current_ = head_;
    }
}

/**
 * Checks if list is empty
 */
bool DoublyLinkedList::empty() {
    return (head_ == NULL);
}

/**
 * Appends a song to the list.
 *
 * Creates a new node, checks if the list is empty. If empty
 * we initialize list otherwise we append the node to the tail.
 *
 * @param s Song we're appending.
 */
void DoublyLinkedList::append(string& s) {
    // TODO adjust constructor to take string?
    Node* node = new Node();

    string* song = new string(s);

    node->data_ = song;

    if (empty()) {
        current_ = head_  = tail_ = node;
    } else {
        node->linkAfter(tail_);

        current_ = tail_ = node; // adjusts the tail and set current
    }
}

/**
 * Inserts node before current node
 *
 * Creates a new node, checks if we're at the beginning 
 * of the list. If we are we adjust the head and prepend
 * otherwise we insert the node.
 *
 * @param s Song we're inserting.
 */
void DoublyLinkedList::insertBefore(string& s) {
    Node* node = new Node();

    string* song = new string(s);

    node->data_ = song;

    if (current_->prev_ != NULL) {
        node->linkAfter(current_->prev_);
    } else {
        head_ = node;
    }

    node->linkBefore(current_);

    current_ = node;
}

/**
 * Inserts node after current node
 *
 * Creates a new node, checks if we're at the end of 
 * the list. If we are we adjust the tail and append
 * otherwise we insert the node;
 *
 * @param s Song we're inserting.
 */
void DoublyLinkedList::insertAfter(string& s) {
    Node* node = new Node();

    string* song = new string(s);

    node->data_ = song;

    if (current_->next_ != NULL) {
        node->linkBefore(current_->next_);
    } else {
        tail_ = node;
    }

    node->linkAfter(current_);

    current_ = node;
}

/**
 * Removes a node
 *
 * Finds the node containing the song. If found we check
 * if we're at the end of the list then the previous node
 * becomes the current, if we're at the beginning of the 
 * list then the next node become the current. If neither
 * exists the list is empty and we reset. If the song is
 * not found we do nothing.
 *
 * @param s Song we want to remove.
 */
void DoublyLinkedList::remove(string& s) {
    if (!empty() && find(s)) {
        if (current_->next_ != NULL) {
            Node* tmp = current_;
            
            if (tmp->prev_ != NULL) {
                tmp->prev_->next_ = tmp->next_;

                tmp->next_->prev_ = tmp->prev_;
            } else {
                head_ = tmp->next_;
                
                head_->prev_ = NULL;
            }   

            current_ = tmp->next_;

            delete tmp;
        } else if (current_->prev_ != NULL) {
            Node* tmp = current_;

            tmp->prev_->next_ = NULL;

            tail_ = current_ = tmp->prev_;

            delete tmp;
        } else {
            delete current_;

            current_ = head_ = tail_ = NULL;
        }
    }
}

/**
 * Moves the current to the head of the list
 */
void DoublyLinkedList::begin() {
    if (!empty()) {
        current_ = head_;
    }
}

/**
 * Moves the current to the tail of the list
 */
void DoublyLinkedList::end() {
    if (!empty()) {
        current_ = tail_;
    }
}

/**
 * Moves the current node to the next node.
 *
 * If the next node exists we move the current to it
 * otherwise we do nothing.
 *
 * @return true if move occurs otherwise false
 */
bool DoublyLinkedList::next() {
    if (!empty() && current_->next_ != NULL) {
        current_ = current_->next_;

        return true;
    }

    return false;
}

/**
 * Moves the current node to the previous node.
 *
 * If the previous node exists we move the current to it
 * otherwise we do nothing.
 *
 * @return true if move occurs otherwise false
 */
bool DoublyLinkedList::prev() {
    if (!empty() && current_->prev_ != NULL) {
        current_ = current_->prev_;
        
        return true;
    }
    
    return false;
}

/**
 * Finds the node containing the matching string.
 *
 * Walks through the list searching for a matching 
 * string.
 *
 * @param s Song we're searching for.
 *
 * @return true if found otherwise false
 */
bool DoublyLinkedList::find(string& s) {
    if (!empty()) {
        Node* tmp = head_;

        while (tmp != NULL) {
            if (tmp->data_->compare(s) == 0) {
                current_ = tmp;

                return true;
            }

            tmp = tmp->next_;
        }
    }

    return false;
}

/**
 * Returns the data of the current node.
 *
 * @return if list isn't empty returns string in current node.
 */
const string& DoublyLinkedList::getData() {
    if (empty()) {
        return NULL; 
    } else {
        return *(current_->data_);
    }
}

DoublyLinkedList::Node::Node()
    :   next_(NULL),
        prev_(NULL),
        data_(NULL)
{

}

DoublyLinkedList::Node::~Node() {
    delete data_;
}

/**
 * Prepends node
 *
 * @param n Node to be prepended
 */
void DoublyLinkedList::Node::linkBefore(Node* n) {
    n->prev_ = this;

    next_ = n;
}

/**
 * Appends ndoe
 *
 * @param n Node to be appended
 */
void DoublyLinkedList::Node::linkAfter(Node* n) {
    n->next_ = this;

    prev_ = n;
}

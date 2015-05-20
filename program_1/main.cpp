#include <iostream>

#include "DoublyLinkedList.h"

using std::cout;
using std::endl;

int main() {
    string s1("Song1");
    string s2("Song2");
    string s3("Song3");
    string s4("Song4");

    DoublyLinkedList list;

    list.append(s1);
    list.append(s2);
    list.append(s3);

    cout << list.getData() << endl;

    list.prev();

    cout << list.getData() << endl;
}

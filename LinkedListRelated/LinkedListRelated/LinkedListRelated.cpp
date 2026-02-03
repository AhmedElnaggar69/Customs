
#include"iostream"
#include"LinkedList.h"
#include"Stack.h"
using namespace std;

int main() {
    /*
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    Node<int>* head = node1;
    myList<int> ls(head);

    ls.insert(4, 5);

    ls.insert(5, 6);

    ls.insert(6, 7);

    ls.insert(7, 8);
    ls.push_back(9);

    ls.push_back(10);

    ls.push_front(11);
    ls.print();
    ls.erase(8);
    ls.print();
    */
    myStack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.pop();
    st.print();

    st.push(42);

    st.push(42);

    st.push(42);

    st.push(69);
    st.print();
    cout << st.top();
}

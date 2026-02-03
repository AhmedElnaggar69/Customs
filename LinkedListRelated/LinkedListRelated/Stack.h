#pragma once
#include"iostream"
#include"Node.h"
#include"LinkedList.h"

template<typename T>
class myStack {
private:
    myList<T> ls{};
public:
    void push(T val) {
        ls.push_front(val);
    }
    int top() {
        return ls.getHead()->val;
    }
    void pop() {
        Node<T>* oldHead = ls.getHead();
        if (!oldHead) return;
        Node<T>* newHead = oldHead->next;
        ls.setHead(newHead);
        delete oldHead;

    }

    bool isEmpty() {
        if (!ls.head_m) {
            return true;
        }
        return false;
    }
    void print() {
        ls.print();
    }
};


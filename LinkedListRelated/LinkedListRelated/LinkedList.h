#pragma once
#include"iostream"
#include"Node.h"
template<typename T>
class myList {
private:
    Node<T>* head_m;
    Node<T>* back_m;
public:

    myList() : head_m(nullptr), back_m(nullptr) {}

    myList(Node<T>* node) {
        head_m = node;
        Node<T>* temp = head_m;
        while (temp->next) {
            temp = temp->next;
        }
        back_m = temp;
    }

    void push_front(T val) {
        Node<T>* temp = new Node<T>(val);
        temp->next = head_m;
        head_m = temp;
    }
    void push_back(T val) {
        Node<T>* temp = new Node<T>(val);
        back_m->next = temp;
        back_m = temp;
    }
    void insert(int index, T val) {
        // 1 2 3 4 5 6
        Node<T>* node = new Node<T>(val);
        Node<T>* temp = head_m;
        int ct = 1;
        while (ct < index) {
            ct++;
            temp = temp->next;
        }
        Node<T>* after = temp->next;

        temp->next = node;
        node->next = after;
        back_m = back_m->next;
    }
    void erase(int index) {
        // 1 2 3 4
        int ct = 1;
        Node<T>* temp = head_m;
        // stop at prev
        while (ct < index) {
            temp = temp->next;
            ct++;
        }
        Node<T>* toRemove = temp->next;
        temp->next = temp->next->next;
        toRemove->next = nullptr;

    }
    void print() {
        Node<T>* temp = head_m;

        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    Node<T>* getBack() {
        return back_m;
    }
    Node<T>* getHead() {
        return head_m;
    }
    void setHead(Node<T>*newHead) {
        head_m = newHead;
    }

    ~myList() {
        Node<T>* temp = head_m;
        while (temp) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};


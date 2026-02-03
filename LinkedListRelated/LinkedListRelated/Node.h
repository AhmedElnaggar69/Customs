#pragma once
template<typename T>
struct Node {
    Node<T>* next;
    T val;
    Node(T val) {
        this->val = val;
        next = nullptr;
    }

};
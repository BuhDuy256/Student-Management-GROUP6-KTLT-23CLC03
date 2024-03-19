#pragma once

#include<iostream>

template<class T>
struct Node {
	T data;
	Node<T>* next;
    Node(T dataValue) : data(dataValue), next(nullptr) {}
	Node(T dataValue, Node<T>* nextNode) : data(dataValue), next(nextNode) {}
};
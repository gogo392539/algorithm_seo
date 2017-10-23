#pragma once
#include <iostream>

template <typename T>
class s_stack {
protected:
	struct S_Node {
		T value;
		S_Node* nextNode;
	};
	typedef S_Node* nodePtr;

private:
	int Size;
	nodePtr topNode;


public:
	s_stack();
	void push(T value);
	T pop();
	int size();
	int empty();
	T top();
	~s_stack();
};

template <typename T>
s_stack<T>::s_stack() : Size(0), topNode(NULL) {
	
}

template <typename T>
void s_stack<T>::push(T value) {
	nodePtr n_Node = new S_Node;
	n_Node->value = value;

	n_Node->nextNode = topNode;

	topNode = n_Node;
	Size++;
}

template <typename T>
T s_stack<T>::pop() {
	if (empty()) {
		return -1;
	}
	else {
		S_Node* temp = topNode;
		int data = temp->value;
		topNode = topNode->nextNode;
		Size--;
		delete temp;
		return data;
	}
}

template <typename T>
int s_stack<T>::size() {
	return Size;
}

template <typename T>
int s_stack<T>::empty() {
	if (topNode == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

template <typename T>
T s_stack<T>::top() {
	if (topNode == NULL) {
		return -1;
	}
	else {
		return topNode->value;
	}
}

template <typename T>
s_stack<T>::~s_stack() {
	while (topNode != NULL) {
		S_Node* temp = topNode;
		topNode = topNode->nextNode;
		delete temp;
	}
}
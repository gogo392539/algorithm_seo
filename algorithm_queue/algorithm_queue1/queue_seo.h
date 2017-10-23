#pragma once
#include <iostream>

template <typename T>
class s_queue {
protected:
	struct Q_Node {
		T value;
		Q_Node* r_node;
		Q_Node* l_node;
	};
	typedef Q_Node* nodePtr;

private:
	int Size;
	nodePtr head;
	nodePtr tail;

public:
	s_queue();
	~s_queue();
	T pop();
	void push(T value);
	int size();
	int empty();
	T front();
	T back();
};

template <typename T>
s_queue<T>::s_queue() : Size(0), head(nullptr), tail(nullptr) {

}

template <typename T>
s_queue<T>::~s_queue() {
	while (head != nullptr) {
		pop();
	}
}

template <typename T>
T s_queue<T>::pop() {
	T tmp;

	if (empty()) {
		return -1;
	}
	nodePtr temp = head;
	head = head->r_node;
	if (head == NULL) {
		tail = nullptr;
	}
	else {
		head->l_node = nullptr;
	}
	tmp = temp->value;
	Size--;
	delete temp;

	return tmp;
}

template <typename T>
void s_queue<T>::push(T value) {
	nodePtr data = new Q_Node;
	data->value = value;
	data->r_node = nullptr;
	data->l_node = tail;
	if (head == nullptr) {
		head = data;
	}
	else {
		tail->r_node = data;
	}
	tail = data;
	Size++;
}

template <typename T>
int s_queue<T>::size() {
	return Size;
}

template <typename T>
int s_queue<T>::empty() {
	if (Size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

template <typename T>
T s_queue<T>::front() {
	if (empty()) {
		return -1;
	}
	else {
		return head->value;
	}
}

template <typename T>
T s_queue<T>::back() {
	if (empty()) {
		return -1;
	}
	else {
		return tail->value;
	}
}
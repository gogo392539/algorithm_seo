#pragma once
#include <iostream>

template <typename T>
class s_Deque {
protected:
	struct D_Node {
		T value;
		D_Node* r_node;
		D_Node* l_node;
	};
	typedef D_Node* nodePtr;

private:
	int Size;
	nodePtr Front;
	nodePtr Back;

public:
	s_Deque();
	~s_Deque();
	void push_front(T value);
	void push_back(T value);
	T pop_front();
	T pop_back();
	int size();
	int empty();
	T front();
	T back();
};

template<typename T>
s_Deque<T>::s_Deque() : Size(0), Front(nullptr), Back(nullptr) {

}

template<typename T>
s_Deque<T>::~s_Deque() {
	while (!empty()) {
		pop_front();
	}
}

template<typename T>
void s_Deque<T>::push_front(T value) {
	nodePtr data = new D_Node;
	data->value = value;
	data->r_node = nullptr;
	data->l_node = nullptr;
	if (Back == nullptr) {
		Back = data;
	}
	else {
		data->r_node = Front;
		Front->l_node = data;
	}
	Front = data;
	Size++;
}

template<typename T>
void s_Deque<T>::push_back(T value) {
	nodePtr data = new D_Node;
	data->value = value;
	data->r_node = nullptr;
	data->l_node = nullptr;
	if (Front == nullptr) {
		Front = data;
	}
	else {
		data->l_node = Back;
		Back->r_node = data;
	}
	Back = data;
	Size++;
}

template<typename T>
T s_Deque<T>::pop_front() {
	T tmp;
	if (empty()) {
		return -1;
	}
	nodePtr temp = Front;
	Front = Front->r_node;
	if (Front == nullptr) {
		Back = nullptr;
	}
	else {
		Front->l_node = nullptr;
	}
	tmp = temp->value;
	Size--;
	delete temp;
	return tmp;
}

template<typename T>
T s_Deque<T>::pop_back() {
	T tmp;
	if (empty()) {
		return -1;
	}
	nodePtr temp = Back;
	Back = Back->l_node;
	if (Back == nullptr) {
		Front = nullptr;
	}
	else {
		Back->r_node = nullptr;
	}
	tmp = temp->value;
	Size--;
	delete temp;
	return tmp;
}

template<typename T>
int s_Deque<T>::size() {
	return Size;
}

template<typename T>
int s_Deque<T>::empty() {
	if (Size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

template<typename T>
T s_Deque<T>::front() {
	if (empty()) {
		return -1;
	}
	else {
		return Front->value;
	}
}

template<typename T>
T s_Deque<T>::back() {
	if (empty()) {
		return -1;
	}
	else {
		return Back->value;
	}
}
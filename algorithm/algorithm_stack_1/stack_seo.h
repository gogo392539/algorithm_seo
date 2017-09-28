#pragma once

template <typename T>
class s_stack {
private:
	T value;
	s_stack<T>* s_ptr;

public:
	s_stack(T value);
	void init();
	void push(T value);
	T pop();
	int size();
	bool empty();
	T top();
};
#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"sqd_deque.h"
#include"sqd_vector.h"
#include"sqd.h"
#include<typeinfo>

template<typename T>
class Stack:public SQD<T>
{
public :
	
	Stack() { impl = new sqd_list<T>; }
	Stack(int size)
	{
		if(size > 0)
			this->SIZE = size;
		impl = new sqd_list<T>;
	}
	void push(T a);
	T operator[](const int index);
	void push_front(T a) override;
	void show() override;
	void set_mode(MODE mode);
	bool is_empty() override;
	T back() override;
	T front() override;
	void pop_front() override;//delete from begin
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() const override;
	void clear()override;
	void sort()override;
	void random_push(int N,int precision = 2);
	~Stack() {}
private:
	MODE mode = list;
	int SIZE = 0;//for array
	SQD<T>*impl;
	void push_back(T a) override;
	void pop_back() override;
};


#include"stack.inc"









////////////specialization for int type
//template<>
//class Stack<int> :public SQD<int>
//{
//public:
//
//	Stack() { impl = new sqd_list<int>; }
//	Stack(int size)
//	{
//		if (size > 0)
//			this->SIZE = size;
//	}
//	int operator[](const int index);
//	void push_front(int a) override;
//	void show() override;
//	void set_mode(int mode);
//	bool is_empty() override;
//	int back() override;
//	int front() override;
//	void pop_front() override;//delete from begin
//	bool erase_from_position(int position) override;
//	bool delete_data(int a) override;
//	int size() const override;
//	void clear()override;
//	void sort()override;
//	void random_push(int N);
//private:
//	MODE mode = list;
//	int SIZE = 0;//��� ������
//	SQD<int>*impl;
//	void push_back(int a) override;
//	void pop_back() override;
//};
//
//void Stack<int>::set_mode(int mode)
//{
//	if (mode == 1)
//	{
//		impl = new sqd_list<int>;
//		this->mode = MODE::list;
//	}
//	else if (mode == 2)
//	{
//		if (SIZE > 0)
//			impl = new sqd_arr<int>(SIZE);
//		else
//			impl = new sqd_arr<int>;
//		this->mode = MODE::arr;
//	}
//	else if (mode == 3)
//	{
//		impl = new sqd_deque<int>;
//		this->mode = MODE::deque;
//	}
//	else
//	{
//		impl = new sqd_vector<int>;
//		this->mode = MODE::vector;
//	}
//}
//
//
//void Stack<int>::push_front(int a)
//{
//	impl->push_front(a);
//}
//
//void Stack<int>::show()
//{
//	impl->show();
//}
//
//bool Stack<int>::is_empty()
//{
//	return impl->is_empty();
//}
//
//int Stack<int>::back()
//{
//	return impl->back();
//}
//
//int Stack<int>::front()
//{
//	return impl->front();
//}
//
//void Stack<int>::pop_front()
//{
//	impl->pop_front();
//}
//
//bool Stack<int>::erase_from_position(int position)
//{
//	return impl->erase_from_position(position);
//}
//
//bool Stack<int>::delete_data(int a)
//{
//	return impl->delete_data(a);
//}
//
//int Stack<int>::size() const
//{
//	return impl->size();
//}
//
//void Stack<int>::clear()
//{
//	impl->clear();
//}
//
//int Stack<int>::operator[](const int index)
//{
//	return impl->operator[](index);
//}
//
//void Stack<int>::sort()
//{
//	impl->sort();
//}
//
//void Stack<int>::random_push(int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		int rand_number = rand() % 10;
//		impl->push_front(rand_number);
//	}
//}



//void Stack<int>::push_back(int a)
//{
//}
//void Stack<int>::pop_back()
//{
//}


#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"sqd_deque.h"
#include"sqd_vector.h"
#include"sqd.h"
#include<typeinfo>

template<typename T>
class Queue :public SQD<T>
{
public:

	Queue() {impl = new sqd_list<T>;}
	Queue(int size)
	{
		if (size > 0)
			this->SIZE = size;
		impl = new sqd_list<T>;
	}
	T operator[](const int index);
	void show() override;
	void set_mode(MODE mode);
	bool is_empty() override;
	T back() override;
	T front() override;
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size()const override;
	void push_back(T a) override;
	void push(T a);
	void pop_front() override;//delete from begin
	void clear()override;
	void sort()override;
	void random_push(int N,int precision = 2);
	~Queue()
	{
		impl->clear();
	}
private:
	MODE mode = list;
	int SIZE = 0;//for array
	SQD<T>*impl;
	void push_front(T a) override;
	void pop_back() override;
};

#include"queue.inc"


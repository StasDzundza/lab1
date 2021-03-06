#pragma once
#include"SQD.h"
#include<deque>

template<typename T>
class sqd_deque :public SQD<T>
{
public:
	sqd_deque() { }
	T operator[](int index);
	//functions for deque in list
	void push_front(T a)override;
	void push_back(T a)override;
	void pop_front()override;
	void pop_back()override;

	//same functions for all 
	void show()override;
	bool is_empty()override;
	T back()override;
	T front()override;
	bool erase_from_position(int position)override;
	bool delete_data(T a)override;
	int size()const override;
	void clear() override;
	void sort()override;
private:
	std::deque<T> DEQUE;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include"sqd_deque.inc"
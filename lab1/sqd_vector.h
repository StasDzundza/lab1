#pragma once
#include"SQD.h"
#include<vector>
using namespace std;
template<typename T>
class sqd_vector :public SQD<T>
{
public:
	sqd_vector() { }
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
	void clear()override;
	void sort()override;
private:
	std::vector<T> VECTOR;
};


template<typename T>
T sqd_vector<T>::back()
{
	if(VECTOR.size() > 0)
		return VECTOR.back();
	else exit(1);
}


template<typename T>
T sqd_vector<T>::front()
{
	if (VECTOR.size() > 0)
		return VECTOR.front();
	else exit(1);
}

template<typename T>
void sqd_vector<T>::pop_front()
{
	if (VECTOR.size() > 0)
	{
		VECTOR.erase(VECTOR.begin());
	}
}


template<typename T>
bool sqd_vector<T>::erase_from_position(int position)
{
	if (position <= VECTOR.size() && position >= 1)
	{
		auto it = VECTOR.begin();
		advance(it, position - 1);
		VECTOR.erase(it);
		return true;
	}
	else return false;
}

template<typename T>
bool sqd_vector<T>::delete_data(T data)
{
	if (VECTOR.size() > 0)
	{
		int position = -1;
		for (int i = 0; i < VECTOR.size(); i++)
		{
			if (data == VECTOR[i])
			{
				position = i;
				break;
			}
		}
		if (position != -1)//������� ����� �������
		{
			auto it = VECTOR.begin();
			advance(it, position);
			VECTOR.erase(it);
			return true;
		}
		else
			return false;
	}
	else return false;
}

template<typename T>
int sqd_vector<T>::size() const
{
	return VECTOR.size();
}

template<typename T>
void sqd_vector<T>::show()
{
	for (int i = 0; i < VECTOR.size(); i++)
	{
		std::cout << VECTOR[i] << " ";
	}
	std::cout << endl;
}

template<typename T>
bool sqd_vector<T>::is_empty()
{
	return VECTOR.empty();
}

template<typename T>
void sqd_vector<T>::push_back(T a)
{
	VECTOR.push_back(a);
}

template<typename T>
void sqd_vector<T>::push_front(T a)
{
	auto it = VECTOR.begin();
	VECTOR.insert(it, a);
}

template<typename T>
void sqd_vector<T>::pop_back()
{
	if (VECTOR.size() > 0)
	{
		VECTOR.pop_back();
	}
}

template<typename T>
void sqd_vector<T>::clear()
{
	VECTOR.clear();
}

template<typename T>
T sqd_vector<T>::operator[](int index)
{
	int SIZE = VECTOR.size();
	if (SIZE > 0 && index < SIZE && index >= 0)
	{
		return VECTOR[index];
	}
	else exit(1);
}

template<typename T>
void sqd_vector<T>::sort()
{
	for (int i = 0; i < VECTOR.size(); i++)
	{
		for (int j = 1; j < VECTOR.size() - i; j++)
		{
			if (VECTOR[j-1] > VECTOR[j])
			{
				T tmp = VECTOR[j-1];
				VECTOR[j-1] = VECTOR[j];
				VECTOR[j] = tmp;
			}
		}
	}
}
#pragma once
#include <iostream>
using namespace std;

template<class T>
class RingB 
{
private:
	int m_pos;
	int m_size;
	T *m_values;

public:
	class iterator;

public:
	// initialize in the order declared ^
	RingB(int size) : m_pos(0), m_size(size), m_values(NULL)
	{
		m_values = new T[size];
	}

	~RingB()
	{
		delete[] m_values;
	}

	int GetSize()
	{
		return m_size;
	}

	void Add(T value)
	{
		m_values[m_pos] = value;
		m_pos++;
		if (m_pos == m_size)
		{
			m_pos = 0;
		}
	}

	T& Get(int pos)
	{
		return m_values[pos];
	}

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(m_size, *this);
	}
};

template<class T>
class RingB<T>::iterator
{
private:
	int m_pos;
	RingB &m_ring;

public:
	iterator(int pos, RingB& aRing) : m_pos(pos), m_ring(aRing)
	{
	}

	iterator& operator++(int)
	{
		m_pos++;
		return *this;
	}

	iterator& operator++()
	{
		m_pos++;
		return *this;
	}

	T& operator*()
	{
		return m_ring.Get(m_pos);
	}

	bool operator!=(const iterator &other) const
	{
		return m_pos != other.m_pos;
	}

	void print()
	{
		cout << "Hello from iterator :" << T() << endl;
	}
};

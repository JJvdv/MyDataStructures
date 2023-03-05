#include "assert.h"

#include <iostream>

template <class elemType>
class ArrayList
{
public:
	ArrayList(int size = 100);
	ArrayList(const ArrayList<elemType>& otherList);
	~ArrayList();

	const ArrayList<elemType>& operator=(const ArrayList<elemType>&);

	bool isEmpty() const;
	bool isFull() const;
	bool isItemAtEqual(int location, const elemType& Item) const;

	int listSize() const;
	int maxListSize() const;
	int seqSearch(const elemType& item) const;

	void print() const;
	void insertAt(int location, const elemType& inItem);
	void insertEnd(const elemType& inItem);
	void removeAt(int location);
	void retrieveAt(int location, const elemType& retItem) const;
	void replaceAt(int location, const elemType& repItem);
	void clearList();
	void insert(const elemType& inItem);
	void remove(const elemType& remItem);

protected:
	elemType* list;
	int length;
	int maxSize;

};

//Implementation of Template class

template <class elemType>
ArrayList<elemType>::ArrayList(int size)
{
	if (size < 0)
	{
		std::cerr << "The array size must be positive. Creating an array of size 100." << std::endl;

		maxSize = 100;
	}
	else
	{
		maxSize = size;
	}

	length = 0;

	list = new elemType[maxSize];

	assert(list != NULL);
}

template <class elemType>
ArrayList<elemType>::~ArrayList()
{
	delete[] list;
}

template <class elemType>
ArrayList<elemType>::ArrayList(const ArrayList<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize];

	for (int i = 0; i < length; i++)
		list[i] = otherList.list[i];
}

template <class elemType>
const ArrayList<elemType>& ArrayList<elemType>::operator=(const ArrayList<elemType>& otherList)
{
	if (this != &otherList)
	{
		delete[] list;

		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new elemType[maxSize];

		assert(list != NULL);

		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}

	return *this;
}

template <class elemType>
void ArrayList<elemType>::insert(const elemType& inItem)
{
	int loc;

	if (length == 0)
		list[length++] = inItem;
	else if (length == maxSize)
		std::cerr << "Cannot insert in a full list!" << std::endl;
	else
	{
		loc = seqSearch(inItem);

		if (loc == -1)
			list[length++] = inItem;
		else
			std::cerr << "The item to be inserted is already in the list. No duplicates are allowed!" << std::endl;
	}
}

template <class elemType>
void ArrayList<elemType>::remove(const elemType& remItem)
{
	int loc;

	if (length == 0)
		std::cerr << "Cannot delete from an empty list!" << std::endl;
	else
	{
		loc = seqSearch(remItem);

		if (loc != -1)
			removeAt(loc);
		else
			std::cout << "The item to be deleted is not in the list!" << std::endl;
	}
}


template <class elemType>
bool ArrayList<elemType>::isEmpty() const
{
	return (length == 0);
}

template <class elemType>
bool ArrayList<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int ArrayList<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int ArrayList<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void ArrayList<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		std::cout << list[i] << " ";

	std::cout << std::endl;
}

template <class elemType>
bool ArrayList<elemType>::isItemAtEqual(int location, const elemType& item) const
{
	return(list[location] == item);
}

template <class elemType>
void ArrayList<elemType>::insertAt(int location, const elemType& inItem)
{
	if (location < 0 || location >= maxSize)
		std::cerr << "The position of the item to be inserted is out of range!" << std::endl;
	else
		if (length >= maxSize)
			std::cerr << "Cannot inser in a full list!" << std::endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1];

			list[location] = inItem;

			length++;
		}
}

template <class elemType>
void ArrayList<elemType>::insertEnd(const elemType& inItem)
{
	if (length >= maxSize)
		std::cerr << "Cannot insert in a full list!" << std::endl;
	else
	{
		list[length] = inItem;
		length++;
	}
}

template <class elemType>
void ArrayList<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		std::cerr << "The location of the item to be removed is out of range!" << std::endl;
	else
	{
		for (int i = location; i < length; i++)
			list[i] = list[i + 1];

		length--;
	}
}

template <class elemType>
void ArrayList<elemType>::retrieveAt(int location, const elemType& retItem) const
{
	if (location < 0 || location >= length)
		std::cerr << "The location of the item to be retrieved is out of range!" << std::endl;
	else
		retItem = list[location];
}

template <class elemType>
void ArrayList<elemType>::replaceAt(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
		std::cerr << "The location of the item to be replaced is out of range!" << std::endl;
	else
		list[location] = repItem;
}

template <class elemType>
void ArrayList<elemType>::clearList()
{
	length = 0;
}


template <class elemType>
int ArrayList<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}

	if (found)
		return true;
	else
		return -1;
}



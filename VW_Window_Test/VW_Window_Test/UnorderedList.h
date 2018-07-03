#pragma once

#include "stdafx.h"
#include <cstring>
#include <iostream>

template <class T>
class UnorderedList {
private:

	T * items;
	unsigned int itemsLength;
	unsigned int itemsCount;



public:

	UnorderedList() :
		itemsLength(0),
		itemsCount(0) {
		items = new T[0];
	}

	UnorderedList(unsigned int initialSize) :
		itemsLength(initialSize),
		itemsCount(0) {
		items = new T[itemsLength];
	}

	UnorderedList(unsigned int initialSize, T* items) :
		items(items),
		itemsLength(initialSize),
		itemsCount(initialSize) {
	}

	~UnorderedList() {
		//if(itemsLength) delete[] items;
	}

	void Reset() {
		if (items) delete items;
		items = new T[itemsLength];
		itemsCount = 0;
	}


	T Push(T item) {
		if (itemsCount == itemsLength) {
			itemsLength = itemsLength * 2 + 1;
			T* newItems = new T[itemsLength]();
			if (itemsCount) {
				memcpy(newItems, items, (sizeof items[0]) * itemsCount);
			}
			delete[] items;
			items = newItems;
		}
		items[itemsCount++] = item;
		return item;
	}

	T Pop() {
		return items[--itemsCount];
	}


	T Cut(T item) {
		unsigned int i = itemsCount;
		while (i-->0) {
			if (items[i] != item) continue;
			T it = items[i];
			items[i] = items[--itemsCount];
			return it;
		}
		std::cout << "COULD'NT CUT ITEM!\n";
		return T();
	}


	T operator [](const unsigned int index) {
		return items[index];
	}


	unsigned int Count() {
		return itemsCount;
	}

	unsigned int Size() {
		return itemsLength;
	}

};



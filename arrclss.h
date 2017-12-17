#include <iostream>
#include <stdlib.h>
#include "baseclss.h"
#include <fstream>

using namespace std;

class indexOutOfRange : public std::exception {};

template <typename T> class ArraySequence : public Sequence<T> {
public:
	T* arr;
	ArraySequence() {
		arr = new T[4];
		length = 4; //объем выделенной памяти
		count_elements = 0; //кол-во элементов
	}
	~ArraySequence() { delete[] arr; };
	void show() {
		cout << "[";
		for (int i = 0; i < count_elements; i++)
		{
			cout << arr[i];
			if (i < count_elements - 1)
				cout << ", ";
		}
		cout << "]" << endl;
	}
	T Get(int ind) override {
		if ((ind >= 0) && (ind < count_elements))
			return arr[ind];
		else
			throw indexOutOfRange();
	}
	T GetFirst() override {
		if (length != 0)
			return arr[0];
		else
			throw indexOutOfRange();
	}
	T GetLast() override {
		if (length != 0)
			return arr[count_elements - 1];
		else
			throw indexOutOfRange();
	}
	Sequence<T>& GetSubsequence(int FirstInd, int LastInd) override {
		ArraySequence<T> *SubSeq = new ArraySequence <T>;
		if ((FirstInd < 0) || (FirstInd >= count_elements) || (LastInd < 0) || (LastInd >= count_elements))
			throw indexOutOfRange();
		else
		{
			for (int i = FirstInd; i < LastInd + 1; i++)
			{
				SubSeq->Append(arr[i]);
			};
		};
		return *SubSeq;
	};
	void Append(T item) override {
		if (count_elements == length) {
			T* bigarr = new T[2 * count_elements];
			for (int i = 0; i < count_elements; i++) {
				bigarr[i] = arr[i];
			}
			arr = bigarr;
			//arr = (T*)realloc(arr, length * 2 * sizeof(T));
			length *= 2;
		}
		arr[count_elements] = item;
		count_elements++;
	};
	void Prepend(T item) override {
		T* newarr;
		if (count_elements == length) {
			newarr = new T[2*length];
			length *= 2;
		}
		else {
			newarr = new T[length];
		};
		newarr[0] = item;
		for (int i = 1; i < count_elements+1; i++)
		{
			newarr[i] = arr[i - 1];
		};
		arr = newarr;
		count_elements++;
	};
	void InsertAt(T item, int ind) override {
		T* newarr;
		if (count_elements == length) {
			newarr = new T[2 * length];
			length *= 2;
		}
		else {
			newarr = new T[length];
		};
		for (int i = 0; i < ind; i++)
		{
			newarr[i] = arr[i];
		};
		newarr[ind] = item;
		for (int i = ind+1; i < count_elements+1; i++)
		{
			newarr[i] = arr[i - 1];
		};
		arr = newarr;
		count_elements++;
	}
	int Getlength() override {
		return count_elements;
	};
	void Change(T item, int ind)
	{
		arr[ind] = item;
	}
	void Remove(T item) override {
		int i = 0;
		while ((arr[i] != item) && (i<count_elements)) i++;
		if (i < count_elements)
		{
			for (int k = i; k < count_elements - 1; k++)
				arr[k] = arr[k + 1];
			arr[count_elements] = 0;
			count_elements--;
		};
	};
	/*void BubbleSort() override 
	{
		if (count_elements > 1)
		{
			int p = 1;
			int end = count_elements - 1;
			while (p != 0)
			{
				p = 0;
				for (int i = 0; i < end; i++)
				{

					if (arr[i] > arr[i + 1])
					{
						T CurEl = arr[i];
						arr[i] = arr[i + 1];
						arr[i + 1] = CurEl;
						p++;
					}
				};
				end--;
			};
		};
	};*/

private:
	int length;
	int count_elements;
};
#pragma once

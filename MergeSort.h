#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "baseclss.h"
#include "arrclss.h"
#include "listclss.h"

using namespace std;

template <typename T> void MergeSort(Sequence <T> *seq, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(seq, low, mid);
		MergeSort(seq, mid + 1, high);
		Merge(seq, low, high, mid);
	}
}

template <typename T> void Merge(Sequence <T> *seq, int low, int high, int mid)
{
	int i = low, j = mid+1, k = 0;
	int m = high - low + 1;
	T *temp = new T[m];
	while (i <= mid && j <= high)
	{
		T a1 = seq->Get(i);
		T a2 = seq->Get(j);
		if (a1 < a2)
		{
			temp[k] = a1;
			k++;
			i++;
		}
		else
		{
			temp[k] = a2;
			k++;
			j++;
		}
	};
	while (i <= mid)
	{
		T a = seq->Get(i);
		temp[k] = a;
		k++;
		i++;
	}
	while (j <= high)
	{
		T a = seq->Get(j);
		temp[k] = a;
		k++;
		j++;
	}
	int tmp = 0;
	for (i = low; i <= high; i++)
	{
		seq->Change(temp[tmp],i);
		tmp++;
	}
}

#pragma once

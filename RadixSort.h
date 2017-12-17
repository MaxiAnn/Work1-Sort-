#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "baseclss.h"
#include "arrclss.h"
#include "listclss.h"

using namespace std;

template <typename T> void RadixSort(Sequence <T> *seq)
{
	int del = 1, ost = 10, a, a0, digit, i, j, zero = 0;
	int size = seq->Getlength();
	while (zero != size)
	{
		zero = 0;
		vector <vector <T>> Data(10);
		for (i = 0; i < size; i++)
		{
			a = seq->Get(i);
			if (a < del) { a0 = 0; }
			else { a0 = a / del; };
			if (a0 == 0) zero++;
			digit = a0 % ost;
			Data[digit].push_back(a);
		}
		int l = 0;
		for (i = 0; i < 10; i++)
		{
			int size_vec = Data[i].size();
			for (j = 0; j < size_vec; j++)
			{
				seq->Change(Data[i][j], l);
				l++;
			}			
		}
		del *= 10;
	}
}

#pragma once

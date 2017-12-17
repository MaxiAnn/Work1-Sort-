#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "baseclss.h"
#include "arrclss.h"
#include "listclss.h"

using namespace std;

template <typename T> void BubbleSort(Sequence <T>* seq)
{
	int end = seq->Getlength();
	int a, b;
	if (end > 1)
	{
		int p = 1;
		end--;
		while (p != 0)
		{
			p = 0;
			for (int i = 0; i < end; i++)
			{
				a = seq->Get(i);
				b = seq->Get(i + 1);
				if (a > b)
				{
					seq->InsertAt(a, i + 2);
					seq->Remove(a);
					p++;
				}
			};
			end--;
		};
	};
};
#pragma once
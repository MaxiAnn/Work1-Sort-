#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "baseclss.h"
#include "arrclss.h"
#include "listclss.h"
#include "BS.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "TestingSort.h"

using namespace std;

void Compare_Time()
	{
		Sequence <int> *p = new ListSequence<int>;
		Sequence <int> *q = new ListSequence<int>;
		Sequence <int> *r = new ListSequence<int>;
		int item;
		ifstream fin("ForTime.txt");
		int N;
		fin >> N;
		for (int i = 0; i < N; i++)
		{
			int item;
			fin >> item;
			p->Append(item);
			q->Append(item);
			r->Append(item);
		};
		fin.close();

		int time1, time2, time3, start, end;

		start = clock();
		BubbleSort(p);
		end = clock();
		time1 = end - start;

		start = clock();
		MergeSort(q, 0, q->Getlength() - 1);
		end = clock();
		time2 = end - start;

		start = clock();
		RadixSort(r);
		end = clock();
		time3 = end - start;

		cout << "Time of BS in ms: " << time1 << endl;
		cout << "Time of MS in ms: " << time2 << endl;
		cout << "Time of RS in ms: " << time3 << endl;

		if (time1 < time2)
		{
			if (time1 < time3)
			{
				cout << "The fastest soring is Bubble Sort \n";
			}
			else
			{
				cout << "The fastest soring is Radix Sort \n";
			}
		}
		else
		{
			if (time2 < time3)
			{
				cout << "The fastest soring is Merge Sort \n";
			}
			else
			{
				cout << "The fastest soring is Radix Sort \n";
			}
		}
	}

#pragma once

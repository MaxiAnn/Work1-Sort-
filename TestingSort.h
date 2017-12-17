#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "baseclss.h"
#include "arrclss.h"
#include "listclss.h"
#include "BS.h"
#include "MergeSort.h"
#include "RadixSort.h"

using namespace std;

void Test()
{
int ind;
cout << "What sorting you would like to check? " << endl << "Bubble Sort - 1 \n Merge Sort - 2 \n Radix Sort - 3" << endl;
cin >> ind;
if (ind == 1)
{
Sequence <int> *p = new ListSequence<int>;
Sequence <int> *q = new ListSequence<int>;
int a, item;
ifstream fin("ForTestSortedSeq.txt");
int N;
fin >> N;
for (int i = 0; i < N; i++)
{
item;
fin >> item;
p->Append(item);
};
fin.close();
BubbleSort(p);
bool f = true;
ifstream f1in("SortedSeq.txt");
for (int i = 0; i < N; i++)
{
item;
f1in >> item;
a = p->Get(i);
if (item != a) f = false;
}
f1in.close();
if (f) { cout << "Bubble Sort works correctly \n"; }
else
{
cout << "Something is wrong: \n ";
cout << "Result: ";
p->show();
ifstream f2in("SortedSeq.txt");
for (int i = 0; i < N; i++)
{
item;
f2in >> item;
q->Append(item);
}
f2in.close();
cout << "\n Expected: ";
q->show();
}
}
else
{
if (ind == 2)
{
Sequence <int> *p = new ListSequence<int>;
Sequence <int> *q = new ListSequence<int>;
int a, item;
ifstream fin("ForTestSortedSeq.txt");
int N;
fin >> N;
for (int i = 0; i < N; i++)
{
item;
fin >> item;
p->Append(item);
};
fin.close();
MergeSort(p, 0, p->Getlength() - 1);
bool f = true;
ifstream f1in("SortedSeq.txt");
for (int i = 0; i < N; i++)
{
item;
f1in >> item;
a = p->Get(i);
if (item != a) f = false;
}
if (f) { cout << "Merge Sort works correctly \n"; }
else
{
cout << "Something is wrong: \n ";
cout << "Result: ";
p->show();
ifstream f2in("SortedSeq.txt");
for (int i = 0; i < N; i++)
{
item;
f2in >> item;
q->Append(item);
}
f2in.close();
cout << "\n Expected: ";
q->show();
}

}
else {
Sequence <int> *p = new ListSequence<int>;
Sequence <int> *q = new ListSequence<int>;
int a, item;
ifstream fin("ForTestSortedSeq.txt");
int N;
fin >> N;
for (int i = 0; i < N; i++)
{
item;
fin >> item;
p->Append(item);
};
fin.close();
RadixSort(p);
bool f = true;
ifstream f1in("SortedSeq.txt");
for (int i = 0; i < N; i++)
{
item;
f1in >> item;
a = p->Get(i);
if (item != a) f = false;
}
if (f) { cout << "Radix Sort works correctly \n"; }
else
{
cout << "Something is wrong: \n ";
cout << "Result: ";
p->show();
ifstream f2in("SortedSeq.txt");
for (int i = 0; i < N; i++)
{
item;
f2in >> item;
q->Append(item);
}
f2in.close();
cout << "\n Expected: ";
q->show();
}
}
}
}


#pragma once
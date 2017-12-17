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
#include "Time.h"

using namespace std;

int main()
{
Sequence <int> *p = new ListSequence<int>;
cout << "Enter size of sequence you'd like to create: " << endl;
int N;
cin >> N;
ofstream foutG("DataForSeq.txt");
srand(43);
int item;
for (int i = 0; i < N; i++)
{
	item = rand();
	p->Append(item);
	foutG << item << " ";
};
foutG.close();
p->show();
cout << "The sequence's length: " << p->Getlength(); cout << endl;
int ind;
cout << "What sorting you would like to use? " << endl << " Bubble Sort - 1 \n Merge Sort - 2 \n Radix Sort - 3" << endl;
cin >> ind;
if (ind == 1)
{
	BubbleSort(p);
	cout << "You used Bubble sort, \n ";
}
else
{
	if (ind == 2)
	{
		MergeSort(p, 0, p->Getlength()-1);
		cout << "You used Merge sort, \n";
	}
	else
	{
		RadixSort(p);
		cout << "You used Radix sort, \n";
	}
}
cout << "Sorted sequence: ";
p->show();
Test();
//Compare_Time();

system("pause");
return 0;


}



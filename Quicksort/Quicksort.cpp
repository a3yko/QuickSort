// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;


void quickSort(vector<int> &, int, int);
void load(vector<int> &);
void print(vector<int>);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> datDere(1);
	srand(time(NULL));

	//Load vector 0h 23min 42sec
	load(datDere);
	print(datDere);
	cin.get();

	//Sort vector
	//Get time here
	double begin = clock();
	quickSort(datDere, 0, datDere.size() - 1);

	//Get time here
	double end = clock(); 
	double total = (end - begin) /1000.0;
	int secs = total;
	print(datDere);
	cout << "\n\nTime elapsed: " << total / 60 << "min " << secs % 60 << "sec " << endl;
	cin.get();
	
	return 0;
}


void load(vector<int> & datDere)
{
	ifstream data("data.txt");
	int garbage;
	while (data >> garbage)
	{
		datDere.push_back(garbage);
	}
	data.close();
}


void print(vector<int> datDere)
{
	for (int i = 0; i < datDere.size(); i++)
		cout << datDere.at(i) << '\t';
}


void quickSort(vector<int> & datDere, int beg, int end)
{
	if (beg == end)
		return;
	bool solved = true;
	for (int i = beg; i < end - 1; i++)
	{
		if (!(datDere.at(i) <= datDere.at(i + 1)))
			solved = false;

	}
	
	
	int mid = end;
	if (datDere.at(beg) > datDere.at(end))
		swap(datDere.at(beg), datDere.at(end));
	//Partition middle value
	for(int i = 0; i < end; i++)
	{
		if (datDere.at(i) > datDere.at(mid) && i < mid)
		{
			swap(datDere.at(i), datDere.at(mid));
			mid = i;
		}

		if (datDere.at(i) <= datDere.at(mid) && i > mid)
		{
			swap(datDere.at(i), datDere.at(mid));
			mid = i;
			for (int u = 0; u < mid; u++)
			if (datDere.at(u) > datDere.at(mid) && u < mid)
			{
				swap(datDere.at(u), datDere.at(mid));
				mid = u;
			}
		}
	}

	//Partion remaining parts separately
	//Left
	if (mid != 0)
	quickSort(datDere, beg, mid - 1);
	//Right
	if (mid != end)
	quickSort(datDere, mid + 1, end);
}

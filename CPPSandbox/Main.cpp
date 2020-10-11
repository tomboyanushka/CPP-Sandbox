// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
// Given an array of integers and a value, determine if there are any three integers in the array whose sum equals the given value.

void ArrayMain()
{
	vector<int> sumArray;
	int sum = 24;
	int arr[] = { 12, 3, 4, 1, 6, 9, 14};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrSize - 2; ++i)
	{
		int l = i + 1;
		int r = arrSize - 1;
		while (l < r)
		{
			if (arr[i] + arr[l] + arr[r] == sum)
			{
				sumArray.push_back(arr[i]);
				sumArray.push_back(arr[l]);
				sumArray.push_back(arr[r]);
				sumArray.push_back(0);
				break;
			}
			else if (arr[i] + arr[l] + arr[r] < sum)
			{
				l++;
			}
			else
			{
				r--;
			}
		}
			
	}

	for (int i = 0; i < sumArray.size(); ++i)
	{
		if (sumArray[i] == 0)
		{
			cout << endl;
		}
		else
		{
			std::cout << sumArray[i] << " ";
		}


	}

}

// Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.
// Given the head pointers of two linked lists where each linked list represents an integer number (each node is a digit), add them and return the resulting linked list.
// Given two sorted linked lists, merge them so that the resulting linked list is also sorted.

int main()
{
	ArrayMain();

	return 0;
}

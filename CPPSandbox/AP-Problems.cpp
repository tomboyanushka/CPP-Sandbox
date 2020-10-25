#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_set>
using namespace std;

// Given an array of integers and a value, determine if there are any three integers in the array whose sum equals the given value.
void ArrayMain()
{
	vector<int> sumArray;
	int sum = 24;
	int arr[] = { 12, 3, 4, 1, 6, 9, 14 };
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
struct Interval
{
	int start, end;
};

bool CompareInterval(Interval a, Interval b)
{
	return a.start < b.start;
}
void MergeIntervals(Interval arr[], int n)
{
	stack<Interval> stack;
	sort(arr, arr + n, CompareInterval);

	stack.push(arr[0]);

	for (int i = 1; i < n; ++i)
	{
		Interval top = stack.top();

		if (top.end < arr[i].start)
		{
			stack.push(arr[i]);
		}
		else if (top.end < arr[i].end)
		{
			top.end = arr[i].end;
			stack.pop();
			stack.push(top);
		}
	}

	cout << "Merged Intervals are: " << endl;
	while (!stack.empty())
	{
		cout << "{" << stack.top().start << ", " << stack.top().end << "}" << " ";
		stack.pop();
	}
	return;
}


// Given two sorted linked lists, merge them so that the resulting linked list is also sorted.

// Given a non empty string s and a dictionary wordDict containing a list of non empty words, determine if there is space segmentation of s and divide it to two or more different words.

// Given the roots of two binary trees, determine if these trees are identical or not. Identical trees have the same layout and data at each node.

// Given a double, ‘x’, and an integer, ‘n’, write a function to calculate ‘x’ raised to the power ‘n’
double FindExponential(double x, int n)
{
	double res;// = x;
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	res = FindExponential(x, n / 2);
	if (n % 2 == 0)
	{
		return res * res;
	}
	else
	{
		if (n > 0)
		{
			return x * res * res;
		}
		else
			return (res * res) / x;
	}

	return res;
}


// Given a string find all non-single letter substrings that are palindromes.
void expandString(string str, int low, int high, unordered_set<string>& set)
{
	while (low >= 0 && high < str.length() && str[low] == str[high])
	{
		set.insert(str.substr(low, high - low + 1));

		low--;
		high++;
	}
}
void PalindromeSubStr(string str)
{
	unordered_set<string> set;

	for (int i = 0; i < str.length(); ++i)
	{
		expandString(str, i, i, set);

		expandString(str, i, i + 1, set);
	}

	for (auto i : set)
	{
		cout << i << " ";
	}
}


// Given a positive integer, target, print all possible combinations of positive integers that sum up to the target number.
void FindPositiveCombinationsUtil(int arr[], int num, int reducedNum, int index)
{

	//int* combinations = new int[num];

	if (reducedNum < 0)
	{
		//cout << 0 << endl;
		return;
	}
	if (reducedNum == 0)
	{
		for (int i = 0; i < index; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	int prev = (index == 0) ? 1 : arr[index - 1];

	for (int k = prev; k <= num; ++k)
	{
		arr[index] = k;

		FindPositiveCombinationsUtil(arr, num, reducedNum - k, index + 1);
	}
}

int apple_main()
{
	//ArrayMain();

	//Interval arr[] = { {6,8}, {5,9}, {2,5}, {4,7} };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//MergeIntervals(arr, n);

	//double rand = 2;
	//cout << FindExponential(rand, -3) << endl;

	//int n = 5;
	//int* arr = new int[n];
	//FindPositiveCombinationsUtil(arr, n, n, 0);

	string str = "malayalam";
	PalindromeSubStr(str);

	return 0;
}
#include "Vectors.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// To Do: what other namespaces are there and what do they do
using namespace std;

int main()
{
	
	vector<int> Numbers;
	Numbers.push_back(45);
	Numbers.push_back(722);
	Numbers.push_back(18);
	Numbers.push_back(29);

	cout << "Unsorted vector: " << endl;
	for (int i = 0; i < Numbers.size(); ++i)
	{
		cout << Numbers[i] << endl;
	}

	sort(Numbers.begin(), Numbers.end());

	vector<int>::reverse_iterator it = Numbers.rbegin();

	cout << "Sorted vector: " << endl;
	for (it; it != Numbers.rend(); ++it)
	{
		cout << *it << endl;
	}


	return 0;
}

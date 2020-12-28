#include <iostream>
#include "RingBuffer.h"
using namespace std;

int main()
{
	RingB<string> textRing(3);

	textRing.Add("one");
	textRing.Add("two");
	textRing.Add("three");

	for (RingB<string>::iterator it = textRing.begin(); it != textRing.end(); ++it)
	{
		cout << *it << endl;
	}

	for (string value : textRing)
	{
		cout << value << endl;
	}

}
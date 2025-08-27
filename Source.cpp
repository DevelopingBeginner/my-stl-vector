#include "NewVector.h"
#include <iostream>

using namespace std;

int main()
{
	NewVector<int> intVec{24, 14, 56};
	intVec.push_back(10);
	for (int i = 0; i < intVec.size(); i++)
	{
		cout << intVec[i] << endl;
	}
	
	cout << "size = " << intVec.size() << endl;

	cout << "capacity = " << intVec.capacity() << endl;
	
	cout << "shrink to fit function!" << endl;

	intVec.shrink_to_fit();

	cout << "capacity = " << intVec.capacity() << endl;

	return 0;
}
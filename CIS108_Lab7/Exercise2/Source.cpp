#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	cout << "Please wait while we count the numbers(1-100000) divisible by 7" << endl;
	int count = 0;
	vector<int> numbers;
	for (int i = 1; i <= 1000000; i++)
	{
		numbers.push_back(i);
	}

	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		if((*it % 7) == 0)	
			count++;
	}
	cout << "The total count is : " << count << endl;
	system("PAUSE");
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int num, add = 0;
	int i = 0, x = 0;
	int voidnum;
	cin >> voidnum;

	do
	{
		cin >> num;
		if ((num % 3 == 0 or num % 5 == 0) and num <= 1000)
		{
			add = add + num;
			++i;
		}
		++x;
		if (num == -1)
			break;

	} while (i < 10 and x < voidnum);
	
	cout << add;
}
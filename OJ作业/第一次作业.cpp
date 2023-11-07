#include <math.h>
#include <iostream>
#include <iomanip>

int main()
{
	int year;
	std::cin >> year;
	if (year % 4 == 0 and year % 100 != 0)
		std::cout << "YES";

	else if (year % 400 == 0)
		std::cout << "YES";

	else
		std::cout << "NO";

	return 0;
}

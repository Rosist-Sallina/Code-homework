#include <iostream>
#include <fstream>

using namespace std;
void Yearprint();

int main()
{
	Yearprint();
}

void Yearprint()
{
	int year;
	cin >> year;
	int x = 1;
	int year_muti;

	if (year <= 2024)
		year_muti = 0;

	else
		year_muti = (year-2023 - (year - 2023) % 4) / 4 + 1;

	int year_number = (365 * (year - year_muti - 2023) + 366 * year_muti);
	year_number = (year_number +6) % 7-1;
	
	if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0)  //检测是否是闰年（闰年的情况）
	{
		cout << "01 ";
		for (int temp = 1; temp <= 5 + year_number * 4; temp++)
			cout << " ";
		cout<< "1  " ;

		x = year_number+3;

		if (x >= 8)
		{
			cout << endl << "   ";
			x = 1;
		}

		for (int i = 1; i < 31; i++)
		{

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}

			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((32 - i) <= 7 and x == 8)
			{
				cout << endl << "02 ";
				x = 1;
				continue;
			}


		}                      //第一个月的日历形成

		for (int i = 0; i < 29; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((30 - i) <= 8 and x == 8)
			{
				cout << endl << "03 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形成

		for (int i = 0; i < 31; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((32 - i) <= 8 and x == 8)
			{
				cout << endl << "04 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

		for (int i = 0; i < 30; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((31 - i) <= 8 and x == 8)
			{
				cout << endl << "05 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

		for (int i = 0; i < 31; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((31 - i) <= 7 and x == 8)
			{
				cout << endl << "06 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

		for (int i = 0; i < 30; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((31 - i) <= 8 and x == 8)
			{
				cout << endl << "07 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第六个月的日历形

		for (int i = 0; i < 31; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((32 - i) <= 8 and x == 8)
			{
				cout << endl << "08 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

		for (int i = 0; i < 31; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((32 - i) <= 8 and x == 8)
			{
				cout << endl << "09 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

		for (int i = 0; i < 30; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((30 - i) <= 8 and x == 8)
			{
				cout << endl << "10 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第十个月的日历形

		for (int i = 0; i < 31; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((32 - i) <= 8 and x == 8)
			{
				cout << endl << "11 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

		for (int i = 0; i < 30; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if ((31 - i) <= 8 and x == 8)
			{
				cout << endl << "12 ";
				x = 1;
				continue;
			}

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第十一个月的日历形

		for (int i = 0; i < 31; i++)
		{
			if (i <= 8)
				cout << " " << i + 1 << "  ";

			else
				cout << i + 1 << "  ";
			x++;

			if (x >= 8)
			{
				cout << endl << "   ";
				x = 1;
			}
		}                      //第二个月的日历形

	}

	else
	{
		//检测是否是闰年（不是闰年的情况）
		{
			cout << "01 ";
			for (int temp = 1; temp <= 5 + year_number * 4; temp++)
					cout << " ";
			cout << "1  ";

			x = year_number+3;

			for (int i = 1; i < 31; i++)
			{

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}

				if (i <= 8)
					cout << " " << i + 1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((32 - i) <= 8 and x == 8)
				{
					cout << endl << "02 ";
					x = 1;
					continue;
				}

				
			}                      //第一个月的日历形成

			for (int i = 0; i < 28; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((29 - i) <= 8 and x == 8)
				{
					cout << endl << "03 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形成

			for (int i = 0; i < 31; i++)
			{
				if (i <= 8)
					cout << " " << i +1<< "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((32 - i) <= 8 and x == 8)
				{
					cout << endl << "04 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

			for (int i = 0; i < 30; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i +1<< "  ";
				x++;

				if ((31 - i) <= 8 and x == 8)
				{
					cout << endl << "05 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

			for (int i = 0; i < 31; i++)
			{
				if (i <= 8)
					cout << " " << i +1<< "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((31 - i) <= 8 and x == 8)
				{
					cout << endl << "06 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

			for (int i = 0; i < 30; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((31 - i) <= 8 and x == 8)
				{
					cout << endl << "07 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第六个月的日历形

			for (int i = 0; i < 31; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((32 - i) <= 8 and x == 8)
				{
					cout << endl << "08 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

			for (int i = 0; i < 31; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((32 - i) <= 8 and x == 8)
				{
					cout << endl << "09 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

			for (int i = 0; i < 30; i++)
			{
				if (i <= 8)
					cout << " " << i +1<< "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((30 - i) <= 8 and x == 8)
				{
					cout << endl << "10 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第十个月的日历形

			for (int i = 0; i < 31; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((32 - i) <= 8 and x == 8)
				{
					cout << endl << "11 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

			for (int i = 0; i < 30; i++)
			{
				if (i <= 8)
					cout << " " << i+1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if ((31 - i) <= 8 and x == 8)
				{
					cout << endl << "12 ";
					x = 1;
					continue;
				}

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第十一个月的日历形

			for (int i = 0; i < 31; i++)
			{
				if (i <= 8)
					cout << " " << i +1 << "  ";

				else
					cout << i + 1 << "  ";
				x++;

				if (x >= 8)
				{
					cout << endl << "   ";
					x = 1;
				}
			}                      //第二个月的日历形

		}
		}
}

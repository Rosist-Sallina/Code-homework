#include <iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<cstdlib>
using namespace std;
string** bubble_sort(string** input , int N);

string** bubble_sort(string** input , int N)
{
	int i, j;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (input[j][1] < input[j + 1][1])
				swap(input[j], input[j + 1]);
		}
	}
	return input;
}

int main()
{
	int N; int like; int unlike;
	cin >> N;
	cin >> like;
	cin >> unlike;

	string** arr = new string * [N];
	for (int i = 0; i < N; ++i)
	{
		arr[i] = new string[2];
		cin >> arr[i][0];
		cin >> arr[i][1];
	}
	string* love = new string[like];
	string* unlove = new string[unlike];
	if (like != 0)
	{
		for (int i = 0; i < like; ++i)
		{
			cin >> love[i];
		}
	}
	if (unlike != 0)
	{
		for (int i = 0; i < unlike; ++i)
		{
			cin >> unlove[i];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int x = 0; x < like; x++)
		{
			if (arr[i][0] == love[x])
			{
				if (atoi(arr[i][1].c_str()) < 90)
				{
					arr[i][1] = to_string(atoi(arr[i][1].c_str()) + 5);
					if (atoi(arr[i][1].c_str()) <= 60)
						arr[i][1] = "60";
				}

				else if (atoi(arr[i][1].c_str()) >= 90 && atoi(arr[i][1].c_str()) <= 95)
				{
					arr[i][1] = "95";
				}
			}
		}
		for (int x = 0; x < unlike; x++)
		{
			if (arr[i][0] == unlove[x])
			{
				if (atoi(arr[i][1].c_str()) <= 65 && atoi(arr[i][1].c_str()) >= 60)
				{
					arr[i][1] = "60";
				}
				else if(atoi(arr[i][1].c_str()) > 65)
					arr[i][1] =to_string(atoi(arr[i][1].c_str()) - 5);
			}
		}

	}
	arr = bubble_sort(arr, N);

	//for (int i = 0; i < N; ++i)
	//{
	//	cout << arr[i][0] << " " << arr[i][1] << endl;
	//}
	
	
	for (int i = 0; i < N; ++i)
	{
		for (int x = 0; x < N; ++x)
		{
			if (arr[i][1] == arr[x][1] && arr[i][0] < arr[x][0])
				swap(arr[x], arr[i]);

		}
	}
	for (int i = 0; i < N; ++i)
	{
		cout << arr[i][0] << " " << arr[i][1] << endl;
	}
	delete arr, love, unlove;
		return 0;;
}

	
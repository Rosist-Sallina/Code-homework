#include<iostream>
#include<random>
#include<cmath>
#include<time.h>

int main()
{
	int square[4][4];
	int temp[4][4];
	srand((unsigned)time(NULL));

	for (int i = 0; i < 4; ++i)
	{
		for (int x = 0; x < 4; ++x)
		{
			square[i][x] = (rand() % 21);
		}
	}
	int order; int to;
	std::cout << "Please enter your order:" << std::endl;

	std::cin >> order;            //0代表压缩，1代表旋转
	std::cin >> to;               //对于压缩，1代表按行上，2代表按行下，3代表列左，4为列右；对于旋转，1,2,3,4，分别代表左右上下

	for (int i = 0; i < 4; ++i)
	{
		for (int x = 0; x < 4; x++)
		{
			if (square[i][x] < 10)
				std::cout << square[i][x] << "  ";
			else
				std::cout << square[i][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------OUTPUT-------------------" << std::endl;
	switch (order)
	{
	case 0:
	{
		switch (to)
		{
		case 1:
		{
			for (int i = 3; i > 0; i--)
			{
				for (int x = 0; x < 4; ++x)
				{
					square[0][x] += square[i][x];
					square[i][x] = 0;
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < 3; i++)
			{
				for (int x = 0; x < 4; ++x)
				{
					square[3][x] += square[i][x];
					square[i][x] = 0;
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i <4; i++)
			{
				for (int x = 3; x >0; --x)
				{
					square[i][0] += square[i][x];
					square[i][x] = 0;
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < 4; i++)
			{
				for (int x = 0; x < 3; ++x)
				{
					square[i][3] += square[i][x];
					square[i][x] = 0;
				}
			}
			break;
		}
		}
		for(int i  = 0;i<4;++i)
			for (int x = 0; x < 4; x++)
			{
				temp[i][x] = square[i][x];
			}
		break;
	}
	case 1:
	{
		for (int i = 0; i < 4; ++i)
			for (int x = 0; x < 4; ++x)
			{
				temp[x][i] = square[3-i][x];
			}
	}break;
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int x = 0; x < 4; x++)
		{
			if (temp[i][x] < 10)
				std::cout << temp[i][x] << "  ";
			else
				std::cout << temp[i][x] << " ";
		}
		std::cout << std::endl;
	}
}



	

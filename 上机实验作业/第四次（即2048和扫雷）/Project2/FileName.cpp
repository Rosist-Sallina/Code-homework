#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<string>
#include<tuple>

using namespace std;
tuple<int ,int , bool > input();

int main()
{
	tuple<int, int, bool> result = input();
	int N, random; bool flag;

	tie(N, random, flag) = result;

	if (!flag)
	{
		N = 4;
		random = 7;
	}
	int** matix = new int*[N];

	for (int i = 0; i < N; ++i)
	{
		matix[i] = new int[N];
	}
	for (int i = 0; i < N; ++i)
	{
		for (int x = 0; x < N; ++x)
		{
			matix[i][x] = 0;
		}
	}
	int** temp = new int* [N];
	for (int i = 0; i < N; ++i)
	{
		temp[i] = new int[N];
	}                               //定义动态数组

	cout << "Enter you love number:" << endl;

	random = (pow(N ,2) * random)/100;
	vector<int> n(random);
	vector<int> x(random);
	vector<int> y(random);

	if (flag) {
		for (int i = 0; i < random; ++i)
		{
			srand((unsigned)time(NULL) + (unsigned)rand());
			n[i] = (rand() % 4 + 1);
			srand((unsigned)time(NULL) + (unsigned)rand());
			x[i] = (rand() % (N));
			srand((unsigned)time(NULL) + (unsigned)rand());
			y[i] = (rand() % (N));
			for (int c = 0; c < i; ++c)
				while (x[i] == x[c] && y[i] == y[c])
				{
					srand((unsigned)time(NULL) + (unsigned)rand());
					x[i] = (rand() % (N ));
					srand((unsigned)time(NULL) + (unsigned)rand());
					y[i] = (rand() % (N ));
				}
			matix[x[i]][y[i]] = pow(2, n[i]);
		}
	}

	else
	{
		for (int i = 0; i < N; ++i)
		{
			srand((unsigned)time(NULL) + (unsigned)rand());
			n[i] = (rand() % 2 + 1);
			srand((unsigned)time(NULL) + (unsigned)rand());
			x[i] = (rand() % (N));
			srand((unsigned)time(NULL) + (unsigned)rand());
			y[i] = (rand() % (N));

			matix[x[i]][y[i]] = pow(2, n[i]);

			break;
		}
	}
	char order, to;
	

	for (int i = 0; i < N; ++i)
	{
		for (int x = 0; x < N; x++)
		{
			if (matix[i][x] < 10)
				std::cout << matix[i][x] << "    ";
			else if (10 <= matix[i][x] && matix[i][x] < 100)
				cout << matix[i][x] << "   ";
			else if (100 <= matix[i][x] && matix[i][x] < 1000)
				cout << matix[i][x] << "  ";
			else
				std::cout << matix[i][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------OUTPUT-------------------" << std::endl;

	ifstream file;
	file.open("cmd.txt");

	std::cout << "Please enter your order:" << std::endl;
	std::cout << "Loading"<<endl;

	if (file.is_open()) { //读取文件从而实现指令

		file.seekg(0, ios::end);
		streampos pos = file.tellg();
		file.seekg(0, ios::beg);

		if (pos == 0){
			for (int i = 0; i < N; i++)
				for (int x = 0; x < N; x++)
					matix[i][x] = '0';

			for (int i = 0; i < random; ++i)
			{
				srand((unsigned)time(NULL) + (unsigned)rand());
				n[i] = (rand() % (20));
				srand((unsigned)time(NULL) + (unsigned)rand());
				x[i] = (rand() % (N));
				srand((unsigned)time(NULL) + (unsigned)rand());
				y[i] = (rand() % (N));
				for (int c = 0; c < i; ++c)
					while (x[i] == x[c] && y[i] == y[c])
					{
						srand((unsigned)time(NULL) + (unsigned)rand());
						x[i] = (rand() % (N));
						srand((unsigned)time(NULL) + (unsigned)rand());
						y[i] = (rand() % (N));
					}
				matix[x[i]][y[i]] = n[i];
			}
			for (int i = 0; i < N; ++i)
			{
				for (int x = 0; x < N; x++)
				{
					if (temp[i][x] < 10)
						std::cout << temp[i][x] << "    ";
					else if (10 <= temp[i][x] && temp[i][x] < 100)
						cout << temp[i][x] << "   ";
					else if (100 <= temp[i][x] && temp[i][x] < 1000)
						cout << temp[i][x] << "  ";
					else
						std::cout << temp[i][x] << " ";
				}
				std::cout << std::endl;
			}
			cout << "按任意键退出" << endl;
			getchar();
			system("exit");
		}

		while (!file.eof()) {

			file >> order;      //对于压缩，1代表按行上，2代表按行下，N-代表列左，N为列右；对于旋转，1,2,N-1、,N，分别代表左右上下
			file >> to;

		


			if (order == 'Q'+48 || order == 'q'+48)
				break;
			switch (order)
			{
			case '0':
			{
				switch (to)
				{
				case '1':
				{
					for (int i = N - 1; i > 0; i--)
					{
						for (int x = 0; x < N; ++x)
						{
							matix[0][x] += matix[i][x];
							matix[i][x] = 0;
						}

					}
					break;
				}
				case '2':
				{
					for (int i = 0; i < N - 1; i++)
					{
						for (int x = 0; x < N; ++x)
						{
							matix[N - 1][x] += matix[i][x];
							matix[i][x] = 0;
						}
					}
					break;
				}
				case '3':
				{
					for (int i = 0; i < N; i++)
					{
						for (int x = N - 1; x > 0; --x)
						{
							matix[i][0] += matix[i][x];
							matix[i][x] = 0;
						}
					}
					break;
				}
				case '4':
				{
					for (int i = 0; i < N; i++)
					{
						for (int x = 0; x < N - 1; ++x)
						{
							matix[i][N - 1] += matix[i][x];
							matix[i][x] = 0;
						}
					}
					for (int i = 0; i < N; ++i)
						for (int x = 0; x < N; x++)
						{
							matix[i][x] = temp[i][x];
						}
					break;
				}
				}
				for (int i = 0; i < N; ++i)
					for (int x = 0; x < N; x++)
					{
						temp[i][x] = matix[i][x];
					}
				for (int i = 0; i < N; ++i)
					for (int x = 0; x < N; x++)
					{
						matix[i][x] = temp[i][x];
					}
				break;
			}
			case '1':
			{
				for (int i = 0; i < N; ++i)
					for (int x = 0; x < N; ++x)
					{
						temp[x][i] = matix[N - 1 - i][x];
					}
				for (int i = 0; i < N; ++i)
					for (int x = 0; x < N; x++)
					{
						matix[i][x] = temp[i][x];
					}
			}break;
			case '2':
			{
				for (int i = N - 2; i >= 0; i--)
				{
					for (int a = 0; a < N; a++)
					{
						if (matix[i + 1][a] == 0 && matix[i][a] != 0 && a <= N - 1)
							swap(matix[i][a], matix[i + 1][a]);
					}
				}
				for (int i = 0; i <= N - 2; i++)
				{
					for (int a = 0; a < N; a++)
					{
						if (matix[i + 1][a] == 0 && matix[i][a] != 0 && a <= N - 1)
							swap(matix[i][a], matix[i + 1][a]);
					}
				}
				for (int i = N - 2; i >= 0; i--)
				{
					for (int a = 0; a < N; a++)
					{
						if (matix[i + 1][a] == matix[i][a] && a <= N - 1)
						{
							matix[i][a] = 0;
							matix[i + 1][a] *= 2;
						}
					}
				}
				for (int i = N - 2; i >= 0; i--)
				{
					for (int a = 0; a < N; a++)
					{
						if (matix[i + 1][a] == 0 && matix[i][a] != 0 && a <= N - 1)
							swap(matix[i][a], matix[i + 1][a]);
					}
				}
				for (int i = 0; i <= N - 2; i++)
				{
					for (int a = 0; a < N; a++)
					{
						if (matix[i + 1][a] == 0 && matix[i][a] != 0 && a <= N - 1)
							swap(matix[i][a], matix[i + 1][a]);
					}
				}

				int w = 0;
				for (int i = 0; i < random; ++i)
				{
					srand((unsigned)time(NULL) + (unsigned)rand());
					n[i] = (rand() % (4 - 1) + 1);
					srand((unsigned)time(NULL) + (unsigned)rand());
					x[i] = (rand() % (N));
					srand((unsigned)time(NULL) + (unsigned)rand());
					y[i] = (rand() % (N));
					for (int c = 0; c < i; ++c)
					{
						if (matix[x[i]][y[i]] != 0)
						{
							srand((unsigned)time(NULL) + (unsigned)rand());
							x[i] = (rand() % 5);
							srand((unsigned)time(NULL) + (unsigned)rand());
							y[i] = (rand() % 5);
							matix[x[i]][y[i]] = pow(2, n[i]);
							w = 1;
							break;
						}
						else
							continue;
					}
					if (w)
						break;
				}
				for (int i = 0; i < N; ++i)
					for (int x = 0; x < N; x++)
					{
						temp[i][x] = matix[i][x];
					}
			}
			}
			for (int i = 0; i < N; ++i)
			{
				for (int x = 0; x < N; x++)
				{
					if (temp[i][x] < 10)
						std::cout << temp[i][x] << "    ";
					else if (10 <= temp[i][x] && temp[i][x] < 100)
						cout << temp[i][x] << "   ";
					else if (100 <= temp[i][x] && temp[i][x] < 1000)
						cout << temp[i][x] << "  ";
					else
						std::cout << temp[i][x] << " ";
				}
				std::cout << std::endl;

				
			}
			std::cout << std::endl<< "-------------------------------------------------分隔符-------------------------------------------------" << endl;
			for (int i = 0; i < N; ++i)
				for (int x = 0; x < N; x++)
				{
					matix[i][x] = temp[i][x];
				}
		}
	}

	else {                                             //指令读取失败，开始第二阶段行动
		char** arr = new char* [N];
		for (int i = 0; i < N; ++i)
		{
			arr[i] = new char[N];
		}

		if (flag)
		{
			for (int i = 0; i < random; ++i)
			{
				srand((unsigned)time(NULL) + (unsigned)rand());
				x[i] = (rand() % (N));
				srand((unsigned)time(NULL) + (unsigned)rand());
				y[i] = (rand() % (N));
				for (int c = 0; c < i; ++c)
					while (x[i] == x[c] && y[i] == y[c])
					{
						srand((unsigned)time(NULL) + (unsigned)rand());
						x[i] = (rand() % (N ));
						srand((unsigned)time(NULL) + (unsigned)rand());
						y[i] = (rand() % (N ));
					}
				arr[x[i]][y[i]] = '*';                 //随机填入‘*’
			}
		}

		else
		{
			for (int i = 0; i < N; ++i)
			{
				srand((unsigned)time(NULL) + (unsigned)rand());
				n[i] = (rand() % (2 - 1) + 1);
				srand((unsigned)time(NULL) + (unsigned)rand());
				x[i] = (rand() % (N ));
				srand((unsigned)time(NULL) + (unsigned)rand());
				y[i] = (rand() % (N ));

				arr[x[i]][y[i]] = '*';
				break;
			}
		}                       //读取文件失败时的matix*填入

		//开始数数               																							//---------------"*"统计功能上线----------------------

		int cont;
		for (int i = 0; i < N; i++)
		{
			for (int x = 0; x < N; x++)
			{
				cont = 0;
				if (arr[i][x] == '*')
					continue;
				for (int s = -1; s < 2; s++)
					for (int d = -1; d < 2; d++)
					{
						if ((i + s) < 0) {
							if ((x + d) < 0)
							{
								if (arr[i + s + 1][x + d + 1] == '*')
									continue;
							}
							else if ((x + d) > (N-1))
							{
								if (arr[i + s + 1][x + d - 1] == '*')
									continue;
							}
							else
								if (arr[i + s + 1][x + d] == '*')
									continue;
						}
						else if ((i + s) > (N - 1)) {
							if ((x + d) < 0)
							{
								if (arr[i + s - 1][x + d + 1] == '*')
									continue;
							}
							else if ((x + d) > (N - 1))
							{
								if (arr[i + s - 1][x + d - 1] == '*')
									continue;
							}
							else
								if (arr[i + s - 1][x + d] == '*')
									continue;
						}
						else {
							if ((x + d) < 0)
							{
								if (arr[i + s][x + d + 1] == '*')
									continue;
							}
							else if ((x + d) > (N - 1))
							{
								if (arr[i + s][x + d - 1] == '*')
									continue;
							}
							else
								if (arr[i + s][x + d] == '*')
									cont += 1;
						}
					}
				arr[i][x] = cont + 48;

			}
		}

		for (int p = 0; p < N; p++) {
			for (int q = 0; q < N; q++)
				cout << arr[p][q];
			cout << endl;
		}

	}
}
tuple<int , int , bool>  input()
{
	ifstream fin;
	fin.open("config.txt");

	int N;
	int rand;
	bool flag = 1;

	if (fin.is_open() != 0)
	{

		string judge;
		char a = '0';

		char c;
		fin >> c;

		if (!fin.eof()) {
			while (!fin.eof())
			{
				getline(fin, judge);
				while (judge[0] != '#')
				{
					getline(fin, judge);
				}
				do
				{
					getline(fin, judge);
					N = judge[7] - 48;
					if(fin.eof())
						break;
				} while (judge[0] != 'S');

				if (N <= 0 || N > 9 || fin.eof())
				{
					cout << "ERROR：配置文件格式不对" << endl;
					N = 4;
					flag = 0;
					rand = 0;
					break;
				}

				while (judge[0] != '#')
				{
					getline(fin, judge);
				}
				do
				{
					getline(fin, judge);
					if (judge.size() == 9)
						rand = judge[7] - 48;
					if (judge.size() == 10)
						rand = 10 * (judge[7] - 48) + judge[8] - 48;
					if (judge.size() == 11)
						rand = 100;
				} while (judge[0] != 'R');
				if (rand < 0 || rand > 100)
				{
					cout << "ERROR：配置文件格式不对" << endl;;
					N = 4;
					flag = 0;
				}      //感觉会出问题
			}
		}
		else
		{
			flag = 0;
		}
	}

	else
	{
		cout << "ERROR:配置文件格式不对" << endl;
		N = 4;
		flag = 0;
		rand = 0;
	}
	tuple<int, int, bool> result;
	result = make_tuple(N, rand, flag);
	fin.close();
	return result;
}

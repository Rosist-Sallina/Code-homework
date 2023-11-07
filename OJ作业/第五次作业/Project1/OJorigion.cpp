#include <iostream>
#include <cmath>
using namespace std;
void printPrime(int num);    // 未定义，需要完成

int main() {
	int n, i;
	cin >> n;
	for (int p = 1; p <= n; p++) {
		cin >> i;
		printPrime(i);
	}
	return 0;
}

void printPrime(int num)
{
	cout << num << "=";
	int number = num;
		for (int x = 2; x <= number; ++x)
		{	
			if (num % x == 0) {
				do
				{
					num /= x;
					cout << x;
					if (num != 1)
						cout << "*";
					if (num == 1)
						break;

				} while (num % x == 0);
			}
		}
		cout << endl;
	
}
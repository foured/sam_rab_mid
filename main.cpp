#include <iostream>

void f1(long long n);
void f2(long long n);
void f3(long long n);
void f4(long long n);
void f5(long long n);

long long pow(long long n, int s);

int main() {
	long long n;
	std::cin >> n;
	f1(n);
	f2(n);
	f3(n);
	f4(n);
	f5(n);
	return 0;
}

void f1(long long n) {
	int count = 0;
	while (n) {
		int  d = n % 10;
		if (d % 2 == 0 && d != 0) count++;
		n /= 10;
	}

	std::cout << count << std::endl;
	std::cout << " " << std::endl;
}
void f2(long long n) {
	int nulls = 0, min = 10, max = 0;

	while (n) {
		int d = n % 10;
		if (d == 0) nulls++;
		else if (min > d) min = d;
		if (max < d) max = d;
		n /= 10;
	}

	std::cout << (min + max) * nulls << std::endl;
	std::cout << " " << std::endl;
}
void f3(long long n) {
	if (n < 0) n *= -1;

	long long t = n;
	if (t / 10 == 0) {
		std::cout << -1 << std::endl;
		std::cout << " " << std::endl;
		return;
	}

	int idx, i = 0, min = 10, min1 = 10, num1 = n;
	while (n) {
		i++;
		int d = n % 10;
		if (d < min) {
			min = d;
			idx = i;
		}
		n /= 10;
	}
	i = 0;
	while (num1) {
		i++;
		int d = num1 % 10;
		if (d < min1 && i != idx) min1 = d;
		num1 /= 10;
	}
	std::cout << min1 << std::endl;
	std::cout << " " << std::endl;
	}
void f4(long long number) {
	long long a = 0, zeros = 0, n = number, sum = 0;
	bool isNotFirstZero = false;

	while (number) {
		int t = number % 5;
		sum += t;
		if (!isNotFirstZero && t == 0)
			zeros++;
		else
			isNotFirstZero = true;

		a = a * 10 + t;
		number /= 5;
	}
	long long m = 0;
	while (a)
	{
		m = m * 10 + a % 10;
		a /= 10;
	}

	for (int i = 0; i < zeros; i++) {
		m *= 10;
	}

	std::cout << m << std::endl; //числ в 5

	if (sum < 0) sum *= -1;
	std::cout << sum << std::endl;//сумма
	std::cout << " " << std::endl;
}
void f5(long long n) {
	long long a = 0, i = 0;

	while (n) {
		int d = n % 10;
		a += d * pow(3, i);
		n /= 10;
		i++;
	}

	std::cout << a << std::endl;
	std::cout << " " << std::endl;
}
long long pow(long long n, int s) {
	for (int i = 0; i < s; i++) {
		n *= n;
	}
	return n;
}
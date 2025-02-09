#include <iostream>
#include <vector>

using namespace std;


bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

vector<int> generatePrimes(int limit) {
	vector<int> primes;

	for (int i = 2; i <= limit; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}

	return primes;
}

int main() {
	int limit = 50;

	vector<int> primes = generatePrimes(limit);

	for (auto prime : primes) {
		cout << prime << " ";
	}

	cout << endl;

	return 0;
}
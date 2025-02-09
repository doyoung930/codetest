#include <iostream>

using namespace std;
int main() {
	int a = -1, b = 0, c = 0, d = 1;
	int result = ++a || ++b && c++ || d++;

	cout << result << endl;
}
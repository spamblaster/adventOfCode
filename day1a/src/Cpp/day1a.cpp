#include <iostream>

using namespace std;

long updateTotal(long newValue) {
	static long total=0;

	total+=newValue;
	return total;
}

int main(int argc, char ** argv) {
	long number, total;
	bool done = false;
	while (!done) {
		cin >> number;
		if (cin.eof()) {
			done = true;
		} else {
			cout << "Read number [" << number << "]";
			total = updateTotal(number);
			cout << "Total [" << total << "]" << endl;
		}
	}
	cout << "Total: " << total << endl;

	exit(0);
}

#include <iostream>

using namespace std;

long int convert(long int num){

	long int count = 0;
	while(num > 0){

		if (num%2 == 1)
			count++;
		
		num = num/2;
	}

	return count;
}

int main() {
	long int num, testcase, count;

	cin >> testcase;

	while(testcase--){
		cin >> num;
		count = convert(num);
		cout << count << endl;
	}
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	vector<int> intObj;
	for (int i = 0; i < 5; i++) {
		intObj.push_back(rand()%10);
	}

	vector<int>::iterator iter;
	for (iter = intObj.begin(); iter != intObj.end(); iter++){
		cout << *iter << endl;
	}

	vector<char> charObj;
	cout << "Enter 5 chars:\n";
	for (int i = 0; i < 5; i++) {
		char a;
		cin >> a;
		charObj.push_back(a);
	}
	vector<char>::iterator iter2;
	for (iter2 = charObj.begin(); iter2 != charObj.end(); iter2++) {
		cout << *iter2 << endl;
	}

	cout << "First vector without first element:\n";
	intObj.erase(intObj.begin());
	for (iter = intObj.begin(); iter != intObj.end(); iter++) {
		cout << *iter << endl;
	}
	cout << "\nMax Element = "<< *max_element(intObj.begin(), intObj.end());
	cin.get();

	return 0;
}

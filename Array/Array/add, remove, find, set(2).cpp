#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arrsize;
	  
public:
	Array(int n) {
		arrsize = n;
		arr = new int[n];
		for (int i = 0; i < arrsize; i++) {
			arr[i] = 0;
		}		
	}
	void add(int i, int z){
		for (int j = arrsize - 1; j >= i; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[i] = z;
	} // 유념할 점은, j를 증가시키며 연산을 하게 된다면 j + 1번째 요소가 이미 j번째 요소가 되어버리므로
	// j + 2번쨰 요소 또한 j번째 요소가 되어버린다. 따라서 뒤에서부터 연산을 해야 한다.

	void remove(int i) {
		for (int j = i + 1; j < arrsize; j++) {
			arr[j - 1] = arr[j];
		}
		arr[arrsize - 1] = 0;
	} // add와 반대로, 뒤에서부터 연산을 하면 모두 같은 요소가 들어가게 된다. 따라서 앞부터 연산을 진행해야 한다.

	void set(int i, int z) {
		arr[i] = z;
	}

	void find(int z) {
		for (int i = 0; i < arrsize; i++) {
			if (arr[i] == z) {
				cout << i << endl;
				return;
			}
		} // z를 찾았다면 인덱스를 출력하고 함수를 종료한다

	cout << -1 << endl; // 못찾았다면 for문을 빠져나와 -1을 출력한다
	}

	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t, n;

	cin >> t >> n;

	Array ar(n);

	for (int i = 0; i < t; i++) {
		string s;
		int index, val;
		cin >> s;
		if (s == "add") {
			cin >> index >> val;
			ar.add(index, val);
		}
		if (s == "remove") {
			cin >> index;
			ar.remove(index);
		}
		if (s == "set") {
			cin >> index >> val;
			ar.set(index, val);
		}
		if (s == "find") {
			cin >> val;
			ar.find(val);
		}
		if (s == "print") {
			ar.print();
		}
	}
}
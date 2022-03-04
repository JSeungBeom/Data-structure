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
	} // ������ ����, j�� ������Ű�� ������ �ϰ� �ȴٸ� j + 1��° ��Ұ� �̹� j��° ��Ұ� �Ǿ�����Ƿ�
	// j + 2���� ��� ���� j��° ��Ұ� �Ǿ������. ���� �ڿ������� ������ �ؾ� �Ѵ�.

	void remove(int i) {
		for (int j = i + 1; j < arrsize; j++) {
			arr[j - 1] = arr[j];
		}
		arr[arrsize - 1] = 0;
	} // add�� �ݴ��, �ڿ������� ������ �ϸ� ��� ���� ��Ұ� ���� �ȴ�. ���� �պ��� ������ �����ؾ� �Ѵ�.

	void set(int i, int z) {
		arr[i] = z;
	}

	void find(int z) {
		for (int i = 0; i < arrsize; i++) {
			if (arr[i] == z) {
				cout << i << endl;
				return;
			}
		} // z�� ã�Ҵٸ� �ε����� ����ϰ� �Լ��� �����Ѵ�

	cout << -1 << endl; // ��ã�Ҵٸ� for���� �������� -1�� ����Ѵ�
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
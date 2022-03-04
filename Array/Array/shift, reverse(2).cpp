#include <iostream>

using namespace std;
class Array {
private:
	int* arr;
	int arrsize;

public:
	Array(int n) {
		int elem;
		arrsize = n;
		arr = new int[arrsize]; // arrsize ��ŭ�� ���� �迭 ����
		for (int i = 0; i < arrsize; i++) {
			cin >> elem;
			arr[i] = elem;
		} // ������ �Լ����� �迭�� �� ��ҵ��� �Է¹ް� �ʱ�ȭ
	}

	void shift(int d) {
		int* temp = new int[d];
		for (int i = 0; i < d; i++) {
			temp[i] = arr[arrsize - d + i];
		} // shift �ϰ� �Ǹ�, ������ ����� ��Ұ� �����.
		// �� ��, �� ��ҵ��� �ٸ� �ӽ� ���� �迭�� ����
		for (int i = arrsize - d - 1; i >= 0; i--) {
			arr[i + d] = arr[i];
		} // i�� �ִ� ��ҵ��� ���� ���������� d��ŭ �ű��
		// ���������� �ű� ��, ó������ �ű�� ��Ұ� �ߺ��Ǿ ���Ƿ� ���������� ��Ҹ� ä����� �Ѵ�

		for (int i = 0; i < d; i++) {
			arr[i] = temp[i];
		} // shift�ϰ� ���� index�� �ӽ� �����س��� �迭�� ��ҵ�� ä���ش�
	} // ȯ����������Ʈ ����

	void reverse(int a, int b) {
		for (int i = a; i <= b; i++) {
			int temp = arr[i]; // �� ��Ҹ� �ٲ� ��, ���� �����ϰ� ���� �� �ڸ��� �ִ� ��Ҹ� ������� ���ϹǷ�,
			// int�� ������ ����� �ӽ÷� �����Ѵ�
			arr[i] = arr[b];
			arr[b] = temp;
			b--;
		} // a ~ b������ ��ҵ��� ���� a�� b�ڸ��� �ٲ��ְ� a + 1�� b - 1 �ڸ��� �ٲ��ָ� b�� �ϳ��� ���� for���� �������´�
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
		int d, a, b;
		cin >> s;
		if (s == "shift") {
			cin >> d;
			ar.shift(d);
		}
		if (s == "reverse") {
			cin >> a >> b;
			ar.reverse(a, b);
		}
		if (s == "print") {
			ar.print();
		}
	}
	
}
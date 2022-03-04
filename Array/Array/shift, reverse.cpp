#include <iostream>

using namespace std;

int main() {
	int* arr;
	int arrsize;

	int t, n;

	cin >> t >> n;
	arrsize = n;
	arr = new int[arrsize]; // �Է¹��� n�� ũ�⸦ ���� ���� �迭 ����

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} // �迭�� �� ���Ҹ� �Է¹޴´�

	for (int k = 0; k < t; k++) {
		string s;
		cin >> s;
		int d, i, j;
		if (s == "shift") {
			cin >> d;
			int* temp = new int[d]; // �迭�� ������ ��� ���Ҹ� �ӽ� ������ ���� �迭
			for (int k = 0; k < d; k++) {
				temp[k] = arr[k];
			} // ������ ��� ���ҵ��� temp�� �ӽ� ����
			for (int k = d; k < arrsize; k++) {
				arr[k - d] = arr[k];
			} // ���ҵ��� �Է¹��� d��ŭ �������� ����Ʈ ����
			for (int k = 0; k < d; k++) {
				arr[arrsize - d + k] = temp[k];
			} // ������ ��� �迭�� �ٽ� ���������� �̵��ϹǷ�, temp�� ����� �迭�� �ٽ� �Ű��ش�

			cout << endl;
		} // ȯ����������Ʈ����

		else if (s == "reverse") {
			cin >> i >> j;
			for (int k = i; k < j; k++) {
				int temp; // index�� ���Ҹ� �ӽ������� ����
				temp = arr[k]; // k��° index�� ���Ҹ� temp�� ����
				arr[k] = arr[j]; // k��° index�� ���Ҹ� j��° index�� ���ҿ� ����
				arr[j] = temp; // �����س��� k��° ���Ҹ� j��° index�� ����
				j--; // i �� j, i + 1�� j - 1... ��ȯ
			}
			cout << endl;
		} // ������ ����
		else if (s == "print") {
			for (int k = 0; k < n; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		} // �迭�� ��� ���Ҹ� ���

		else
			break;
	}


	return 0;
}
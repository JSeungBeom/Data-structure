#include <iostream>

using namespace std;

int main() {
	int* arr;
	int arrsize;

	int t, n;

	cin >> t >> n;
	arrsize = n;
	arr = new int[arrsize]; // 입력받은 n의 크기를 갖는 동적 배열 생성

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} // 배열의 각 원소를 입력받는다

	for (int k = 0; k < t; k++) {
		string s;
		cin >> s;
		int d, i, j;
		if (s == "shift") {
			cin >> d;
			int* temp = new int[d]; // 배열의 범위를 벗어난 원소를 임시 저장할 동적 배열
			for (int k = 0; k < d; k++) {
				temp[k] = arr[k];
			} // 범위를 벗어난 원소들을 temp에 임시 저장
			for (int k = d; k < arrsize; k++) {
				arr[k - d] = arr[k];
			} // 원소들을 입력받은 d만큼 좌측으로 시프트 연산
			for (int k = 0; k < d; k++) {
				arr[arrsize - d + k] = temp[k];
			} // 범위를 벗어난 배열은 다시 오른쪽으로 이동하므로, temp에 저장된 배열을 다시 옮겨준다

			cout << endl;
		} // 환형좌측시프트연산

		else if (s == "reverse") {
			cin >> i >> j;
			for (int k = i; k < j; k++) {
				int temp; // index에 원소를 임시저장할 변수
				temp = arr[k]; // k번째 index의 원소를 temp에 저장
				arr[k] = arr[j]; // k번째 index의 원소를 j번째 index의 원소와 변경
				arr[j] = temp; // 저장해놨던 k번째 원소를 j번째 index에 저장
				j--; // i 와 j, i + 1과 j - 1... 교환
			}
			cout << endl;
		} // 리버스 연산
		else if (s == "print") {
			for (int k = 0; k < n; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		} // 배열의 모든 원소를 출력

		else
			break;
	}


	return 0;
}
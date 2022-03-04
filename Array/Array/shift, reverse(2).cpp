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
		arr = new int[arrsize]; // arrsize 만큼의 동적 배열 생성
		for (int i = 0; i < arrsize; i++) {
			cin >> elem;
			arr[i] = elem;
		} // 생성자 함수에서 배열에 들어갈 요소들을 입력받고 초기화
	}

	void shift(int d) {
		int* temp = new int[d];
		for (int i = 0; i < d; i++) {
			temp[i] = arr[arrsize - d + i];
		} // shift 하게 되면, 범위를 벗어나는 요소가 생긴다.
		// 이 때, 이 요소들을 다른 임시 동적 배열에 저장
		for (int i = arrsize - d - 1; i >= 0; i--) {
			arr[i + d] = arr[i];
		} // i에 있는 요소들을 각각 오른쪽으로 d만큼 옮긴다
		// 오른쪽으로 옮길 때, 처음부터 옮기면 요소가 중복되어서 들어가므로 끝에서부터 요소를 채워줘야 한다

		for (int i = 0; i < d; i++) {
			arr[i] = temp[i];
		} // shift하고 남은 index에 임시 저장해놨던 배열의 요소들로 채워준다
	} // 환형우측시프트 연산

	void reverse(int a, int b) {
		for (int i = a; i <= b; i++) {
			int temp = arr[i]; // 두 요소를 바꿀 때, 먼저 대입하고 나면 그 자리에 있던 요소를 기억하지 못하므로,
			// int형 변수를 만들어 임시로 저장한다
			arr[i] = arr[b];
			arr[b] = temp;
			b--;
		} // a ~ b까지의 요소들을 각각 a와 b자리를 바꿔주고 a + 1과 b - 1 자리를 바꿔주며 b를 하나씩 빼서 for문을 빠져나온다
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
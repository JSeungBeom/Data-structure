#include <iostream>

using namespace std;

int* prefixAverage_Linear(int x[], int n) {
	int* arr = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
		arr[i] = sum / (i + 1);
	}
	return arr;
} // 시간 복잡도 O(n) 시간에 수행되는 prefixAverage 연산

int main() {
	int x[10] = { 1, 2, 3, 4,5,6,7,8,9,10 };

	int* a = prefixAverage_Linear(x, 10);

	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
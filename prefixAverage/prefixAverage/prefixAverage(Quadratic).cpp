#include <iostream>

using namespace std;

int* prefixAverage_Quadratic(int x[], int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int sum = x[0];
		for (int j = 1; j <= i; j++) {
			sum += x[j];
		}
		arr[i] = sum / (i + 1);
	}
	return arr;
} // O(n^2) 의 시간 복잡도를 가지는 prefixAverage 연산

int main() {
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int *a = prefixAverage_Quadratic(x, 10);

	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
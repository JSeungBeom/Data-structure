#include <iostream>

using namespace std;

template <class T> // template을 이용해, generic한 class를 구현
class stackarr {
private:
	int t; // stack의 맨 위(top) 인덱스를 저장
	T* arr; // stack의 데이터들을 저장할 동적 배열

public:
	stackarr(int n) {
		t = -1; // 데이터를 삽입하면 0번째 index가 t가 되므로, 초기값은 -1
		arr = new T[n]; // arr의 동적 할당
		for (int i = 0; i < n; i++) {
			arr[i] = NULL;
		}
	} // constructor, 멤버 변수의 초기화

	int size() {
		return t + 1;
	} // 사이즈를 리턴하는 함수, t가 맨 위 index이므로, t + 1이 스택의 사이즈이다

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	}

	T top() {
		return arr[t];
	} // stack의 맨 위 데이터를 반환하는 함수

	void push(T x) {
		if (t + 1 > sizeof(arr)) {
			cout << "Stack overflow" << endl;
			return;
		} // 삽입하고자 하는 위치가, 배열의 크기를 초과하는 경우 exception 처리
		else {
			arr[t + 1] = x;
			t++;
		} // t의 index 위에 데이터 x를 추가하고, t의 위치를 1 증가
	} // stack의 맨 위에 데이터를 추가하는 함수

	T pop() {
		if (empty()) {
			cout << "Stack empty" << endl;
			exit(1);
		} // 스택이 비어있을 경우, pop을 할 수 없으므로 exception 처리

		else {
			t--; 
			return arr[t + 1];
		} // 맨 위의 데이터를 삭제하므로, t의 위치를 1 감소시키고, t + 1 (원래 t)의 데이터를 반환
	}

	
};

int main() {
	stackarr<int> s(10);
	// stackarr의 추가할 데이터를 int 타입으로 하고, 객체 s를 선언

	s.push(3);
	s.push(3);
	s.push(4);
	cout << s.pop() << endl;
	cout << s.top() << endl;
	s.push(9);
	cout << s.top() << endl;;
}

/*
배열을 이용한 Stack의 구현에서는, 모든 기능들이 O(1)의 시간복잡도를 갖고,
n개의 배열에서 O(N)의 공간복잡도를 갖기 때문에, 효율적인 자료 구조라고 할 수 있다

하지만, stack의 최대 크기를 처음에 정해주어야 하고, 이를 늘릴 수 없기 때문에
최대 크기를 넘어서는 full stack 상태에 데이터를 삽입하려 하면, exception이 발생할 수 있다
*/
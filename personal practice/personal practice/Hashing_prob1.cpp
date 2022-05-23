#include <iostream>

#define NOITEM 0
#define ISITEM 1 
#define AVAILABLE 2

using namespace std;

// key, value를 저장할 entry
struct entry {
	int key; 
	string value;
	int valid; // 현재 entry의 상태

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	// 셀에서 엔트리를 지우더라도, 탐색은 가능해야함
	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFnc(int key) { // 해쉬 함수
		return key % capacity;
	}

public:
	hashTable(int N) { // 생성자
		capacity = N;
		table = new entry[capacity];
	}
	// 해쉬테이블에 key, value의 엔트리를 삽입
	void put(int key, string value) {
		int index = hashFnc(key); // 인덱스는 해시함수의 결과값
		int probe = 1; // probe 횟수

		// 테이블의 셀이 아이템이 있고, probe 횟수가 capacity보다 작은 동안 탐색
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFnc(index + 1); // Linear Probing
			probe++;
		}

		if (probe > capacity)
			return;
		cout << probe << endl;
		table[index] = entry(key, value);
		return;
	}

	// 해시테이블에서 key값을 갖는 엔트리 삭제
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				cout << table[index].value << endl;
				table[index].erase();
				return;
			}
			index = hashFnc(index + 1);
			probe++;
		}

		cout << "None" << endl;
		return;
	}
	
	string find(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFnc(index + 1);
			probe++;
		}
		return "None";
	}

	void vacant() {
		int count = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM)
				count++;
		}
		cout << count << endl;
	}
 };

int main() {
	int t, n;
	cin >> t >> n;
	hashTable h(n);
	
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int k;
		string v;
		if (s == "put") {
			cin >> k >> v;
			h.put(k, v);
		}
		if (s == "erase") {
			cin >> k;
			h.erase(k);
		}
		if (s == "find") {
			cin >> k;
			cout << h.find(k) << endl;
		}
		if (s == "vacant") {
			h.vacant();
		}
	}
}


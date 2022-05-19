#include <iostream>

using namespace std;

#define NOITEM 0 // 엔트리에 한번도 삽입 되지 않은 상태
#define ISITEM 1 // 엔트리에 값이 삽입된 상태
#define AVAILABLE 2 // 엔트리에 이전에 값이 있었으나, 지금은 지워진 상태

struct entry {
	int key; // 엔트리의 key 값
	string value; // 엔트리의 value
	int valid; // 엔트리의 상태

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

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
public:
	hashTable(int N);
	void put(int key, string value);
	void erase(int key);
	string find(int key);
private:
	entry* table;
	int capacity;
	int hashFnc(int key);
};

hashTable::hashTable(int N) {
	capacity = N;
	table = new entry[capacity];
	return;
}

// 해쉬 함수
int hashTable::hashFnc(int key) {
	return key % capacity;
}

// 해쉬 테이블에 (key, value) entry 삽입 
void hashTable::put(int key, string value) {
	int index = hashFnc(key); // 해쉬 함수의 결과 값 -> index
	int probe = 1; // probe 횟수를 저장

	// 빈 인덱스를 발견할 때까지 탐색, 모든 해쉬테이블을 확인할 때 까지
	while (table[index].valid == ISITEM && probe <= capacity) {
		index = hashFnc(index + 1); // 선형 조사법을 사용한 충돌 관리
		probe++;
	}

	if (probe > capacity) // 해쉬테이블이 가득 찬 경우
		return;
	table[index] = entry(key, value);
	return;
}

// key 값을 갖는 엔트리를 테이블에서 삭제
void hashTable::erase(int key) {
	int index = hashFnc(key);
	int probe = 1;

	// 셀에 엔트리가 있거나, 엔트리가 있었다면 계속 탐색
	if (table[index].valid != NOITEM && probe <= capacity) {
		// 셀에 엔트리가 있고, 키 값이 주어진 키 값과 같다면	
		if (table[index].valid == ISITEM && table[index].key == key) {
			table[index].erase(); // 데이터를 삭제(삭제된 데이터임을 표시)
			return;
		}
		index = hashFnc(index + 1);
		probe++;
	}

	return;
}

string hashTable::find(int key) {
	int index = hashFnc(key);
	int probe = 1;

	// 셀에 엔트리가 있거나, 있었던 상태인 동안 탐색
	while (table[index].valid != NOITEM && probe <= capacity) {
		// 키 값이 같다면 해당 value를 리턴
		if (table[index].valid == ISITEM && table[index].key == key) {
			return table[index].value;
		}
		index = hashFnc(index + 1);
		probe++;
	}
	return "";
}

int main() {
	hashTable ht(30);
	ht.put(3, "hi");
	ht.put(5, "hello");
	ht.put(7, "ok");

	cout << ht.find(7) << endl;
}
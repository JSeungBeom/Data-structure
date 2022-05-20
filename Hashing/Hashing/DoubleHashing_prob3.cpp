#include <iostream>

using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

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

	// 삽입이 가능한 셀이면서, 탐색이 중단되지 않는 상태
	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int divisor;
	int hashFnc(int key){
		return key % capacity;
	}

	int hashFnc2(int key) {
		return divisor - (key % divisor);
	}

public:
	hashTable(int N, int M) {
		capacity = N;
		divisor = M;
		table = new entry[capacity];
		return;
	}

	void put(int key, string value) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid == ISITEM && probe <= capacity) {
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}

		if (probe > capacity) {
			return;
		}
		cout << probe << endl;
		table[idx] = entry(key, value);
		return;
	}

	void remove(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				cout << table[idx].value << endl;
				table[idx].erase();
				return;
			}
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}
		cout << "None" << endl;
		return;
	}

	string find(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				return table[idx].value;
			}

			idx = hashFnc(idx + hashFnc2(key));
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
	int t, n, m;
	cin >> t >> n >> m;

	hashTable ht(n, m);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int k;
		string v;
		if (s == "put") {
			cin >> k >> v;
			ht.put(k, v);
		}
		if (s == "find") {
			cin >> k;
			cout << ht.find(k) << endl;
		}
		if (s == "erase") {
			cin >> k;
			ht.remove(k);
		}
		if (s == "vacant") {
			ht.vacant();
		}
	}
}
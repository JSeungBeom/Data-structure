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

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFnc(int key) {
		return key % capacity;
	}

public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
		return;
	}

	void put(int key, string value) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid == ISITEM && probe <= capacity) {
			idx = hashFnc(idx + 1);
			probe++;
		}

		if (probe > capacity)
			return;
		cout << probe << endl;

		table[idx] = entry(key, value);
	}

	void erase(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				cout << table[idx].value << endl;
				table[idx].erase();
				return;
			}
			idx = hashFnc(idx + 1);
			probe++;
		}

		cout << "None" << endl;
	}

	string find(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key)
				return table[idx].value;
			idx = hashFnc(idx + 1);
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
	hashTable ht(n);
	
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int k;
		string v;
		if (s == "put") {
			cin >> k >> v;
			ht.put(k, v);
		}
		if (s == "erase") {
			cin >> k;
			ht.erase(k);
		}
		if (s == "find") {
			cin >> k;
			cout << ht.find(k) << endl;
		}
		if (s == "vacant") {
			ht.vacant();
		}
	}
}
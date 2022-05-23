#include <iostream>

#define ISITEM 0
#define NOITEM 1
#define AVAILABLE 2

using namespace std;

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
	int divisor;
	int hashFnc(int key) {
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
	}

	void put(int key, string value) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid == ISITEM && probe <= capacity) {
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}

		if (probe > capacity)
			return;
		table[idx] = entry(key, value);
		cout << probe << endl;
		return;
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
	hashTable h(n, m);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int k;
		string v;
		if (s == "put") {
			cin >> k >> v;
			h.put(k, v);
		}
		if (s == "find") {
			cin >> k;
			cout << h.find(k) << endl;
		}
		if (s == "erase") {
			cin >> k;
			h.erase(k);
		}
		if (s == "vacant") {
			h.vacant();
		}
	}
}
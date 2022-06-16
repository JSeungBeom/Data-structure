#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

#include <iostream>

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
	int hashFnc(int key) {
		return key % capacity;
	}

public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
	}

	void put(int key, string value) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFnc(index + 1);
			probe++;
		}

		cout << probe << endl;
		if (probe > capacity)
			return;
		table[index] = entry(key, value);
	}

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
		int cnt = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM) {
				cnt++;
			}
		}
		cout << cnt << endl;
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
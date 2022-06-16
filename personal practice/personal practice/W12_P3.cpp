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

		if (probe > capacity) {
			return;
		}

		table[idx] = entry(key, value);
		cout << probe << endl;
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
	}

	void find(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				cout << table[idx].value << endl;
				return;
			}
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}

		cout << "None" << endl;
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
	int t, n, m;
	cin >> t >> n >> m;
	hashTable h(n, m);
	while (t--) {
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
			h.find(k);
		}
		if (s == "vacant") {
			h.vacant();
		}
	}
}
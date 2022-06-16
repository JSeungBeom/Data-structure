#include <iostream>

using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
#define ABSENT 3
#define PRESENT 4

struct nentry {
	string key;
	int value;
	int valid;
	int status;

	nentry() {
		key = "";
		value = 0;
		valid = NOITEM;
		status = ABSENT;
	}

	nentry(string key, int value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
		status = ABSENT;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

struct entry {
	int key;
	string value;
	int valid;
	int status;

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
		status = ABSENT;
	}

	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
		status = ABSENT;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	nentry* table2;
	int capacity;
	int hashFnc(int key) {
		return key % capacity;
	}

	int hashFnc(string key) {
		int k = 0;
		for (int i = 0; i < key.length(); i++) {
			k += (key[i] - 97) * pow(26, i);
		}
		return k % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
		table2 = new nentry[capacity];
	}

	void put(int k, string v) {
		int idx = hashFnc(k);
		int probe = 1;

		while (table[idx].valid == ISITEM && probe <= capacity) {
			idx = idx + 1;
			probe++;
		}

		if (probe > capacity)
			return;

		table[idx] = entry(k, v);
	}

	void put(string k, int v) {
		int idx = hashFnc(k);
		int probe = 1;

		while (table2[idx].valid == ISITEM && probe <= capacity) {
			idx = idx + 1;
			probe++;
		}

		if (probe > capacity)
			return;

		table2[idx] = nentry(k, v);
	}

	string remove(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				table[idx].erase();
				return table[idx].value;
			}
			idx = idx + 1;
			probe++;
		}
	}

	void remove(string key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table2[idx].valid != NOITEM && probe <= capacity) {
			if (table2[idx].valid == ISITEM && table2[idx].key == key) {
				table2[idx].erase();
			}
			idx = idx + 1;
			probe++;
		}
	}

	void name(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				cout << table[idx].value << endl;
				return;
			}
		}
	}

	void present(string key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table2[idx].valid != NOITEM && probe <= capacity) {
			if (table2[idx].valid == ISITEM && table2[idx].key == key) {
				cout << table2[idx].value << endl;
				table2[idx].status = PRESENT;
				return;
			}
		}

		cout << "Invalid" << endl;
	}

	void absent(string key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table2[idx].valid != NOITEM && probe <= capacity) {
			if (table2[idx].valid == ISITEM && table2[idx].key == key) {
				cout << table2[idx].value << endl;
				table2[idx].status = ABSENT;
				return;
			}
		}

		cout << "Invalid" << endl;
	}

	void print() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++) {
			if (table2[i].valid == ISITEM && table2[i].status == PRESENT) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
};

int main() {
	int t; 
	cin >> t;
	
	hashTable h(200003);
	while (t--) {
		string s;
		cin >> s;
		int x;
		string y;
		if (s == "add") {
			cin >> x >> y;
			h.put(x, y);
			h.put(y, x);
		}
		if (s == "delete") {
			cin >> x;
			string a = h.remove(x);
			h.remove(a);
		}
		if (s == "absent") {
			cin >> y;
			h.absent(y);
		}
		if (s == "present") {
			cin >> y;
			h.present(y);
		}
		if (s == "name") {
			cin >> x;
			h.name(x);
		}
	}
	h.print();
}
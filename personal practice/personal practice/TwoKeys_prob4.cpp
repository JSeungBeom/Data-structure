#include <iostream>
#include <math.h>	

using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
#define ABSENT 3
#define PRESENT 4

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
	entry* table1;
	entry* table2;
	int capacity;
	int hashFnc(int key) {
		return key % capacity;
	}

	int hashFnc(string name) {
		int hashval = 0;
		for (int i = 0; i < name.length(); i++) {
			hashval += (name[i] - 97) * (int)pow(26, i);
		}
		return hashval % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		table1 = new entry[capacity];
		table2 = new entry[capacity];
		return;
	}

	void put1(int key, string value) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table1[idx].valid == ISITEM && probe <= capacity) {
			idx = hashFnc(idx + 1);
			probe++;
		}

		if (probe > capacity)
			return;

		table1[idx] = entry(key, value);
		return;
	}

	void put2(int key, string value) {
		int idx = hashFnc(value);
		int probe = 1;

		while (table2[idx].valid == ISITEM && probe <= capacity) {
			idx = hashFnc(idx + 1);
			probe++;
		}

		if (probe > capacity)
			return;

		table2[idx] = entry(key, value);
		return;
	}

	void remove1(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table1[idx].valid != NOITEM && probe <= capacity) {
			if (table1[idx].valid == ISITEM && table1[idx].key == key) {
				remove2(table1[idx].value);
				table1[idx].erase();
				return;
			}

			idx = hashFnc(idx + 1);
			probe++;
		}

		return;
	}

	void remove2(string value) {
		int idx = hashFnc(value);
		int probe = 1;

		while (table2[idx].valid != NOITEM && probe <= capacity) {
			if (table2[idx].valid == ISITEM && table2[idx].value == value) {
				table2[idx].erase();
				return;
			}

			idx = hashFnc(idx + 1);
			probe++;
		}

		return;
	}

	void find(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table1[idx].valid != NOITEM && probe <= capacity) {
			if (table1[idx].valid == ISITEM && table1[idx].key == key) {
				cout << table1[idx].value << endl;
				return;
			}

			idx = hashFnc(idx + 1);
			probe++;
		}

		return;
	}


	void present(string value) {
		int idx = hashFnc(value);
		int probe = 1;

		while (table2[idx].valid != NOITEM && probe <= capacity) {
			if (table2[idx].valid == ISITEM && table2[idx].value == value) {
				table2[idx].status = PRESENT;
				cout << table2[idx].key << endl;
				return;
			}

			idx = hashFnc(idx + 1);
			probe++;
		}
		cout << "Invalid" << endl;
		return;
	}

	void absent(string value) {
		int idx = hashFnc(value);
		int probe = 1;

		while (table2[idx].valid != NOITEM && probe <= capacity) {
			if (table2[idx].valid == ISITEM && table2[idx].value == value) {
				table2[idx].status = ABSENT;
				cout << table2[idx].key << endl;
				return;
			}

			idx = hashFnc(idx + 1);
			probe++;
		}
		cout << "Invalid" << endl;
		return;
	}

	void print_present() {
		int count = 0;
		for (int i = 0; i < capacity; i++) {
			if (table2[i].status == PRESENT && table2[i].valid == ISITEM)
				count++;
		}
		cout << count << endl;
	}
};

int main() {
	int t;
	cin >> t;
	hashTable ht(200003);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int k;
		string v;
		if (s == "add") {
			cin >> k >> v;
			ht.put1(k, v);
			ht.put2(k, v);
		}
		if (s == "delete") {
			cin >> k;
			ht.remove1(k);
		}
		if (s == "name") {
			cin >> k;
			ht.find(k);
		}
		if (s == "present") {
			cin >> v;
			ht.present(v);
		}
		if (s == "absent") {
			cin >> v;
			ht.absent(v);
		}
	}
	ht.print_present();
} 
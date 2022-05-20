#include <iostream>
#include <math.h>

using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
#define LOGIN 3
#define LOGOUT 4

struct entry {
	string key;
	string value;
	int valid;
	int status;

	entry() {
		key = "";
		value = "";
		valid = NOITEM;
		status = LOGOUT;
	}

	entry(string key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
		status = LOGOUT;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFnc(string key) {
		int hashval = 0;
		for (int i = 0; i < key.length(); i++) {
			hashval += (key[i] - 97) * (int)pow(26, i);
		}
		return hashval % capacity;
	}

	int hashFnc(int key) {
		return key % capacity;
	}

public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
		return;
	}

	void signup(string key, string value) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid == ISITEM && probe <= capacity) {
			if (table[idx].key == key) {
				cout << "Invalid" << endl;
				return;
			}
			idx = hashFnc(idx + 1);
			probe++;
		}

		if (probe > capacity)
			return;
		table[idx] = entry(key, value);
		cout << "Submit" << endl;
		return;
	}

	void login(string key, string value) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				if (table[idx].value == value) {
					if (table[idx].status == LOGOUT) {
						cout << "Submit" << endl;
						table[idx].status = LOGIN;
						return;
					}
					else {
						cout << "Quit" << endl;
						return;
					}
				}
				else {
					cout << "Invalid" << endl;
					return;
				}
			}
			idx = hashFnc(idx + 1);
			probe++;
		}
		cout << "Invalid" << endl;
		return;
	}

	void logout(string key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= capacity) {
			if (table[idx].key == key) {
				table[idx].status = LOGOUT;
				cout << "Submit" << endl;
				return;
			}

			idx = hashFnc(idx + 1);
			probe++;
		}

		return;
	}
};

int main() {
	int t;
	cin >> t;

	hashTable ht(200003);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		string k, v;
		if (s == "signup") {
			cin >> k >> v;
			ht.signup(k, v);
		}
		if (s == "login") {
			cin >> k >> v;
			ht.login(k, v);
		}
		if (s == "logout") {
			cin >> k;
			ht.logout(k);
		}
	}
}
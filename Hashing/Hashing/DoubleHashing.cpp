#include <iostream>

using namespace std;

#define ISITEM 1
#define AVAILABLE 2
#define NOITEM 3

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
	// ù��° �ؽ� �Լ�
	int hashFnc(int key) {
		return key % capacity;
	}

	// �ι�° �ؽ� �Լ�
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
		int index = hashFnc(key); // ù ��° ���� ��ġ�� ù ��° �ؽ��Լ��� �����
		int probe = 1; // probe Ƚ�� ����

		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFnc(index + hashFnc2(key)); // �ε����� �ι� ° �ؽ��Լ��� �������ŭ �����ϸ� Ž��
			probe++;
		}

		if (probe > capacity) {
			return;
		}
		table[index] = entry(key, value);
		return;
	}

	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].erase();
				return;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}

		return;
	}

	string find(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key)
				return table[index].value;
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		return "";
	}
};

int main() {

}
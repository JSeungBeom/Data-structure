#include <iostream>
#include <vector>	

using namespace std;

struct vertex {
	int vertexId; // ������ ���� ��ȣ
	int matrixId; // edge matrix���� ������ �ε���

	vertex* prev;
	vertex* next;

	vertex() {
		vertexId = matrixId = -1;
		prev = next = NULL;
	}

	vertex(int vertexId) {
		this->vertexId = vertexId;
		matrixId = -1;
		prev = next = NULL;
	}
};

// vertex object �������� ���� ���� ����Ʈ�� ����
class vertexList {
private:
	vertex* header;
	vertex* trailer;

public:
	vertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		header->matrixId = -1;
		trailer->prev = header;
	}

	// Vertex object ����, �� �ڿ� ����
	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		// ����� �� �ڿ� �߰��ϹǷ�, ���� ������ 1 ������ matrixId 
		newVertex->matrixId = trailer->prev->matrixId + 1;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}

	// Vertex object ����
	void eraseVertex(vertex* delVertex) {
		// ������ ���� �ڿ� �ִ� ����� matrix id�� ����
		for (vertex* cur = delVertex; cur != trailer; cur = cur->next) {
			cur->matrixId--;
		}

		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}

	// Vertex object�� �ּҸ� ���� ������ ã��
	vertex* findVertex(int vertexId) {
		for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
			if (cur->vertexId == vertexId) {
				return cur;
			}
		}

		return NULL;
	}
};

struct edge {
	edge* next; // edge list���� ������ ��ġ ����
	edge* prev;

	vertex* src; // �� �� ������ ��ġ ����
	vertex* dst;

	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}

	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};

class edgeList {
private:
	edge* header;
	edge* trailer;

public:
	edgeList() {
		header = new edge();
		trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}

	// edge object�� �������� ����
	void insertEdge(edge* newEdge) {
		newEdge->prev = trailer->prev;
		newEdge->next = trailer;
		trailer->prev->next = newEdge;
		trailer->prev = newEdge;
	}

	void eraseEdge(edge* delEdge) {
		delEdge->prev->next = delEdge->next;
		delEdge->next->prev = delEdge->prev;
		delete delEdge;
	}
};

class graph {
private:
	vector<vector<edge*>> edgeMatrix; // ���� ���, edge�� � ������ �����ϴ��� ���� ����
	vertexList vList;
	edgeList eList;

public:
	void insertVertex(int vertexId) {
		// �����ϰ��� �ϴ� vertex�� �̹� �����ϴ� ���
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}

		vertex* newVertex = new vertex(vertexId); // �� vertex �Ҵ�

		// ���ο� vertex�� ���� ���� �߰�
		for (int i = 0; i < edgeMatrix.size(); i++) {
			edgeMatrix[i].push_back(NULL);
		}

		// ���ο� vertex�� ���� ���� �߰�
		edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));

		// vertexList�� �� vertex �߰�
		vList.insertVertex(newVertex);
	}

	// vertex ����
	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId);

		if (delVertex == NULL) { // �����Ϸ��� vertex ���� X
			return;
		}

		int matrixId = delVertex->matrixId;

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (i != matrixId) { // self-loop�� �ƴ� ��
				if (edgeMatrix[i][matrixId] != NULL) { // i�� matrixId���� �ּҰ��� �����ٸ�
					eList.eraseEdge(edgeMatrix[i][matrixId]); // �ش� edge ����
				}
				edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId); // ����� �ش� �� ����
			}
		}

		edgeMatrix.erase(edgeMatrix.begin() + matrixId); // ����� �ش� �� ����
		vList.eraseVertex(delVertex); // vertex ����
	}

	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);

		if (src == NULL || dst == NULL) // ������ ���ٸ�
			return;

		int srcMatrixId = src->matrixId; // ���� ������ matrixId
		int dstMatrixId = dst->matrixId; // ���� ������ matrixId

		// �̹� edge�� �����Ѵٸ�
		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL ||
			edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
			cout << "Exist" << endl;
			return;
		}

		edge* newEdge = new edge(src, dst); // ���ο� edge object ����
		eList.insertEdge(newEdge); // edge List�� edge ����
		// src, dst�� �ش��ϴ� ��Ŀ� ���ο� edge�� �ּ� ����
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;

	}

	// edge ����
	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);

		if (src == NULL || dst == NULL)
			return;

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		// src, dst�� �ش��ϴ� ��Ŀ��� edge ������ ���� ���
		if (edgeMatrix[srcMatrixId][dstMatrixId] == NULL ||
			edgeMatrix[dstMatrixId][srcMatrixId] == NULL) {
			cout << "None" << endl;
			return;
		}

		eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
	}
};

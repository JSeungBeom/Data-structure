#include <iostream>
#include <vector>

using namespace std;

struct vertex {
	int vertexId;
	int matrixId;
	vertex* next;
	vertex* prev;

	vertex() {
		vertexId = matrixId = -1;
		next = prev = NULL;
	}

	vertex(int vertexId) {
		this->vertexId = vertexId;
		matrixId = -1;
		next = prev = NULL;
	}
};

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

	void insertVertex(vertex* newVertex) {
		newVertex->next = trailer;
		newVertex->prev = trailer->prev;
		newVertex->matrixId = trailer->prev->matrixId + 1;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}

	void eraseVertex(vertex* delVertex) {
		for (vertex* cur = delVertex; cur != trailer; cur = cur->next) {
			cur->matrixId--;
		}

		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;

		delete delVertex;
	}

	vertex* findVertex(int vertexId) {
		for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
			if (cur->vertexId == vertexId)
				return cur;
		}

		return NULL;
	}
};

struct edge {
	vertex* src;
	vertex* dst;
	int weight;

	edge* next;
	edge* prev;

	edge() {
		src = dst = NULL;
		next = prev = NULL;
		weight = -1;
	}

	edge(vertex* src, vertex* dst, int weight) {
		this->src = src;
		this->dst = dst;
		this->weight = weight;
		next = prev = NULL;
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

	void insertEdge(edge* newEdge) {
		newEdge->next = trailer;
		newEdge->prev = trailer->prev;
		trailer->prev->next = newEdge;
		trailer->prev = newEdge;
	}

	void eraseEdge(edge* delEdge) {
		delEdge->next->prev = delEdge->prev;
		delEdge->prev->next = delEdge->next;
		delete delEdge;
	}
};

class graph {
private:
	vertexList vList;
	edgeList eList;
	vector<vector<edge*>> edgeMatrix;

public:
	void insertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL)
			return;

		vertex* newVertex = new vertex(vertexId);

		for (int i = 0; i < edgeMatrix.size(); i++) {
			edgeMatrix[i].push_back(NULL);
		}

		edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));

		vList.insertVertex(newVertex);
	}

	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId);
		if (delVertex == NULL)
			return;

		int matrixId = delVertex->matrixId;

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (i != matrixId) {
				if (edgeMatrix[i][matrixId] != NULL) {
					eList.eraseEdge(edgeMatrix[i][matrixId]);
				}
				edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId);
			}
		}

		edgeMatrix.erase(edgeMatrix.begin() + matrixId);
		vList.eraseVertex(delVertex);
	}

	void insertEdge(int srcVertexId, int dstVertexId, int weight) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);
		if (src == NULL || dst == NULL)
			return;

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL
			|| edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
			return;
		}

		edge* newEdge = new edge(src, dst, weight);
		eList.insertEdge(newEdge);
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;
	}

	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);

		if (src == NULL || dst == NULL)
			return;

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] == NULL ||
			edgeMatrix[dstMatrixId][srcMatrixId] == NULL) {
			return;
		}

		eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
	}

	void findIncident1(int srcId) {
		bool arr[500] = { false };
		bool noFriend = true;
		
		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (edgeMatrix[srcId][i] != NULL && edgeMatrix[srcId][i]->weight == 1) { // 인접행렬 찾기
				for (int j = 0; j < edgeMatrix.size(); j++) {
					if (edgeMatrix[i][j] != NULL &&
						edgeMatrix[srcId][j] == NULL && srcId != j &&
						edgeMatrix[i][j]->weight == 1) {
						arr[j] = true;
					}
				}
			}
		}

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (edgeMatrix[srcId][i] != NULL) {
				if (arr[i])
					arr[i] = false;
			}
		}
		for (int i = 0; i < 500; i++) {
			if (arr[i]) {
				cout << i + 1 << ' ';
				noFriend = false;
			}
		}

		if (noFriend) cout << 0;
		cout << endl;
	}

	void findIncident2(int srcId) {
		bool arr[500] = { false };
		bool noFriend = true;

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (edgeMatrix[srcId][i] != NULL && edgeMatrix[srcId][i]->weight == 1) { // 인접행렬 찾기
				for (int j = 0; j < edgeMatrix.size(); j++) {
					if (edgeMatrix[i][j] != NULL &&
						edgeMatrix[srcId][j] == NULL && srcId != j &&
						edgeMatrix[i][j]->weight == 2) {
						arr[j] = true;
					}
				}
			}
		}

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (edgeMatrix[srcId][i] != NULL) {
				if (arr[i])
					arr[i] = false;
			}
		}
		for (int i = 0; i < 500; i++) {
			if (arr[i]) {
				cout << i + 1 << ' ';
				noFriend = false;
			}
		}

		if (noFriend) cout << 0;
		cout << endl;
	}
};

int main() {
	int n, m;

	cin >> n >> m;

	graph g;

	for (int i = 0; i < n; i++) {
		g.insertVertex(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int st;
			cin >> st;
			if(st != 0)
			g.insertEdge(i, j, st);
		}
	}
	
	while (m--) {
		int k, f;
		cin >> k >> f;
		if (f == 0) {
			g.findIncident1(k - 1);
		}
		if (f == 1) {
			g.findIncident2(k - 1);
		}
	}
}
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
		delVertex->next->prev = delVertex->prev;
		delVertex->prev->next = delVertex->next;
		delete delVertex;
	}

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
	vertex* src;
	vertex* dst;

	edge* next;
	edge* prev;

	edge() {
		src = dst = NULL;
		next = prev = NULL;
	}


	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
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
		delEdge->prev->next = delEdge->next;
		delEdge->next->prev = delEdge->prev;
		delete delEdge;
	}
};

class graph {
private:
	vertexList vList;
	edgeList eList;
	vector <vector<edge*>> edgeMatrix;

public:
	void insertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}

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
				if (edgeMatrix[i][matrixId] != NULL)
					eList.eraseEdge(edgeMatrix[i][matrixId]);
			}
			edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId);
		}

		edgeMatrix.erase(edgeMatrix.begin() + matrixId);
		vList.eraseVertex(delVertex);
	}

	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);
		if (src == NULL || dst == NULL)
			return;

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL
			|| edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
				cout << "Exist" << endl;
				return;
		}

		edge* newEdge = new edge(src, dst);
		eList.insertEdge(newEdge);
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;
	}

	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] == NULL ||
			edgeMatrix[dstMatrixId][srcMatrixId] == NULL) {
				cout << "None" << endl;
				return;
		}

		eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
	}

	void SumAdjacentNode(int vertexId) {
		vertex* cur = vList.findVertex(vertexId);
		int sum = 0;

		int matrixId = cur->matrixId;

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (i != matrixId) {
				if (edgeMatrix[i][matrixId] != NULL) {
					if (edgeMatrix[i][matrixId]->src->vertexId == vertexId) {
						sum += edgeMatrix[i][matrixId]->dst->vertexId;
					}
					else {
						sum += edgeMatrix[i][matrixId]->src->vertexId;
					}
				}
			}
		}

		if (sum == 0) {
			cout << "None" << endl;
			return;
		}

		cout << sum << endl;
	}
};

int main() {
	int t, n;

	cin >> t >> n;
	graph g;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		g.insertVertex(x);
	}

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		int src, dst;
		if (s == "insertEdge") {
			cin >> src >> dst;
			g.insertEdge(src, dst);
		}
		if (s == "eraseEdge") {
			cin >> src >> dst;
			g.eraseEdge(src, dst);
		}
		if (s == "SumAdjacentNode") {
			cin >> src;
			g.SumAdjacentNode(src);
		}
	}
}
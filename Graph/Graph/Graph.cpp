#include <iostream>
#include <vector>	

using namespace std;

struct vertex {
	int vertexId; // 정점의 고유 번호
	int matrixId; // edge matrix에서 정점의 인덱스

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

// vertex object 시퀀스를 이중 연결 리스트로 구현
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

	// Vertex object 삽입, 맨 뒤에 삽입
	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		// 행렬의 맨 뒤에 추가하므로, 이전 셀보다 1 증가한 matrixId 
		newVertex->matrixId = trailer->prev->matrixId + 1;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}

	// Vertex object 삭제
	void eraseVertex(vertex* delVertex) {
		// 삭제할 정점 뒤에 있던 행렬의 matrix id를 감소
		for (vertex* cur = delVertex; cur != trailer; cur = cur->next) {
			cur->matrixId--;
		}

		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}

	// Vertex object의 주소를 고유 값으로 찾기
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
	edge* next; // edge list에서 서로의 위치 저장
	edge* prev;

	vertex* src; // 양 끝 정점의 위치 저장
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

	// edge object를 시퀀스에 삽입
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
	vector<vector<edge*>> edgeMatrix; // 이중 행렬, edge가 어떤 정점을 연결하는지 정보 저장
	vertexList vList;
	edgeList eList;

public:
	void insertVertex(int vertexId) {
		// 삽입하고자 하는 vertex가 이미 존재하는 경우
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}

		vertex* newVertex = new vertex(vertexId); // 새 vertex 할당

		// 새로운 vertex를 위한 열을 추가
		for (int i = 0; i < edgeMatrix.size(); i++) {
			edgeMatrix[i].push_back(NULL);
		}

		// 새로운 vertex를 위한 행을 추가
		edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));

		// vertexList에 새 vertex 추가
		vList.insertVertex(newVertex);
	}

	// vertex 삭제
	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId);

		if (delVertex == NULL) { // 삭제하려는 vertex 존재 X
			return;
		}

		int matrixId = delVertex->matrixId;

		for (int i = 0; i < edgeMatrix.size(); i++) {
			if (i != matrixId) { // self-loop가 아닐 때
				if (edgeMatrix[i][matrixId] != NULL) { // i행 matrixId열이 주소값을 가졌다면
					eList.eraseEdge(edgeMatrix[i][matrixId]); // 해당 edge 삭제
				}
				edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId); // 행렬의 해당 열 삭제
			}
		}

		edgeMatrix.erase(edgeMatrix.begin() + matrixId); // 행렬의 해당 행 삭제
		vList.eraseVertex(delVertex); // vertex 삭제
	}

	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);

		if (src == NULL || dst == NULL) // 정점이 없다면
			return;

		int srcMatrixId = src->matrixId; // 시작 정점의 matrixId
		int dstMatrixId = dst->matrixId; // 도착 정점의 matrixId

		// 이미 edge가 존재한다면
		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL ||
			edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
			cout << "Exist" << endl;
			return;
		}

		edge* newEdge = new edge(src, dst); // 새로운 edge object 생성
		eList.insertEdge(newEdge); // edge List에 edge 삽입
		// src, dst에 해당하는 행렬에 새로운 edge의 주소 삽입
		edgeMatrix[srcMatrixId][dstMatrixId] =
			edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;

	}

	// edge 삭제
	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);

		if (src == NULL || dst == NULL)
			return;

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		// src, dst에 해당하는 행렬에서 edge 정보가 없는 경우
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

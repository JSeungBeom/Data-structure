#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct vertex;
struct edge;
struct edgeNode;
class vertexList;
class edgeList {
public:
	edgeList();
	void insertEdge(edge* newEdge);
	void eraseEdge(edgeNode* delEdge);
	edgeNode* header;
	edgeNode* trailer;
};

// 정점 구조체
struct vertex {
	bool visit;
	int vertexId; // 정점의 고유 번호
	int degree; // 정점과 연결된 간선의 수
	vertex* prev;
	vertex* next;
	edgeList incidentEdge; // 정점과 연결된 간선 리스트


	vertex() {
		vertexId = -1;
		degree = 0;
		prev = next = NULL;
		visit = false;
	}

	vertex(int vertexId) {
		this->vertexId = vertexId;
		degree = 0;
		prev = next = NULL;
		visit = false;
	}
};

// 간선의 정보를 저장하는 구조체
struct edge {
	vertex* srcVertex; // 시작 정점
	vertex* dstVertex; // 도착 정점
	edgeNode* srcIncidentEdgeNode; // 시작 정점의 연결 간선 리스트에서의 주소
	edgeNode* dstIncidentEdgeNode; // 도착 정점의 연결 간선 리스트에서의 주소
	edgeNode* totalEdgeNode; // 그래프의 정점 리스트에서의 주소
	edge() {
		srcVertex = dstVertex = NULL;
	}
	edge(vertex* src, vertex* dst) {
		this->srcVertex = src;
		this->dstVertex = dst;
	}
};

// 간선 리스트를 구성하는 노드
struct edgeNode {
	edge* edgeInfo; // 간선의 정보
	edgeNode* prev;
	edgeNode* next;
	edgeNode() { // 기본 생성자
		edgeInfo = NULL;
		prev = next = NULL;
	}
	edgeNode(edge* edgeInfo) { // 생성자
		this->edgeInfo = edgeInfo;
		prev = next = NULL;
	}
};

// 정점을 저장하는 리스트
class vertexList {
private:
	vertex* header;
	vertex* trailer;
public:
	vector<int> order;

	vertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}
	// 정점 삽입
	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}
	// 정점 삭제
	void eraseVertex(vertex* delVertex) {
		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}
	// vertexId에 해당하는 vertex 탐색
	vertex* findVertex(int vertexId) {
		for (vertex* curVertex = header->next; curVertex != trailer; curVertex = curVertex->next) {
			if (curVertex->vertexId == vertexId) {
				return curVertex;
			}
		}

		return NULL;
	}
};

// 간선을 저장하는 이중 연결 리스트
edgeList::edgeList() {
	header = new edgeNode();
	trailer = new edgeNode();
	header->next = trailer;
	trailer->prev = header;
}

// 간선 삽입
void edgeList::insertEdge(edge* newEdge) {
	edgeNode* newEdgeNode = new edgeNode(newEdge);
	newEdgeNode->prev = trailer->prev;
	newEdgeNode->next = trailer;
	trailer->prev->next = newEdgeNode;
	trailer->prev = newEdgeNode;
}

// 간선 삭제
void edgeList::eraseEdge(edgeNode* delEdge) {
	delEdge->prev->next = delEdge->next;
	delEdge->next->prev = delEdge->prev;
	delete delEdge;
}

class graph {
private:
	int count = 0;
	vertexList vList;
	edgeList eList;

public:
	vector<int> order;
	// 그래프에서 두 정점 src, dst를 잇는 간선을 찾는 함수
	edge* findEdge(vertex* srcVertex, vertex* dstVertex) {
		if (srcVertex->degree < dstVertex->degree) { // 두 정점 중 연결된 간선의 개수가 적은 정점을 기준으로 탐색
			for (edgeNode* curEdge = srcVertex->incidentEdge.header->next; curEdge != srcVertex->incidentEdge.trailer; curEdge = curEdge->next) {
				if (curEdge->edgeInfo->dstVertex == dstVertex) {
					return curEdge->edgeInfo;
				}
			}
		}
		else {
			for (edgeNode* curEdge = dstVertex->incidentEdge.header->next; curEdge != dstVertex->incidentEdge.trailer; curEdge = curEdge->next) {
				if (curEdge->edgeInfo->dstVertex == srcVertex) {
					return curEdge->edgeInfo;
				}
			}
		}
		return NULL;
	}
	// 정점 삽입
	void insertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}

		vertex* newVertex = new vertex(vertexId);
		vList.insertVertex(newVertex);
	}
	// 정점 삭제
	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId); // 정점 리스트에서 탐색
		if (delVertex == NULL) {
			return;
		}

		// 삭제하려는 정점과 연결된 간선 삭제
		for (edgeNode* curEdge = delVertex->incidentEdge.header->next; curEdge != delVertex->incidentEdge.trailer; curEdge->next) {
			eList.eraseEdge(curEdge->edgeInfo->totalEdgeNode); // 그래프의 간선 리스트에서 간선 삭제
			if (curEdge == curEdge->edgeInfo->srcIncidentEdgeNode) { // 반대편 정점의 연결 간선 리스트에서 간선 삭제
				curEdge->edgeInfo->dstVertex->incidentEdge.eraseEdge(curEdge->edgeInfo->dstIncidentEdgeNode);
			}
			else {
				curEdge->edgeInfo->srcVertex->incidentEdge.eraseEdge(curEdge->edgeInfo->srcIncidentEdgeNode);
			}
			delete curEdge->edgeInfo;
		}

		vList.eraseVertex(delVertex); // 정점 리스트에서 정점 삭제
	}

	// 두 정점 src, dst를 잇는 간선을 삽입
	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* srcVertex = vList.findVertex(srcVertexId);
		vertex* dstVertex = vList.findVertex(dstVertexId);
		if (srcVertex == NULL || dstVertex == NULL) {
			return;
		}
		if (findEdge(srcVertex, dstVertex) != NULL) {
			return;
		}

		edge* newEdge = new edge(srcVertex, dstVertex);

		srcVertex->incidentEdge.insertEdge(newEdge); // 3개의 간선 리스트에 간선 삽입
		dstVertex->incidentEdge.insertEdge(newEdge);
		eList.insertEdge(newEdge);
		newEdge->srcIncidentEdgeNode = srcVertex->incidentEdge.trailer->prev; // 3개의 간선 리스트에 저장된 주소를 간선 정보에 저장
		newEdge->dstIncidentEdgeNode = dstVertex->incidentEdge.trailer->prev;
		newEdge->totalEdgeNode = eList.trailer->prev;
		srcVertex->degree++; // 각 정점의 degree 증가
		dstVertex->degree++;
	}

	// 두 정점 src, dst를 잇는 간선을 삭제
	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* srcVertex = vList.findVertex(srcVertexId);
		vertex* dstVertex = vList.findVertex(dstVertexId);
		if (srcVertex == NULL || dstVertex == NULL) {
			return;
		}

		edge* delEdge = findEdge(srcVertex, dstVertex);

		if (delEdge == NULL) {
			return;
		}

		srcVertex->incidentEdge.eraseEdge(delEdge->srcIncidentEdgeNode); // 3개의 간선에서 간선 삭제
		dstVertex->incidentEdge.eraseEdge(delEdge->dstIncidentEdgeNode);
		eList.eraseEdge(delEdge->totalEdgeNode);
		srcVertex->degree--; // 각 정점에 연결된 degree 감소
		dstVertex->degree--;
		delete delEdge;
	}

	void DFS(int vertexId) {
		vertex* curVertex = vList.findVertex(vertexId);
		curVertex->visit = true;
		count++;
		if (count % 2 != 0)
			cout << curVertex->vertexId << " ";
		for (edgeNode* e = curVertex->incidentEdge.header->next; e != curVertex->incidentEdge.trailer; e = e->next) {
			if (curVertex == e->edgeInfo->srcVertex) {
				if (e->edgeInfo->dstVertex->visit != true) {
					DFS(e->edgeInfo->dstVertex->vertexId);
				}
			}
			else {
				if (e->edgeInfo->srcVertex->visit != true) {
					DFS(e->edgeInfo->srcVertex->vertexId);
				}
			}
		}
	}
};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		graph g;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			g.insertVertex(a);
			g.insertVertex(b);
			g.insertEdge(a, b);
		}
		g.DFS(1);
		cout << endl;
	}
}
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

// ���� ����ü
struct vertex {
	bool visit;
	int vertexId; // ������ ���� ��ȣ
	int degree; // ������ ����� ������ ��
	vertex* prev;
	vertex* next;
	edgeList incidentEdge; // ������ ����� ���� ����Ʈ


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

// ������ ������ �����ϴ� ����ü
struct edge {
	vertex* srcVertex; // ���� ����
	vertex* dstVertex; // ���� ����
	edgeNode* srcIncidentEdgeNode; // ���� ������ ���� ���� ����Ʈ������ �ּ�
	edgeNode* dstIncidentEdgeNode; // ���� ������ ���� ���� ����Ʈ������ �ּ�
	edgeNode* totalEdgeNode; // �׷����� ���� ����Ʈ������ �ּ�
	edge() {
		srcVertex = dstVertex = NULL;
	}
	edge(vertex* src, vertex* dst) {
		this->srcVertex = src;
		this->dstVertex = dst;
	}
};

// ���� ����Ʈ�� �����ϴ� ���
struct edgeNode {
	edge* edgeInfo; // ������ ����
	edgeNode* prev;
	edgeNode* next;
	edgeNode() { // �⺻ ������
		edgeInfo = NULL;
		prev = next = NULL;
	}
	edgeNode(edge* edgeInfo) { // ������
		this->edgeInfo = edgeInfo;
		prev = next = NULL;
	}
};

// ������ �����ϴ� ����Ʈ
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
	// ���� ����
	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}
	// ���� ����
	void eraseVertex(vertex* delVertex) {
		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}
	// vertexId�� �ش��ϴ� vertex Ž��
	vertex* findVertex(int vertexId) {
		for (vertex* curVertex = header->next; curVertex != trailer; curVertex = curVertex->next) {
			if (curVertex->vertexId == vertexId) {
				return curVertex;
			}
		}

		return NULL;
	}
};

// ������ �����ϴ� ���� ���� ����Ʈ
edgeList::edgeList() {
	header = new edgeNode();
	trailer = new edgeNode();
	header->next = trailer;
	trailer->prev = header;
}

// ���� ����
void edgeList::insertEdge(edge* newEdge) {
	edgeNode* newEdgeNode = new edgeNode(newEdge);
	newEdgeNode->prev = trailer->prev;
	newEdgeNode->next = trailer;
	trailer->prev->next = newEdgeNode;
	trailer->prev = newEdgeNode;
}

// ���� ����
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
	// �׷������� �� ���� src, dst�� �մ� ������ ã�� �Լ�
	edge* findEdge(vertex* srcVertex, vertex* dstVertex) {
		if (srcVertex->degree < dstVertex->degree) { // �� ���� �� ����� ������ ������ ���� ������ �������� Ž��
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
	// ���� ����
	void insertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}

		vertex* newVertex = new vertex(vertexId);
		vList.insertVertex(newVertex);
	}
	// ���� ����
	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId); // ���� ����Ʈ���� Ž��
		if (delVertex == NULL) {
			return;
		}

		// �����Ϸ��� ������ ����� ���� ����
		for (edgeNode* curEdge = delVertex->incidentEdge.header->next; curEdge != delVertex->incidentEdge.trailer; curEdge->next) {
			eList.eraseEdge(curEdge->edgeInfo->totalEdgeNode); // �׷����� ���� ����Ʈ���� ���� ����
			if (curEdge == curEdge->edgeInfo->srcIncidentEdgeNode) { // �ݴ��� ������ ���� ���� ����Ʈ���� ���� ����
				curEdge->edgeInfo->dstVertex->incidentEdge.eraseEdge(curEdge->edgeInfo->dstIncidentEdgeNode);
			}
			else {
				curEdge->edgeInfo->srcVertex->incidentEdge.eraseEdge(curEdge->edgeInfo->srcIncidentEdgeNode);
			}
			delete curEdge->edgeInfo;
		}

		vList.eraseVertex(delVertex); // ���� ����Ʈ���� ���� ����
	}

	// �� ���� src, dst�� �մ� ������ ����
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

		srcVertex->incidentEdge.insertEdge(newEdge); // 3���� ���� ����Ʈ�� ���� ����
		dstVertex->incidentEdge.insertEdge(newEdge);
		eList.insertEdge(newEdge);
		newEdge->srcIncidentEdgeNode = srcVertex->incidentEdge.trailer->prev; // 3���� ���� ����Ʈ�� ����� �ּҸ� ���� ������ ����
		newEdge->dstIncidentEdgeNode = dstVertex->incidentEdge.trailer->prev;
		newEdge->totalEdgeNode = eList.trailer->prev;
		srcVertex->degree++; // �� ������ degree ����
		dstVertex->degree++;
	}

	// �� ���� src, dst�� �մ� ������ ����
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

		srcVertex->incidentEdge.eraseEdge(delEdge->srcIncidentEdgeNode); // 3���� �������� ���� ����
		dstVertex->incidentEdge.eraseEdge(delEdge->dstIncidentEdgeNode);
		eList.eraseEdge(delEdge->totalEdgeNode);
		srcVertex->degree--; // �� ������ ����� degree ����
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
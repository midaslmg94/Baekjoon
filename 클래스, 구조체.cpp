#include<iostream>
using namespace std;
class Edge {
public:
	int node[2]; // �������
	int distance=0;
	Edge(int a, int b, int distance) {// ������ �����ε�
		/* this�� ���°�� */
		this->node[0] = a;
		this->node[1] = b;
		this->distance;
	}
	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};
/*operator�� ���� �ʴ� ��� ���Լ�*/
bool cmp(const Edge& a, const Edge& b) {
	return a.distance < b.distance;
}
int main() {

}
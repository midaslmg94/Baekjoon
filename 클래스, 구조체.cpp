#include<iostream>
using namespace std;
class Edge {
public:
	int node[2]; // 멤버변수
	int distance=0;
	Edge(int a, int b, int distance) {// 생성자 오버로딩
		/* this를 쓰는경우 */
		this->node[0] = a;
		this->node[1] = b;
		this->distance;
	}
	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};
/*operator를 쓰지 않는 경우 비교함수*/
bool cmp(const Edge& a, const Edge& b) {
	return a.distance < b.distance;
}
int main() {

}
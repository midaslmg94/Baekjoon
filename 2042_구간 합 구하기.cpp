#include<iostream>
#include<algorithm>
const int MAX = 1'000'000;
using namespace std;
long long arr[MAX]; // 입력 배열 : 인덱스가 0부터 시작
long long tree[4 * MAX]; // 세그먼트 트리 배열 : 인덱스(노드)가 1부터 시작
int N, M, K;
long long make_segment_tree(int start = 0, int end = N - 1, int node = 1) { // 이렇게 해주면 파라미터 값이 없어도 자동으로 값이 들어온다.
	if (start == end) { // node가 리프노드인 경우
		return tree[node] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		/*
			노드의 왼쪽 자식 노드 = node*2
			노드의 오른쪽 자식 노드 = node*2+1
 		*/
		tree[node] = make_segment_tree(start, mid, node * 2)+make_segment_tree(mid+1,end,(node*2)+1); 
		return tree[node];
	}
}
void update_segment_tree(int start, int end, int node, int index, long long diff) {// index는 바꿀 숫자의 위치 ex) 세번째 원소를 5로 바꾼다 
	if (index<start || index>end) return; // 범위 밖에 있는 경우 : 세번째 원소가 범위에 포함되지 않음 ex) 1~2 또는 4~6 까지의 구간합을 구한 노드 
	tree[node] = tree[node] + diff; // 원소 갱신
	if (start != end) {
		int mid = (start + end) / 2;
		update_segment_tree(start, mid, node * 2, index, diff);
		update_segment_tree(mid + 1, end, (node * 2) + 1, index, diff);
	}
}
/*
	노드가 담당하는 구간 : start~end
	합을 구해야 하는 구간 : left ~ right
*/
long long sum_segment_tree(int start, int end, int node, int left, int right) { 
	// 범위 밖에 있는 경우
	if (left > end || right < start) { 
		return 0; 
	}
	// 범위 안에 있는 경우
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (left + right) / 2;
	return sum_segment_tree(start, mid, node * 2, left, right) + sum_segment_tree(mid + 1, end, (node * 2) + 1, left, right);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	make_segment_tree();

	for (int i = 0; i < M + K; i++) {		
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) { // b번째 수를 c로 바꿈
			b -= b;
			long long diff = c - arr[b]; // 변한 숫자 차이
			update_segment_tree(0,N-1,1,b,diff);
		}
		else {// b번째 수부터 c번째 수까지의 합을 구하여 출력
			cout << sum_segment_tree(0, N - 1, 1, b-1, c-1)<<"\n";
		}
	}
}
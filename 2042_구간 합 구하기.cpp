#include<iostream>
#include<algorithm>
const int MAX = 1'000'000;
using namespace std;
long long arr[MAX]; // �Է� �迭 : �ε����� 0���� ����
long long tree[4 * MAX]; // ���׸�Ʈ Ʈ�� �迭 : �ε���(���)�� 1���� ����
int N, M, K;
long long make_segment_tree(int start = 0, int end = N - 1, int node = 1) { // �̷��� ���ָ� �Ķ���� ���� ��� �ڵ����� ���� ���´�.
	if (start == end) { // node�� ��������� ���
		return tree[node] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		/*
			����� ���� �ڽ� ��� = node*2
			����� ������ �ڽ� ��� = node*2+1
 		*/
		tree[node] = make_segment_tree(start, mid, node * 2)+make_segment_tree(mid+1,end,(node*2)+1); 
		return tree[node];
	}
}
void update_segment_tree(int start, int end, int node, int index, long long diff) {// index�� �ٲ� ������ ��ġ ex) ����° ���Ҹ� 5�� �ٲ۴� 
	if (index<start || index>end) return; // ���� �ۿ� �ִ� ��� : ����° ���Ұ� ������ ���Ե��� ���� ex) 1~2 �Ǵ� 4~6 ������ �������� ���� ��� 
	tree[node] = tree[node] + diff; // ���� ����
	if (start != end) {
		int mid = (start + end) / 2;
		update_segment_tree(start, mid, node * 2, index, diff);
		update_segment_tree(mid + 1, end, (node * 2) + 1, index, diff);
	}
}
/*
	��尡 ����ϴ� ���� : start~end
	���� ���ؾ� �ϴ� ���� : left ~ right
*/
long long sum_segment_tree(int start, int end, int node, int left, int right) { 
	// ���� �ۿ� �ִ� ���
	if (left > end || right < start) { 
		return 0; 
	}
	// ���� �ȿ� �ִ� ���
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
		if (a == 1) { // b��° ���� c�� �ٲ�
			b -= b;
			long long diff = c - arr[b]; // ���� ���� ����
			update_segment_tree(0,N-1,1,b,diff);
		}
		else {// b��° ������ c��° �������� ���� ���Ͽ� ���
			cout << sum_segment_tree(0, N - 1, 1, b-1, c-1)<<"\n";
		}
	}
}
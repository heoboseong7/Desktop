/*
** 20175969 허보성
** 자료구조 프로그래밍 과제 02
** 5/30 수정
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *nodePtr;
typedef struct node {
	nodePtr father;
	nodePtr mother;
	char _name;
}node;

typedef struct path { //root에서부터 원하는 값이 있는 node까지의 길을 저장
	long long int path; //이동한 방향을 저장하는 스택 비트가 0이면 왼쪽(father) 1이면 오른쪽(mother)방향으로 이동했음을 의미. 
	int n; // 이동한 방향의 개수
}path;

nodePtr root = NULL;
char input[6];

int getinput();
void append(char parent, char relation, char child); //입력이 M, F일 때 트리를 확장해주는 함수
void preorder_print(nodePtr _ptr); // 현재 트리의 모든 _name들 전위 순서대로 출력해주는 함수.
nodePtr preorder_find(char ans, nodePtr _ptr); // ans에 해당하는 _name을 가진 노드를 찾아 그 노드의 포인터값을 리턴해주는 함수. 전위 순서대로 탐색
path pathfind(nodePtr start, char ans); // start에 해당하는 노드부터 출발하여 ans값을 가진 노드까지의 path를 찾아 리턴
void printpath(path p, nodePtr start, int startN); // start에 해당하는 노드부터 출발하여 startN부터 p.n까지의 길을 따라 관계와 _name을 출력해준다.
void question(char start, char destination); // 입력이 ? 일 때 관계를 출력해주는 함수
int getSamePointCount(path a, path b); // path a와 b를 비교하여 root부터 같은 방향이 몇개인지 찾아 리턴해주는 함수ㅏ

int main() {
	printf(">>\n");
	while (getinput()); //입력이 $(종료 문자)인 경우 0을 리턴받아 종료. 그 전까지는 반복
	return 0;
}

int getinput() { // 입력을 M, F, ?에 따라 구분하여 해당하는 실행을 해준다.
	printf(">>");
	scanf("%s", input);
	if (input[2] == '?') {
		question(input[0], input[4]);
		return 1;
	}
	else if (input[0] == '$')
		return 0;
	else {
		append(input[4], input[2], input[0]);
		preorder_print(root);
		printf("\n");
		return 1;
	}
}

void append(char parent, char relation, char child) { // 입력이 M, F일 때 트리에 추가해주는 함수
	nodePtr childPtr = preorder_find(child, root);
	// childPtr에 child의 값을 가진 노드를 찾아 저장한다
	if (childPtr) {//childPtr이 NULL이 아닌 경우는 child의 값을 가진 노드가 있다는 것을 의미
		nodePtr temp = malloc(sizeof(node));
		temp->mother = NULL;
		temp->father = NULL;
		temp->_name = parent;
		if (relation == 'F') {
			childPtr->father = temp;
		}
		else if (relation == 'M') {
			childPtr->mother = temp;
		}
	// 새로운 노드 생성하여 parent의 값을 넣고 childPtr의 F 또는 M에 해당하는 곳에 생성한 노드를 넣어준다
	}
	else if (root) { 
		// childPtr의 값이 NULL이고 root가 NULL이 아닐 때 = parent가 root의 _name인 경우
		childPtr = malloc(sizeof(node));
		childPtr->_name = child;
		if (relation == 'F') {
			childPtr->father = root;
			childPtr->mother = NULL;
		}
		else if (relation == 'M') {
			childPtr->father = NULL;
			childPtr->mother = root;
		}
		root = childPtr;
		// 새로운 노드를 childPtr에 생성하여 child의 값을 저장한 다음 F 또는 M에 해당하는 곳에 root를 넣어준다
	}
	else {
		// childPtr과 root가 모두 NULL인 경우 처음으로 입력을 받는 경우
		root = malloc(sizeof(node));
		root->_name = child;
		childPtr = malloc(sizeof(node));
		childPtr->_name = parent;
		childPtr->father = NULL;
		childPtr->mother = NULL;

		if (relation == 'F') {
			root->father = childPtr;
			root->mother = NULL;
		}
		else if (relation == 'M') {
			root->father = NULL;
			root->mother = childPtr;
		}
	}
	//childPtr과 root모두에 새로운 노드를 생성해주고 각각 parent와 child의 값을 넣어준다
}

void preorder_print(nodePtr _ptr) {
	if (_ptr) {
		printf("%c", _ptr->_name);
		preorder_print(_ptr->father);
		preorder_print(_ptr->mother);
	}
}
// 재귀 함수를 이용
nodePtr preorder_find(char ans, nodePtr _ptr) { 
	if (!_ptr) //ptr이 NULL인 경우
		return NULL;
	else if (_ptr->_name == ans) // ans에 해당하는 값을 가진 노드를 찾은 경우
		return _ptr;
	else { // ptr이 NULL이 아니고 ans에 해당하는 값을 가지지도 않은 경우
		nodePtr temp = NULL;
		if (_ptr->father)
			temp = preorder_find(ans, _ptr->father);
		if (!temp && _ptr->mother)
			temp = preorder_find(ans, _ptr->mother);
		return temp;
	}
}
// 반복문과 스택을 이용하여 start부터 ans의 값을 가진 노드까지 가는 길을 찾는 함수
path pathfind(nodePtr start, char ans) {
	path result;
	result.path = 0; result.n = 0;
	nodePtr temp;
	while (1) {
		temp = start;
		for (int i = 0; i < result.n; i++) {
			if (result.path & (1i64 << i))
				temp = temp->mother;
			else
				temp = temp->father;
		}
		if (!temp) {
			result.n--;
			result.path &= (1 << result.n) - 1;
			result.path |= 1i64 << (result.n - 1);
			continue;
		}
		else if (temp->_name == ans)
			break;
		else if (temp->father)
			result.n++;
		else if (temp->mother) {
			result.path |= 1i64 << (result.n - 1);
			result.n++;
		}
		else
			result.path |= 1i64 << (result.n - 1);
	}
	return result;
}
// start노드 부터 startN부터의 길을 따라 관계와 _name을 출력하는 함수 
void printpath(path p, nodePtr start, int startN) {
	printf("%c", start->_name);
	for (int i = startN; i < p.n; i++) {
		if (p.path & (1i64 << i)) {
			start = start->mother;
			printf("-M-%c", start->_name);
		}
		else {
			start = start->father;
			printf("-F-%c", start->_name);
		}
	}
	printf("\n");
}
// 질의를 받았을 때
void question(char start, char destination) {
	path a = pathfind(root, start);
	path b = pathfind(root, destination);
	int sameN = getSamePointCount(a, b);
	nodePtr samePoint = root;
	//sameN을 찾아 가장 위의 공통 부모를 찾아 samePoint를 해당하는 부분까지 이동
	for (int i = 0; i < sameN; i++) {
		if (a.path & (1i64 << i))
			samePoint = samePoint->mother;
		else
			samePoint = samePoint->father;
	}
	// start의 값을 가진 노드가  destination을 가진 노드의 후손노드 이므로 불필요한 연산을 진행하지 않기 위해 처리해준다.
	if (samePoint->_name == input[0]) {
		printpath(b, samePoint, sameN);
	}
	else {
		for (int i = a.n; i > sameN; i--) {
			nodePtr roottemp = root;
			for (int j = 0; j < i; j++) {
				if (a.path & (1i64 << j))
					roottemp = roottemp->mother;
				else
					roottemp = roottemp->father;
			}
			if (i - 2 > -1)
				if (a.path & (1i64 << (i - 2)))
					printf("%c-D-", roottemp->_name);
				else
					printf("%c-S-", roottemp->_name);
			else
				printf("%c-C-", roottemp->_name);
		}
		printpath(b, samePoint, sameN);
	}
}

int getSamePointCount(path a, path b) {
	long long int temp = ~(a.path ^ b.path);
	int tempN = a.n < b.n ? a.n : b.n;
	int retN = 0;
	for (int i = 0; i < tempN; i++) {
		if (temp & (1i64 << i))
			retN++;
		else
			break;
	}
	return retN;
}
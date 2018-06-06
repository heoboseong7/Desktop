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
void append(char parent, char relation, char child);
void preorder_print(nodePtr _ptr);
nodePtr preorder_find(char ans, nodePtr _ptr);
path pathfind(nodePtr start, char ans);
void printpath(path p, nodePtr start, int startN);
int getSamePointCount(path a, path b);

int main() {
	printf(">>\n");
	while (getinput());
	return 0;
}

int getinput() {
	printf(">>");
	scanf("%s", input);
	if (input[2] == '?') {
		path a = pathfind(root, input[0]);
		path b = pathfind(root, input[4]);
		int sameN = getSamePointCount(a, b);
		nodePtr samePoint = root;

		for (int i = 0; i < sameN; i++) {
			if (a.path & (1i64 << i))
				samePoint = samePoint->mother;
			else
				samePoint = samePoint->father;
		}
		if (samePoint->_name == input[0]) {
			printpath(b, samePoint, sameN);
			return 1;
		}
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

void append(char parent, char relation, char child) {
	nodePtr childPtr = preorder_find(child, root);

	if (childPtr) {
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
	}
	else if (root) {
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
	}
	else {
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
}

void preorder_print(nodePtr _ptr) {
	if (_ptr) {
		printf("%c", _ptr->_name);
		preorder_print(_ptr->father);
		preorder_print(_ptr->mother);
	}
}

nodePtr preorder_find(char ans, nodePtr _ptr) {
	if (!_ptr)
		return NULL;
	else if (_ptr->_name == ans)
		return _ptr;
	else {
		nodePtr temp = NULL;
		if (_ptr->father)
			temp = preorder_find(ans, _ptr->father);
		if (!temp && _ptr->mother)
			temp = preorder_find(ans, _ptr->mother);
		return temp;
	}
}

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
/*
** 20175969 �㺸��
** �ڷᱸ�� ���α׷��� ���� 02
** 5/30 ����
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

typedef struct path { //root�������� ���ϴ� ���� �ִ� node������ ���� ����
	long long int path; //�̵��� ������ �����ϴ� ���� ��Ʈ�� 0�̸� ����(father) 1�̸� ������(mother)�������� �̵������� �ǹ�. 
	int n; // �̵��� ������ ����
}path;

nodePtr root = NULL;
char input[6];

int getinput();
void append(char parent, char relation, char child); //�Է��� M, F�� �� Ʈ���� Ȯ�����ִ� �Լ�
void preorder_print(nodePtr _ptr); // ���� Ʈ���� ��� _name�� ���� ������� ������ִ� �Լ�.
nodePtr preorder_find(char ans, nodePtr _ptr); // ans�� �ش��ϴ� _name�� ���� ��带 ã�� �� ����� �����Ͱ��� �������ִ� �Լ�. ���� ������� Ž��
path pathfind(nodePtr start, char ans); // start�� �ش��ϴ� ������ ����Ͽ� ans���� ���� �������� path�� ã�� ����
void printpath(path p, nodePtr start, int startN); // start�� �ش��ϴ� ������ ����Ͽ� startN���� p.n������ ���� ���� ����� _name�� ������ش�.
void question(char start, char destination); // �Է��� ? �� �� ���踦 ������ִ� �Լ�
int getSamePointCount(path a, path b); // path a�� b�� ���Ͽ� root���� ���� ������ ����� ã�� �������ִ� �Լ���

int main() {
	printf(">>\n");
	while (getinput()); //�Է��� $(���� ����)�� ��� 0�� ���Ϲ޾� ����. �� �������� �ݺ�
	return 0;
}

int getinput() { // �Է��� M, F, ?�� ���� �����Ͽ� �ش��ϴ� ������ ���ش�.
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

void append(char parent, char relation, char child) { // �Է��� M, F�� �� Ʈ���� �߰����ִ� �Լ�
	nodePtr childPtr = preorder_find(child, root);
	// childPtr�� child�� ���� ���� ��带 ã�� �����Ѵ�
	if (childPtr) {//childPtr�� NULL�� �ƴ� ���� child�� ���� ���� ��尡 �ִٴ� ���� �ǹ�
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
	// ���ο� ��� �����Ͽ� parent�� ���� �ְ� childPtr�� F �Ǵ� M�� �ش��ϴ� ���� ������ ��带 �־��ش�
	}
	else if (root) { 
		// childPtr�� ���� NULL�̰� root�� NULL�� �ƴ� �� = parent�� root�� _name�� ���
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
		// ���ο� ��带 childPtr�� �����Ͽ� child�� ���� ������ ���� F �Ǵ� M�� �ش��ϴ� ���� root�� �־��ش�
	}
	else {
		// childPtr�� root�� ��� NULL�� ��� ó������ �Է��� �޴� ���
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
	//childPtr�� root��ο� ���ο� ��带 �������ְ� ���� parent�� child�� ���� �־��ش�
}

void preorder_print(nodePtr _ptr) {
	if (_ptr) {
		printf("%c", _ptr->_name);
		preorder_print(_ptr->father);
		preorder_print(_ptr->mother);
	}
}
// ��� �Լ��� �̿�
nodePtr preorder_find(char ans, nodePtr _ptr) { 
	if (!_ptr) //ptr�� NULL�� ���
		return NULL;
	else if (_ptr->_name == ans) // ans�� �ش��ϴ� ���� ���� ��带 ã�� ���
		return _ptr;
	else { // ptr�� NULL�� �ƴϰ� ans�� �ش��ϴ� ���� �������� ���� ���
		nodePtr temp = NULL;
		if (_ptr->father)
			temp = preorder_find(ans, _ptr->father);
		if (!temp && _ptr->mother)
			temp = preorder_find(ans, _ptr->mother);
		return temp;
	}
}
// �ݺ����� ������ �̿��Ͽ� start���� ans�� ���� ���� ������ ���� ���� ã�� �Լ�
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
// start��� ���� startN������ ���� ���� ����� _name�� ����ϴ� �Լ� 
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
// ���Ǹ� �޾��� ��
void question(char start, char destination) {
	path a = pathfind(root, start);
	path b = pathfind(root, destination);
	int sameN = getSamePointCount(a, b);
	nodePtr samePoint = root;
	//sameN�� ã�� ���� ���� ���� �θ� ã�� samePoint�� �ش��ϴ� �κб��� �̵�
	for (int i = 0; i < sameN; i++) {
		if (a.path & (1i64 << i))
			samePoint = samePoint->mother;
		else
			samePoint = samePoint->father;
	}
	// start�� ���� ���� ��尡  destination�� ���� ����� �ļճ�� �̹Ƿ� ���ʿ��� ������ �������� �ʱ� ���� ó�����ش�.
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
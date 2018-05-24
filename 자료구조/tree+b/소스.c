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

typedef struct path {
	int path;
	int n;
}path;

nodePtr root = NULL;
char input[6];

int getinput();
void append(char parent, char relation, char child);
void preorder_print(nodePtr _ptr);
nodePtr preorder_find(char ans, nodePtr _ptr);
path pathfind(nodePtr start, char ans);
void printpath(path p, nodePtr start);

int main() {
	printf(">>\n");
	while (getinput());
	return 0;
}

int getinput() {
	printf(">>");
	scanf("%s", input);
	if (input[2] == '?') {
		nodePtr childPtr = preorder_find(input[0], root);
		path relation = pathfind(childPtr, input[4]);
		printpath(relation, childPtr);
	}
	else if (input[0] == '$')
		return 0;
	else {
		append(input[4], input[2], input[0]);
		preorder_print(root);
		printf("\n");
	}
}

void append(char parent, char relation, char child) {
	nodePtr childPtr = preorder_find(child, root);

	if (childPtr != NULL) {
		nodePtr temp = malloc(sizeof(node));
		temp->mother = NULL;
		temp->father = NULL;
		temp->_name = parent;

		if ((int)relation == 'F') {
			childPtr->father = temp;
		}
		else if ((int)relation == 'M') {
			childPtr->mother = temp;
		}
	}
	else if (root != NULL) {
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
	if (_ptr == NULL) {
		return NULL;
	}
	else if ((int)_ptr->_name == ans)
		return _ptr;
	else {
		nodePtr temp = NULL;
		if (_ptr->father != NULL)
			temp = preorder_find(ans, _ptr->father);
		if (temp == NULL && _ptr->mother != NULL)
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
			if (result.path & (1 << i))
				temp = temp->mother;
			else
				temp = temp->father;
		}
		if (temp == NULL) {
			result.n -= 1;
			result.path &= (1 << result.n) - 1;
			result.path |= 1 << (result.n - 1);
			continue;
		}
		if (temp->_name == ans)
			break;

		if (temp->father != NULL) {
			result.n += 1;
		}
		else if (temp->mother != NULL) {
			result.path |= 1 << (result.n - 1);
			result.n += 1;
		}
		else if (result.path & (result.n - 1)) {
			result.n -= 1;
			result.path &= (1 << result.n) - 1;
			result.path |= 1 << (result.n - 1);
		}
		else {
			result.path |= 1 << (result.n - 1);
		}
	}
	return result;
}

void printpath(path p, nodePtr start) {
	printf("%c", start->_name);
	for (int i = 0; i < p.n; i++) {
		if (p.path & (1 << i)) {
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
#include<stdio.h>
#include<stdlib.h>

#define NUM_ROW 10
#define NUM_COL 10
#define EXIT_ROW 10
#define EXIT_COL 10
#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

typedef struct {
	short int vert;
	short int horiz;
} offsets;

element stack[100];
int top = 0;
int mark[NUM_ROW + 2][NUM_COL + 2] = { 0 };
int maze[NUM_ROW + 2][NUM_COL + 2];

void setup_maze();
element pop();
void push(element item);
element stackEmpty();
void stackFull();


int main() {
	offsets move[8];
	move[0].vert = -1; move[0].horiz = 0;
	move[1].vert = -1; move[1].horiz = 1;
	move[2].vert = 0; move[2].horiz = 1;
	move[3].vert = 1; move[3].horiz = 1;
	move[4].vert = 1; move[4].horiz = 0;
	move[5].vert = 1; move[5].horiz = -1;
	move[6].vert = 0; move[6].horiz = -1;
	move[7].vert = -1; move[7].horiz = -1;

	setup_maze();

	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
	while (!found && top > -1) {
		position = pop();
		row = position.row; col = position.col; dir = position.dir;
		while (!found && dir < 8) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
				found = TRUE;
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;
				position.row = row; position.col = col; position.dir = ++dir;
				push(position);
				row = nextRow; col = nextCol; dir = 0;
			}
			else ++dir;
		}
	}
	if (found) {
		printf("The path is:\n");
		printf("row  col\n");
		for (i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else printf("The maze does not have a path\n");
}

void setup_maze() {
	short int maze0[NUM_ROW][NUM_COL] = {
		{ 0,0,1,0,1,1,1,0,1,0 },
		{ 1,0,0,1,1,1,0,1,0,1 },
		{ 1,1,0,1,1,0,1,0,1,1 },
		{ 0,0,1,1,1,0,1,0,0,0 },
		{ 0,1,1,1,1,0,1,0,1,0 },
		{ 1,0,1,1,0,1,1,0,1,0 },
		{ 1,1,0,1,0,1,0,0,1,0 },
		{ 1,0,1,0,1,0,1,0,0,0 },
		{ 0,1,0,1,1,1,0,1,1,0 },
		{ 1,0,0,1,1,1,0,0,0,0 }
	};
	for (int i = 0; i < NUM_ROW + 2; i++)
		for (int j = 0; j < NUM_COL + 2; j++) {
			if (i == 0 || j == 0 || i == NUM_ROW + 1 || j == NUM_COL + 1)
				maze[i][j] = 1;
			else
				maze[i][j] = maze0[i - 1][j - 1];
		}

}
void push(element item) {
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}
element pop() {
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}
element stackEmpty() {
	fprintf(stderr, "Stack is empty\n");
	exit(EXIT_FAILURE);
}
void stackFull() {
	fprintf(stderr, "Stack is full\n");
	exit(EXIT_FAILURE);
}
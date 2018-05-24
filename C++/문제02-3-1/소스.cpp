#include <iostream>

using namespace std;

typedef struct
{
	int xpos;
	int ypos;
}Point; 

Point &PntAdder(const Point &p1, const Point &p2)
{
	Point *sum = new Point;
	sum->xpos = p1.xpos + p2.xpos;
	sum->ypos = p1.ypos + p2.ypos;

	return * sum;
}
int main()
{
	Point *point1 = new Point;
	Point *point2 = new Point;
	point1->xpos = 3; point1->ypos = 5;
	point2->xpos = 12; point2->ypos = 20;
	Point &sum = PntAdder(*point1, *point2);
	cout << sum.xpos << endl << sum.ypos << endl;

	delete point1;
	delete point2;
	delete &sum;

	return 0;
}
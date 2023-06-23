#include <iostream>
#include <math.h>
using namespace std;
class Point {
private:
	double x;
	double y;
public:
	Point(double xx, double yy) {
		x = xx;
		y = yy;
	};
	double Distance(const Point);
};

double Point::Distance(const Point a) {
	double ans = 0;
	ans = sqrt(pow((x - a.x),2) + pow((y - a.y),2));
	return ans;
}

int main(int argc, char** argv) {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	cout << A.Distance(B) << endl;
	return 0;
}

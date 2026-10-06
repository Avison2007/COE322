#include <cmath>

class Point {
private:
  float x, y;

public:
  // constructor:
  // same name as the class
  // no return type
  Point(float in_x, float in_y) {
    x = in_x;
    y = in_y;
  }

  Point halfway(Point q) {
    float hx = (x + q.x) /2;
    float hy = (y + q.y) /2;

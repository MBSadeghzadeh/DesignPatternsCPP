#include <cassert>

#include "Prototype/Prototype.h"

int main() {
    Shape shape1;
    shape1.x = 11;
    shape1.y = 12;
    shape1.color = "red";

    auto clonedShape = shape1.clone();

    Shape shape2 = *clonedShape.get();

    assert(shape1 == shape2);

    Rectangle rect1;

    rect1.height = 10;
    rect1.width = 20;
    rect1.x = 1;
    rect1.y = 2;
    rect1.color = "blue";

    clonedShape =  rect1.clone();

    Rectangle rect2 = *std::static_pointer_cast<Rectangle>(clonedShape).get();

    assert(rect1 == rect2);

    Circle circle1;
    circle1.radius = 20;
    circle1.x = 21;
    circle1.y = 22;
    circle1.color = "green";

    clonedShape = circle1.clone();

    Circle circle2 = *std::static_pointer_cast<Circle>(clonedShape).get();

    assert( circle1 == circle2);

    rect2.width++;
    circle2.y++;

    assert(rect1 != rect2);
    assert(circle1 != circle2);

    return 0;
}


#include <memory>
#include <string>

class Shape {
public:
    Shape() = default;

    Shape(const Shape &sh) {
        this->x = sh.x;
        this->y = sh.y;
        this->color = sh.color;
    }

    virtual std::shared_ptr<Shape> clone() {
        return std::make_shared<Shape>(*this);
    }

    bool operator!=(const Shape &s) const {
        return !(*this == s);
    }

    bool operator==(const Shape &s) const {
        return this->x == s.x && this->y == s.y && this->color == s.color;
    }

    virtual ~Shape() = default;

    int x;
    int y;
    std::string color;
};


class Rectangle: public Shape {
public:
    Rectangle() = default;

    Rectangle(const Rectangle &r): Shape(r) {
        this->width = r.width;
        this->height = r.height;
    }

    bool operator!=(const Rectangle &s) const {
        return !(*this == s);
    }

    bool operator==(const Rectangle &r) const {
        const Shape& ls = *this;
        const Shape& rs = r;
        return ls == rs &&  this->width == r.width && this->height == r.height;
    }

    std::shared_ptr<Shape> clone() override {
        auto rect = std::make_shared<Rectangle>(*this);
        return std::static_pointer_cast<Shape>(rect);
    }

    int width;
    int height;
};


class Circle: public Shape {
public:
    Circle() = default;

    Circle(const Circle &c): Shape(c) {
        this->radius = c.radius;
    }

    bool operator!=(const Circle &s) const {
        return !(*this == s);
    }

    bool operator==(const Circle &c) const {
        const Shape &shL = *this;
        const Shape &shR = c;

        return shL == shR && this->radius == c.radius;
    }

    std::shared_ptr<Shape> clone() override {
        auto c = std::make_shared<Circle>(*this);
        return std::static_pointer_cast<Shape>(c);
    }

    int radius;
};


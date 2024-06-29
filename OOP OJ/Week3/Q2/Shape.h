class Shape {
    private:
        double width;
        double height;
    public:
        Shape(double width, double height){
            this->width = width;
            this->height = height;
        }
        double getWidth(){
            return width;
        }
        double getHeight(){
            return height;
        }
        virtual double getArea() = 0;
};

class Rectangle : public Shape {
    public:
        Rectangle(double width, double height) : Shape(width, height) {}
        double getArea() override{
            return getWidth() * getHeight();
        }
};

class Circle : public Shape {
    private :
        double radius;
    public:
        Circle(double radius) : Shape(0, 0) {
            this->radius = radius;
        }
        double getArea() override{
            return 3.14 * radius * radius;
        }  
};
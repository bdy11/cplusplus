class Shape{
public:
  virtual ~Shape() = default;      // 析构函数
  virtual void draw() const = 0;   // 必须被子类重写
  virtual double area() const = 0;
};

class Circle: public Shape{
private:
  double radius;

public:
  Circle(double r) : radius(r){}
  void draw() const override{
    std::cout<<"drawing circle"<<stdd::endl;
  }

  double area() const override{
    return M_PI * radius * radius;
  }
};

class Rectangle : public Shape{
private:
  double width, height;
public:
  Rectangle(double w, double h): width(w), height(h) {}

  void draw() const override{
    std::coud<<"drawing rectangle"<<std::endl;
  }

  double area() const override{
    return width * height;
  }
}


std::unique_ptr<Shape> createShape(const std::string & type){
  if(type == "Circle){
    return std::make_unique<Circle>(3.0);
  }else if(type == "Rectangle"){
    return std::make_unique<Rectangle>(4.0, 5.0);
  }else{
    return nullptr;
  }
}
int main(){
  std::vector<std::unique_ptr<Shape>> shapes;

  shapes.emplace_back(std::make_unique<Circle>(2.0));
  shapes.emplace_back(std::make_unique<Rectangle>(3.0, 6.0));
  shapes.emplace_back(createShape("Circle"));
  shapes.emplace_back(createShape("Rectangle"));

  for (const auto& shape :shapes){
    shape->draw();
    std::cout<<"area: "<< shape->area() <<"\n \n";
  }

  return 0;
}



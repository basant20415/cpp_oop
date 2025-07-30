#ifndef _OOP_HPP
#define _OOP_HPP

// best practice :the name of the class starts with Capital letter
//separating what from how 
class Rectangle{//what -->declaration
private:
double length;
double width;


public:
Rectangle();
Rectangle(double ,double );
double computeArea();
double computeParameter();
double get_length() const;
double get_width() const;
void set_width(int );
void set_length(int );
};



#endif

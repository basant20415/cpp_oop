
#include"oop.hpp"

//how
Rectangle::Rectangle(){
    length=width=0;
}
Rectangle::Rectangle(double l,double w){
    width=w;
    length=l;
}

Rectangle::double computeArea(){
    return length*width;
}

Rectangle::double computeParameter(){
    return 2*(length+width);
}

Rectangle::double get_length(){
    return length;
}

Rectangle::double get_width(){
    return width;
}

Rectangle::void set_width(int w){
    width=w;
}

Rectangle::void set_length(int l){
    length=l;
}




#include<bits/stdc++.h>
using namespace std;




struct rectangle{
double length;
double width;

rectangle(){
    width=length=0;
}
rectangle(double l,double w){
    width=w;
    length=l;
}

double computeArea(){
    return length*width;
}

double computeParameter(){
    return 2*(length+width);
}



};

int main(){
// rectangle rec;
// rec.set_length(100);
// rec.set_width(50);
// cout<<rec.get_length();
// =========
// struct rectangle
rectangle r;
r.length=10;
r.width=20;
cout<<r.computeArea();
cout<<rectangle r2(30,40);
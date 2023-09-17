// Program to check whether two lines intersect or not.

#include<iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

int Direction(Point pi, Point pj, Point pk){
    return (((pk.x - pi.x) * (pj.y - pi.y)) - (((pk.y - pi.y) * (pj.x - pi.x))));
}

bool onSegment(Point pi, Point pj, Point pk){
    if((min(pi.x,pj.x) <= pk.x <= max(pi.x,pj.x)) &&
    (min(pi.y,pj.y) <= pk.y <= max(pi.y,pj.y))){
        return true;
    }
    else{
        return false;
    }
}

bool Segment_Intersect(Point p1, Point p2, Point p3, Point p4){
    int d1, d2, d3, d4;
    
    d1 = Direction(p3, p4, p1);
    d2 = Direction(p3, p4, p2);
    d3 = Direction(p1, p2, p3);
    d4 = Direction(p1, p2, p4);
    
    if((d1 * d2) < 0 && (d3 * d4) < 0){
        return true;
    }
    else if(d1 == 0 && onSegment(p3, p4, p1)){
        return true;
    }
    else if(d2 == 0 && onSegment(p3, p4, p2)){
        return true;
    }
    else if(d3 == 0 && onSegment(p1, p2, p3)){
        return true;
    }
    else if(d4 == 0 && onSegment(p1, p2, p4)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Point p1, p2, p3, p4;
    
    cout << "Enter First Point: ";
    cin >> p1.x >> p1.y;
    
    cout << "Enter Second Point: ";
    cin >> p2.x >> p2.y;
    
    cout << "Enter Third Point: ";
    cin >> p3.x >> p3.y;
    
    cout << "Enter Fourth Point: ";
    cin >> p4.x >> p4.y;
    
    bool intersect = Segment_Intersect(p1, p2, p3, p4);
    
    if(intersect){
        cout << "Two Line Segments are intersect." << endl;
    }
    else{
        cout << "Two Line Segments are not intersect." << endl;
    }
    
    return 0;
}
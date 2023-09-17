#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

double distance(Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

pair<Point, Point> Closest_Pair_Of_Points(vector<Point>& points){
    int n = points.size();

    if(n < 2){
        return make_pair(Point{0, 0}, Point{0, 0});
    }

    double minDistance = distance(points[0], points[1]);
    pair<Point, Point> closestPair = make_pair(points[0], points[1]);

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double d = distance(points[i], points[j]);

            if(d < minDistance){
                minDistance = d;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}

int main(){
    int n;

    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);

    for(int i=0; i<n; i++){
        cout << "Enter Points: ";
        cin >> points[i].x >> points[i].y;
    }

    pair<Point, Point> closestPair = Closest_Pair_Of_Points(points);

    cout << "\nClosest Pair of Points: (" << closestPair.first.x << ", " << closestPair.first.y << ") & (" << closestPair.second.x << ", " << closestPair.second.y << ")" << endl;
    cout << "\nMinimum Distance: " << distance(closestPair.first, closestPair.second) << endl;
    
    return 0;
}
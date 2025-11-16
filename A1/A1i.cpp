#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

struct Circle {
    double x, y, r;
};

int main() {
    vector<Circle> circles(3);
    
    for (int i = 0; i < 3; i++) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    
    double min_x = circles[0].x - circles[0].r;
    double max_x = circles[0].x + circles[0].r;
    double min_y = circles[0].y - circles[0].r;
    double max_y = circles[0].y + circles[0].r;
    
    for (int i = 1; i < 3; i++) {
        min_x = min(min_x, circles[i].x - circles[i].r);
        max_x = max(max_x, circles[i].x + circles[i].r);
        min_y = min(min_y, circles[i].y - circles[i].r);
        max_y = max(max_y, circles[i].y + circles[i].r);
    }
    
    double rect_area = (max_x - min_x) * (max_y - min_y);
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist_x(min_x, max_x);
    uniform_real_distribution<double> dist_y(min_y, max_y);
    
    const int N = 1000000;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        double px = dist_x(gen);
        double py = dist_y(gen);
        
        bool in_all = true;
        for (const auto& circle : circles) {
            double dx = px - circle.x;
            double dy = py - circle.y;
            if (dx * dx + dy * dy > circle.r * circle.r) {
                in_all = false;
                break;
            }
        }
        
        if (in_all) {
            count++;
        }
    }
    
    double area = rect_area * count / N;
    
    cout.precision(20);
    cout << area << endl;
    
    return 0;
}
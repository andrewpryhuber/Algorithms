#include <iostream>
#include <cmath>

//does not work yet
using namespace std;

double slope(double x1[2], double x2[2])
{
    return (x1[1] - x2[1]) / (x1[0] - x2[0]);
}

double yintercept(double slope, double x1[2])
{
    if (x1[0] == 0)
    {
        return 0;
    }
    else
    {
        return x1[1] - x1[0] * slope;
    }
}

int main()
{
    double p1[2] = {0, 0};
    double p2[2] = {1, 1};
    double q1[2] = {0, 1};
    double q2[2] = {1, 0};

    double slope1 = slope(p1, p2);
    double slope2 = slope(q1, q2);

    double yintercept1 = yintercept(slope1, p1);
    double yintercept2 = yintercept(slope2, p2);

    cout << yintercept1 << endl;
    cout << yintercept2 << endl;

    double xintersection = (yintercept1 - yintercept2) / (slope1 - slope2);
    double yintersection = yintercept1 + slope1 * p1[0];

    cout << "Intersection is (" << xintersection << "," << yintersection << ")." << endl;
}

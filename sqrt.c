#include <stdio.h>
#include <math.h>


double distance(double x1, double x2, double y1, double y2)
{
    double d;

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    return d;
}

void test(int a[][5][5]);

int main(int argc, char const *argv[])
{
    /* code */
    double x1, x2, y1, y2, result;

    printf("Please enter x1, x2, y1, y2");
    scanf("%lf,%lf,%lf,%lf", &x1, &x2, &y1, &y2);
    result = distance(x1, x2, y1, y2);

    printf("result=%lf\n", result);

    return 0;
}
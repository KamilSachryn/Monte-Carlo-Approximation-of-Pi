// Monte Carlo Approximation of Pi.cpp 


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;


double distance(int x1, int y1, int x2, int y2)
{
    return sqrtf(abs(x2 - x1) ^ 2 + abs(y2 - y1) ^ 2);
}

int main()
{
    //init random seed
    srand(time(NULL));

    //simlate a square
    //put circle in square
    //if <= r then landed in circle
    //if > r landed out of circle
    //but we dont need the wole square, just 1 part, then multiply by 4
    //so...
    //random between 0 and 1 and check distance.
     
    const double NUM_REPETITIONS = 100000;
    int hits = 0;
    double r = 1;
    double x = 0;
    double y = 0;

    for (int i = 0; i < NUM_REPETITIONS; i++)
    {

        x = rand() / double(RAND_MAX);
        y = rand() / double(RAND_MAX);

        /*
        if (sqrt(x * x + y * y) < r)
        {
            hits++;
        }
        */
        hits += sqrt(x * x + y * y) < r ? 1 : 0;
        
    }
    //number of hits in our 1/4th slice
    double ans = hits / NUM_REPETITIONS;
    //extrapolate to whole circle by doing * 4
    ans *= 4;

    cout << ans;

}

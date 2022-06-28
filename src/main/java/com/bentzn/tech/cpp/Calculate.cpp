#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;

int calculatePythagoras()
{
    int nLoops = 250;
    int nCnt = 0;
    for (float i = 1; i < nLoops; i++)
    {
        for (float n = 1; n < nLoops; n++)
        {
            for (float m = 1; m < nLoops; m++)
            {
                if (i * i + n * n == m * m)
                    nCnt++;
            }
        }
    }

    return nCnt;
}

int main()
{
    struct timeval time0, time1;
    gettimeofday(&time0, NULL);

    for (int i = 0; i < 100; i++)
    {
        calculatePythagoras();
    }
    gettimeofday(&time1, NULL);

    float timeDiff = (time1.tv_sec - time0.tv_sec) + (time1.tv_usec - time0.tv_usec) / 1000000;
    float frames = 100;
    float framesPerSec = frames / timeDiff;
    cout << "Frames / sec: " << framesPerSec << endl;

    return 1;
}

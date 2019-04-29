#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#define MAX 6

int main()
{
    srand(time(NULL));
    int a[MAX];
    float avg=0.0;
    for(int i=0; i<MAX; i++)
        a[i] = rand()%MAX;
    for(int i=0; i<MAX; i++)
        std::cout<<a[i]<<"\t";
    #pragma omp parallel
    for(int i=0; i<MAX; i++)
    {
        avg += a[i];
        std::cout<<"\nFor i = "<<i<<" thread "<<omp_get_thread_num()<<" is executing ";
    }
    avg /= MAX;
    std::cout<<"\nAverage = "<<avg<<std::endl;
    return 0;
}


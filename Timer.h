//
// Created by jdinh on 12/25/2020.
//

#ifndef MANUAL_RANDOM_NUMBER_GENERATOR_TIMER_H
#define MANUAL_RANDOM_NUMBER_GENERATOR_TIMER_H

#include <chrono>

using namespace std;


class Timer
{
private:
    typedef chrono::high_resolution_clock Clock;
    typedef Clock ::time_point Time;
    static Time getCurrentTime();
    Time t1, t2;

public:
    void start();
    void end();
    double getDuration();
};


#endif //MANUAL_RANDOM_NUMBER_GENERATOR_TIMER_H

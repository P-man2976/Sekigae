#include "function.h"
#include <math.h>




double InQuad(double change, double base, double duration, double time)
{
    time /= duration;

    return change * time * time + base;
}

double OutQuad(double change, double base, double duration, double time)
{
    time /= duration;

    return -change * time * (time - 2) + base;
}

double InOutQuad(double change, double base, double duration, double time)
{
    time /= duration / 2;

    if (time < 1) return change / 2 * time * time + base;

    return -change / 2 * ((--time) * (time - 2) - 1) + base;
}

double easeInExpo(double t, double b, double c, double d)
{
    return c * pow(2, 10 * (t / d - 1)) + b;
};

//change�͈ړ��ʁBbase�͍ŏ��̈ʒu�Bduration�͈ړ����ԂŁAtime�����݂̌o�ߎ��ԁB
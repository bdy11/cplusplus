// Online C++ compiler to run C++ program online
#include <iostream>
#include <math.h>
#include <cstdint>
const float PI = 3.14159265358979323846;
struct fpoint_t{
    uint16_t x;
    uint16_t y;
};

struct fpose{
    fpoint_t position;
    float theta;
};


float transform_get_theta(int16_t x, int16_t y)
{
    float theta = atan((float)y / x);
    if (x < 0 && y >= 0)
        theta = PI + theta;
    else if (x < 0 && y < 0)
        theta = -PI + theta;
    return theta;
}

void transform_point_odom_to_baselink(const fpose pose, float x_in, float y_in, float* x_out,
    float* y_out)
{
    float xo = (x_in -  pose.position.x);
    float yo = (y_in - pose.position.y);
    float to = transform_get_theta(xo, yo) - pose.theta;
    float lo = sqrt(pow(xo, 2) + pow(yo, 2));
    *x_out = lo * cos(to);
    *y_out = lo * sin(to);
}

void transform_point_odom_to_baselink(const fpose pose, int32_t x_in, int32_t y_in, int16_t* x_out,
    int16_t* y_out)
{
    int16_t xo = (x_in -  pose.position.x);
    int16_t yo = (y_in - pose.position.y);
    float to = transform_get_theta(xo, yo) - pose.theta;
    float lo = sqrt(pow(xo, 2) + pow(yo, 2));
    *x_out = lo * cos(to);
    *y_out = lo * sin(to);
}

int main() {
    fpose pose;
    pose.position.x = 952;
    pose.position.y = 30473;
    pose.theta = 3.10434723;
    int32_t x_in = -68911;
    int32_t y_in = -104327;
    int16_t x_out = 0;
    int16_t y_out = 0;
    transform_point_odom_to_baselink(pose, x_in, y_in, &x_out, &y_out);
    std::cout<< x_out<<" "<<y_out<<std::endl;


    transform_point_odom_to_baselink(pose, (int32_t)x_in, (int32_t)y_in, (int16_t*)&x_out, (int16_t*)&y_out);
    std::cout<< x_out<<" "<<y_out<<std::endl;

    return 0;
}
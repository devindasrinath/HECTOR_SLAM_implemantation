#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <eigen3/Eigen/Dense>

class DatasetGenerator {
private:
    std::vector<double> distanceData;
    std::vector<double> angleData;
    size_t _num_data;
    double radius;

    double solveQuadratic(double a, double b, double c) ;

    double circle_inside_distance(std::pair<double, double> robot_pos, double beam_angle, double radius) ;

public:
    DatasetGenerator(int num_data, double radius) : _num_data(num_data), radius(radius) {}

    std::vector<double> getDistanceData();
    std::vector<double> getAngleData();
    void generateData(std::pair<double,double> center);
};
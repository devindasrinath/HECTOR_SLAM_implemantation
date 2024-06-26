#include "simulation.h"


template<size_t N>
double DatasetGenerator<N>::solveQuadratic(double a, double b, double c) {
    static size_t i = 0;

    if(i>=_num_data){
        i = 0;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
     //   std::cout << "No real roots\n";
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        return root;
     //   std::cout << "One real root: " << root << "\n";
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        if(root1>0 && root2>0){
            if(i<(_num_data/2)){
                return root1;
            }
            else{
                return root2;
            }
        }
        else if (root1>0){
            return root1;
        }
        else if (root2>0){
            return root2;
        }
        
    
    }
    i++;
    return 0;
}

template<size_t N>
double DatasetGenerator<N>::circle_inside_distance(std::pair<double,double> robot_pos,double beam_angle,double radius){

    auto a =1;
    auto b = 2 *(robot_pos.first * sin(beam_angle) + robot_pos.second * cos(beam_angle));
    auto c = robot_pos.first*robot_pos.first + robot_pos.second*robot_pos.second - radius*radius;

    return solveQuadratic(a,b,c);
}

template<size_t N>
std::array<double,N> DatasetGenerator<N>::getDistanceData(){
    
    return distanceData;
}

template<size_t N>
std::array<double,N> DatasetGenerator<N>::getAngleData(){

    return angleData;
}

template<size_t N>
void DatasetGenerator<N>::generateData(std::pair<double,double> center,double angle_deg){
    

    double angle_rad = (2*M_PI*angle_deg)/360;
    
    for (size_t i = 0; i < _num_data; i++)
    {
        distanceData[i] = (circle_inside_distance(center,(2*M_PI*i/_num_data) + angle_rad,radius));//circle distances
        
    }

    double angle_data = 0;
    for (size_t i = 0; i < _num_data; i++)
    {
        angleData[i] = (angle_data);//circle angles
        angle_data+=2*M_PI/360;
        
    }
}

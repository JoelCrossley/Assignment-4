#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;
/*
class fourMomentum
{
    double energy = 0.0;
    double xMomentum = 0.0;
    double yMomentum = 0.0;
    double zMomentum = 0.0;
};
*/

class particle
{
private:
    std::string type {"Ghost"};
    double mass {0.0};
    std::vector<double> fourMomentum {0.0, 0.0, 0.0, 0.0};
public:
    // Default constructor
    particle() = default ;

    double ThreeMagnitude(vector<double> threeVector) {
        return pow( pow(threeVector[1],2) + pow(threeVector[2],2) + pow(threeVector[3],2) , 0.5);
    }

    // Parameterized constructor
    particle(string particleType, double xMomentum, double yMomentum, double zMomentum) {
        type = particleType;
        fourMomentum[1] = xMomentum;
        fourMomentum[2] = yMomentum;
        fourMomentum[3] = zMomentum;
        if (type == "electron") mass = 0.511;
        else if (type == "muon") mass = 105.6;
        else if (type == "tau") mass = 1776.9;

        fourMomentum[0] = pow(mass*mass + pow(ThreeMagnitude(fourMomentum),2) ,0.5);
    }

    ~particle(){std::cout<<"Destroying "<<type<<std::endl;}  // Destructor (in-line)
    double gamma() {return fourMomentum[0]/mass;} // One-line functions are OK in-line
    void print_data();

    double getFourEnergy() {
        return fourMomentum[0];
    }
    double getFourMomentumX() {
        return fourMomentum[1];
    }
    double getFourMomentumY() {
        return fourMomentum[2];
    }
    double getFourMomentumZ() {
        return fourMomentum[3];
    }

};
#endif

vector<double> DotProduct(particle p1, particle p2) {
    double xMomentum = p1.getFourMomentumX()*p2.getFourMomentumX();
    double yMomentum = p1.getFourMomentumY()*p2.getFourMomentumY();
    double zMomentum = p1.getFourMomentumZ()*p2.getFourMomentumZ();
    vector<double> dotMomentum = {xMomentum,yMomentum,zMomentum};
    return dotMomentum;
}

vector<double> VectorSum(particle p1, particle p2) {
    double energy = p1.getFourEnergy() + p2.getFourEnergy();
    double xMomentum = p1.getFourMomentumX()+p2.getFourMomentumX();
    double yMomentum = p1.getFourMomentumY()+p2.getFourMomentumY();
    double zMomentum = p1.getFourMomentumZ()+p2.getFourMomentumZ();
    vector<double> MomentumSum = {energy,xMomentum,yMomentum,zMomentum};
    return MomentumSum;
}

double ThreeMagnitude(vector<double> threeVector) {
    return pow( pow(threeVector[0],2) + pow(threeVector[1],2) + pow(threeVector[2],2) , 0.5);
}

int main() {
    particle particle1("tau", 100, 0, 0);
    particle particle2("muon", 100, 0, 0);
    cout << particle1.getFourMomentumX() << endl;
    cout << DotProduct(particle1, particle2)[0] << endl;
}

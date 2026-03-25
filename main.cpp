#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

class particle
{
private:
    std::string type {"Ghost"};
    double mass {0.0};
    std::vector<double> fourMomentum {0.0, 0.0, 0.0, 0.0};
    //double energy {0.0};
public:
    // Default constructor
    particle() = default ;
    // Parameterized constructor
    /*particle(std::string particle_type, double particle_mass, double particle_momentum):
      type{particle_type}, mass{particle_mass}, momentum{particle_momentum},
      energy{sqrt(mass*mass+momentum*momentum)}
    {};*/

    double ThreeMagnitude(vector<double> threeVector) {
        return pow( pow(threeVector[1],2) + pow(threeVector[2],2) + pow(threeVector[3],2) , 0.5);
    }

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

    vector<double> getFourMomentum() {
        return fourMomentum;
    }
};
#endif

vector<double> DotProduct(particle p1, particle p2) {
    double xMomentum = p1.getFourMomentum()[1]*p2.getFourMomentum()[1];
    double yMomentum = p1.getFourMomentum()[2]*p2.getFourMomentum()[2];
    double zMomentum = p1.getFourMomentum()[3]*p2.getFourMomentum()[3];
    vector<double> dotMomentum = {xMomentum,yMomentum,zMomentum};
    return dotMomentum;
}

double ThreeMagnitude(vector<double> threeVector) {
    return pow( pow(threeVector[0],2) + pow(threeVector[1],2) + pow(threeVector[2],2) , 0.5);
}

int main() {
    particle particle1("tau", 100, 0, 0);
    particle particle2("muon", 100, 0, 0);
    cout << particle1.getFourMomentum()[0] << endl;
    cout << DotProduct(particle1, particle2)[1] << endl;
}

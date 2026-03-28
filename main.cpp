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
    std::vector<double> fourMomentum {0.0, 0.0, 0.0, 0.0};//introduce particle with default values
public:
    // Default constructor
    particle() = default ;

    double ThreeMagnitude(vector<double> threeVector) {
        return pow( pow(threeVector[1],2) + pow(threeVector[2],2) + pow(threeVector[3],2) , 0.5);//function to calculate the magnitude of a particle's momentum
    }

    // Parameterized constructor
    particle(string particleType, double xMomentum, double yMomentum, double zMomentum) {//particle type and the three momentum components is enough to assign all the properties of the particles, since the mass determined by the particle type and energy from mass and momentum
        type = particleType;
        fourMomentum[1] = xMomentum;
        fourMomentum[2] = yMomentum;
        fourMomentum[3] = zMomentum;
        if (type == "electron") mass = 0.511;
        else if (type == "muon") mass = 105.6;
        else if (type == "tau") mass = 1776.9;//mass assigned to particles based on their type

        fourMomentum[0] = pow(mass*mass + pow(ThreeMagnitude(fourMomentum),2) ,0.5);//energy calculated from total momentum and mass
    }

    double getFourEnergy() {//getters for each component of four momentum
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

    ~particle(){}  // Destructor (in-line)
    double gamma() {return fourMomentum[0]/mass;} // One-line functions are OK in-line
    void print_data();

};
#endif

vector<double> DotProduct(particle p1, particle p2) {//function to take the dot product of two momenta
    double energy = p1.getFourEnergy() * p2.getFourEnergy();
    double xMomentum = p1.getFourMomentumX()*p2.getFourMomentumX();
    double yMomentum = p1.getFourMomentumY()*p2.getFourMomentumY();
    double zMomentum = p1.getFourMomentumZ()*p2.getFourMomentumZ();
    vector<double> dotMomentum = {energy, xMomentum,yMomentum,zMomentum};
    return dotMomentum;
}

vector<double> VectorSum(particle p1, particle p2) {//adds to four momenta
    double energy = p1.getFourEnergy() + p2.getFourEnergy();
    double xMomentum = p1.getFourMomentumX()+p2.getFourMomentumX();
    double yMomentum = p1.getFourMomentumY()+p2.getFourMomentumY();
    double zMomentum = p1.getFourMomentumZ()+p2.getFourMomentumZ();
    vector<double> MomentumSum = {energy,xMomentum,yMomentum,zMomentum};
    return MomentumSum;
}

double ThreeMagnitude(vector<double> threeVector) {//function to calculate the magnitude of a particle's momentum
    return pow( pow(threeVector[0],2) + pow(threeVector[1],2) + pow(threeVector[2],2) , 0.5);
}

int NumValidation(int type) //Function used to validate integer inputs
{
    while (!(cin>>type)|| type<1|| type > 3) {
        cout << "Invalid input, must be a 1, 2 or 3 " << endl;
        cin.clear();
        cin.ignore();
    }
    return type;
}

int MomentumValidation(int momentum) //Function used to validate momentum inputs
{
    while (!(cin>>momentum)) {
        cout << "Invalid input, must be a double " << endl;
        cin.clear();
        cin.ignore();
    }
    return momentum;
}

int main() {
    int typeNum;
    string particleType;
    double xMomentum, yMomentum, zMomentum;
    cout << "Choose type for the first particle, 1 for electron, 2 for muon or 3 for tau" << endl;
    typeNum = NumValidation(typeNum);
    cout << "Input particle 1 x momentum"<<endl;
    xMomentum = MomentumValidation(xMomentum);
    cout << "Input particle 1 y momentum"<<endl;
    yMomentum = MomentumValidation(yMomentum);
    cout << "Input particle 1 z momentum"<<endl;
    zMomentum = MomentumValidation(zMomentum);

    if (typeNum == 1) {
        particleType = "electron";
        cout << "Electron selected"<<endl;
    } else if (typeNum == 2) {
        particleType = "muon";
        cout << "Muon selected"<<endl;
    } else if (typeNum == 3) {
        particleType = "tau";
        cout << "Tau selected"<<endl;
    }

    particle particle1(particleType, xMomentum, yMomentum, zMomentum);

    cout << "Choose type for the second particle, 1 for electron, 2 for muon or 3 for tau" << endl;
    typeNum = NumValidation(typeNum);
    cout << "Input particle 2 x momentum"<<endl;
    xMomentum = MomentumValidation(xMomentum);
    cout << "Input particle 2 y momentum"<<endl;
    yMomentum = MomentumValidation(yMomentum);
    cout << "Input particle 2 z momentum"<<endl;
    zMomentum = MomentumValidation(zMomentum);

    if (typeNum == 1) {
        particleType = "electron";
        cout << "Electron selected"<<endl;
    } else if (typeNum == 2) {
        particleType = "muon";
        cout << "Muon selected"<<endl;
    } else if (typeNum == 3) {
        particleType = "tau";
        cout << "Tau selected"<<endl;
    }

    particle particle2(particleType, xMomentum, yMomentum, zMomentum);

    cout << "The sum of the four momenta is (";
    for (int i = 0; i < 4; i++) {
        cout << VectorSum(particle1, particle2)[i] << " , ";
    }
    cout << " )" << endl << "The dot product of the four momenta is (";
    for (int i = 0; i < 4; i++) {
        cout << DotProduct(particle1, particle2)[i] << " , ";
    }
    cout << ")";
}

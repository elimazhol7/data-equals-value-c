#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>
#include <fstream>
using namespace std;

class PersonData {
private:
    string name;
    long id;
    double gpa;
    char gender;
    bool hasName, hasID, hasGPA, hasGender;

public:
    PersonData();
    bool read(ifstream &in);
    void cleanAndWrite(ofstream &out);
};

#endif

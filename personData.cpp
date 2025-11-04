#include "personData.h"
#include "stringUtils.h"
#include <iostream>
#include <sstream>
#include <algorithm>

PersonData::PersonData() {
    hasName = hasID = hasGPA = hasGender = false;
    id = 0;
    gpa = 0.0;
    gender = ' ';
}

bool PersonData::read(ifstream &in) {
    string line;
    bool dataStarted = false;

    while (getline(in, line)) {
        trim(line);

        if (line.empty()) continue;
        if (line[0] == '#') continue; // comment line

        size_t pos = line.find('=');
        if (pos == string::npos) {
            if (dataStarted) return true; // next block begins
            continue;
        }

        dataStarted = true;
        string label = toLower(trimCopy(line.substr(0, pos)));
        string value = trimCopy(line.substr(pos + 1));

        if (label == "name") {
            name = value; hasName = true;
        } else if (label == "id") {
            id = stringToLong(value); hasID = true;
        } else if (label == "gpa") {
            gpa = stringToDouble(value); hasGPA = true;
        } else if (label == "gender") {
            gender = toupper(value[0]); hasGender = true;
        } else {
            // Unknown label → skip
        }

        // Peek next line to detect block end
        streampos posNow = in.tellg();
        string nextLine;
        if (getline(in, nextLine)) {
            trim(nextLine);
            if (nextLine.empty()) {
                in.seekg(posNow);
                return true;
            }
            in.seekg(posNow);
        } else {
            return true;
        }
    }

    return dataStarted;
}

void PersonData::cleanAndWrite(ofstream &out) {
    if (hasName) out << "name = " << name << endl;
    if (hasID) out << "ID = " << id << endl;
    if (hasGPA) out << "GPA = " << gpa << endl;
    if (hasGender) out << "gender = " << gender << endl;
}

#include "StringUtils.h"
#include <sstream>
#include <cctype>

void trim(string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) s = "";
    else s = s.substr(start, end - start + 1);
}

string trimCopy(string s) {
    trim(s);
    return s;
}

string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

long stringToLong(const string &s) {
    long val;
    stringstream ss(s);
    ss >> val;
    return val;
}

double stringToDouble(const string &s) {
    double val;
    stringstream ss(s);
    ss >> val;
    return val;
}

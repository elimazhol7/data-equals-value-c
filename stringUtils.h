#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
using namespace std;

void trim(string &s);
string trimCopy(string s);
string toLower(string s);
long stringToLong(const string &s);
double stringToDouble(const string &s);

#endif

#include <iostream>
#include <fstream>
#include <string>
#include "personData.h"
#include "stringUtils.h"
using namespace std;

int main() {
    cout << "\n\tWelcome to the People Data Copying Program!!!\n\n";

    ifstream inFile;
    ofstream outFile;
    string inputName, outputName;

    // Open input file safely
    while (true) {
        cout << "Please enter the name of your data file: ";
        getline(cin, inputName);
        inFile.open(inputName);
        if (!inFile) {
            cout << "I'm sorry, I could not open '" << inputName << "'. Please enter another name:\n";
            inFile.clear();
        } else {
            cout << "File '" << inputName << "' opened successfully!\n\n";
            break;
        }
    }

    // Open output file safely
    while (true) {
        cout << "Please enter the name of the copy file: ";
        getline(cin, outputName);
        outFile.open(outputName);
        if (!outFile) {
            cout << "I'm sorry, I could not open '" << outputName << "'. Please enter another name:\n";
            outFile.clear();
        } else {
            cout << "File '" << outputName << "' opened successfully!\n\n";
            break;
        }
    }

    cout << "Copying data from '" << inputName << "' to '" << outputName << "'...\n\n";

    outFile << "# format is 'label = value' -- one per line\n";
    outFile << "# known labels are: name, ID, GPA, and gender\n";
    outFile << "# spacing around '=' is okay\n";

    while (!inFile.eof()) {
        PersonData person;
        if (person.read(inFile)) {
            person.cleanAndWrite(outFile);
        }
    }

    cout << "Done copying data!\n";
    cout << "\nThank you for using the PCP!!\n";
    cout << "Endeavor to have a tremendous day!\n";

    inFile.close();
    outFile.close();
    return 0;
}

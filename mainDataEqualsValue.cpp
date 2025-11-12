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
    bool fileOpened = false;

    // Open input file safely
    do {
        cout << "Please enter the name of your data file: ";
        getline(cin, inputName);

        inFile.open(inputName);
        if (!inFile) {
            cout << "I'm sorry, I could not open '" << inputName
                 << "'. Please enter another name:\n";
            inFile.clear();
        } else {
            cout << "File '" << inputName << "' opened successfully!\n\n";
            fileOpened = true;
        }
    } while (!fileOpened);

    // Open output file safely
    fileOpened = false;
    do {
        cout << "Please enter the name of the copy file: ";
        getline(cin, outputName);

        outFile.open(outputName);
        if (!outFile) {
            cout << "I'm sorry, I could not open '" << outputName
                 << "'. Please enter another name:\n";
            outFile.clear();
        } else {
            cout << "File '" << outputName << "' opened successfully!\n\n";
            fileOpened = true;
        }
    } while (!fileOpened);

    cout << "Copying data from '" << inputName << "' to '"
         << outputName << "'...\n\n";

    outFile << "# format is 'label = value' -- one per line\n";
    outFile << "# known labels are: name, ID, GPA, and gender\n";
    outFile << "# spacing around '=' is okay\n";

    PersonData person;
    while (person.read(inFile)) {
        person.cleanAndWrite(outFile);
    }

    cout << "Done copying data!\n";
    cout << "\nBye!\n";

    inFile.close();
    outFile.close();
    return 0;
}

#include "Mobile.h"

int main() {
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";

    readfile();  // Read data from the file

    for (int i = 0; i < Mobiles; i++) {
        printDetails(mobArray[i]);  // Display details before sorting
    }

    Sorting();  // Sort the array

    cout << "\nAfter Sorting:\n";  // Display details after sorting
    for (int i = 0; i < Mobiles; i++) {
        printDetails(mobArray[i]);
    }

    writefile(outputFileName);  // Write sorted data back to a file

    return 0;
}


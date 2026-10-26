
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>

using namespace std;


class GroceryTracker {
private:
    map<string, int> itemFrequencies;


    bool loadItems(const string& fileName) {
        ifstream inputFile(fileName);
        string item;

        if (!inputFile.is_open()) {
            cout << "Error: Could not open " << fileName << "." << endl;
            return false;
        }

        // Count each occurrence of a grocery item.
        while (getline(inputFile, item)) {
            if (!item.empty()) {
                itemFrequencies[item]++;
            }
        }

        inputFile.close();
        return true;
    }

    // Creates the backup file automatically.
    bool saveFrequencies(const string& fileName) {
        ofstream outputFile(fileName);

        if (!outputFile.is_open()) {
            cout << "Error: Could not create "
                << fileName << "." << endl;
            return false;
        }

        // Write each item and its frequency to the file.
        for (const auto& entry : itemFrequencies) {
            outputFile << entry.first << " "
                << entry.second << endl;
        }

        outputFile.close();
        return true;
    }

public:
    // Load the data and create the backup at startup.
    GroceryTracker(const string& inputFileName) {
        if (loadItems(inputFileName)) {
            saveFrequencies("frequency.dat");
        }
    }

    // Display the frequency of one selected item.
    void findItem() const {
        string item;

        cout << "Enter the grocery item: ";
        getline(cin, item);

        auto found = itemFrequencies.find(item);

        if (found != itemFrequencies.end()) {
            cout << item << " was purchased "
                << found->second << " times." << endl;
        }
        else {
            cout << item << " was not found. Frequency: 0"
                << endl;
        }
    }

    // Display every item and its purchase frequency.
    void printFrequencies() const {
        cout << "\nGrocery Item Frequencies" << endl;
        cout << "------------------------" << endl;

        for (const auto& entry : itemFrequencies) {
            cout << entry.first << " "
                << entry.second << endl;
        }
    }

    // Display a histogram using asterisks.
    void printHistogram() const {
        cout << "\nGrocery Item Histogram" << endl;
        cout << "----------------------" << endl;

        for (const auto& entry : itemFrequencies) {
            cout << entry.first << " ";

            for (int i = 0; i < entry.second; i++) {
                cout << "*";
            }

            cout << endl;
        }
    }
};

int main() {
    // The input file must be in the program's working directory.
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int choice = 0;

    do {
        cout << "\n===== Corner Grocer Menu =====" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display item frequency histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number."
                << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Remove the leftover newline before using getline().
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            tracker.findItem();
            break;

        case 2:
            tracker.printFrequencies();
            break;

        case 3:
            tracker.printHistogram();
            break;

        case 4:
            cout << "Thank you for using Corner Grocer!"
                << endl;
            break;

        default:
            cout << "Invalid choice. Please select 1, 2, 3, or 4."
                << endl;
        }

    } while (choice != 4);

    return 0;
}

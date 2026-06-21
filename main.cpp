// Evan Cogan
// CS-210
// Project 3

/*
Your task is to build an *item-tracking program* for the Corner Grocer

The program that the Corner Grocer is asking you to create should address the following functional requirements:
*/
#include <iostream>
#include <map>
#include <fstream>
#include <string>

// I used a class for the menu to honor the principles of OOP.
class Menu {
    public:
        void displayMenu() {
            std::cout << "1. Search for an item\n";
            std::cout << "2. Print all item frequencies\n";
            std::cout << "3. Print Histogram\n";
            std::cout << "4. Exit\n";
        }

        int getChoice () {
            int choice;
            std::cout << "Enter your choice (1-4): ";
            std::cin >> choice;
             
            // Validation, should be between 1 and 4 ONLY
            while (choice < 1 || choice > 4) {
                std::cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
                std::cout << "Enter your choice (1-4): ";
                std::cin >> choice;
            }
             
            return choice;
        }
};

// The CornerGrocerApp class talks to the Menu class and handles the data processing, sending it back to the Menu class for display.
class CornerGrocerApp {
private:
    std::map<std::string, int> itemFrequencies;
    std::string inputFileName = "CS210_Project_Three_Input_File.txt";
    std::string backupFileName = "frequency.dat";
    Menu menu;

    bool loadData() {
        std::ifstream inputFile(inputFileName);

        if (!inputFile) {
            std::cerr << "Could not open file: " << inputFileName << std::endl;
            return false;
        }

        std::string item;
        while (inputFile >> item) {
            itemFrequencies[item]++;
        }

        return true;
    }

    void saveFrequencyBackup() {
        std::ofstream outputFile(backupFileName);

        if (!outputFile) {
            std::cerr << "Could not create backup file: " << backupFileName << std::endl;
            return;
        }

        for (const auto& pair : itemFrequencies) {
            outputFile << pair.first << " " << pair.second << std::endl;
        }
    }

    void searchItemFrequency() {
        std::cout << "Enter item name to search: ";
        std::string itemName;
        std::cin >> itemName;
        auto it = itemFrequencies.find(itemName);
        if (it != itemFrequencies.end()) {
            std::cout << "Frequency of " << itemName << ": " << it->second << std::endl;
        } else {
            std::cout << itemName << " not found!" << std::endl;
        }
    }

    void printAllFrequencies() {
        for (const auto& pair : itemFrequencies) {  // Here we use a key-value pair to iterate through the map and print each item and its frequency.
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    void printHistogram() {
        for (const auto& pair : itemFrequencies) {
            std::cout << pair.first << ": " << std::string(pair.second, '*') << std::endl;
        }
    }
// The run method is the main loop of the application, handling user input and calling the appropriate methods based on the user's choice.
public:
    void run() {
        if (!loadData()) {
            std::cerr << "Failed to load data from file." << std::endl;
            return;
        }

        saveFrequencyBackup();

        int choice;
        do {
            menu.displayMenu();
            choice = menu.getChoice();

            switch (choice) {
                case 1:
                    searchItemFrequency();
                    break;
                case 2:
                    printAllFrequencies();
                    break;
                case 3:
                    printHistogram();
                    break;
                case 4:
                    std::cout << "Exiting program. Goodbye!" << std::endl;
                    break;
            }
        } while (choice != 4);
    }
};
int main() {
    CornerGrocerApp app;
    app.run();
    return 0;
}

/*
[]  Documentation:
Describe your code’s design and functionality. Include screenshots to support your description. As you complete this work, your manager at Chada Tech is interested to see your thought process regarding how you use C++.
*/
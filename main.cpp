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

    public:
        void loadData() {
            std::ifstream inputFile(inputFileName);

            if (!inputFile) {
                std::cerr << "Could not open file!" << inputFileName << std::endl;
                return;
            }

            std::string item;
            while (std::getline(inputFile, item)) {
                itemFrequencies[item]++;
            }

            inputFile.close();
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

            outputFile.close();
        }
};

int main() {
    std::cout << "Hello, World!\n";
    return 0;
}

/*
[]  Documentation:
Describe your code’s design and functionality. Include screenshots to support your description. As you complete this work, your manager at Chada Tech is interested to see your thought process regarding how you use C++.
*/
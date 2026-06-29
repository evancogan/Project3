# Corner Grocer Item Tracking Program

# *Overview*
The Corner Grocer was in need of a program that 'analyzes the text records they generate throughout the day.' 

"These records list items purchased in chronological order from the time the store opens to the time it closes."

The program is a console based tracking app that reads this data from an input file and counts how many times each one appears, using a map. Then, it gives the user a menu to search for said item, print all the frequencies of the items, or display a complete histogram of the counts.

# *Features*
*   A built in histogram creator
*   Check item frequencies

# *How to Run*
Open the terminal in the project folder and compile the program with:

```bash
g++ -std=c++17 main.cpp -o corner_grocer
```

Then run it with:

```bash
./corner_grocer
```

Make sure the input file is in the same folder as the program so it can load the item data correctly.

# *Screenshots*
![Screenshot of the app](screenshot1.png)
![Screenshot 2](screenshot2.png)

# *Design Notes*
The CornerGrocerApp class talks to the Menu class and handles the data processing, sending it back to the Menu class for display.
This was done to follow the tenets of Object Oriented Programming (OOP).

# *Reflection*

The corner grocer app is essentially a search engine as well as a histograph maker. It will allow the company to move around products while keeping track of inventory.


I think the app excels in finding the amount of items, and finding the item regardless of case sensitivity, but it falters as an interactable program, where users could change item counts. Although, this section of the code could stay largely the same and a different, modular program could simply pass back and forth input data.
    
The piece of code I found most challenging to strategize is the load data section, and the error handling there. I found that it was relatively boiler-plate, it had its own syntax and I was expected to write around it. When dealing with syntactic problems, however, the solution is always to search the documentation for examples, and finding out what those key words are that makes the program tick. Thus, I definitely think that simply web searching for documentation remains an indespensible tool for interpreting syntax. 

The skills I picked up from this project, are realizing that while syntax can trip you up, design is where you prove your concept is really solid before implementing any code. I found that my design actually helped to keep my margin of error low, as I followed it closely, appreciating that even though coding is largely recipes that get copied around, the implementation of it can be as creative as any other writing medium, and I was intimidated by this, how my code implementation could be so starkly different from another's.

To compensate for originality, I made sure to keep my code well-documented, and anywhere that somethign wasn't plainly obvious by reading it, or if it was a critical part of the program, to plainly state what it does. I have had to learn to scope back my code comments in this class, thanks to professor feedback, as not every line needs an explanation, but I think that those unique critical design moments are a great place to leave a note that explains your reasoning.
# CS-210-portfolio
# CS 210 Module Eight Journal: Corner Grocer

## Project Summary

The Corner Grocer project was developed in C++ to help a grocery store track how often different items are purchased. The program reads grocery items from a text file, counts the frequency of each item, and displays the results to the user. It provides a menu that allows users to search for an individual item, display all item frequencies, view a histogram, or exit the program. It also creates a `frequency.dat` file to save the frequency information.

## What Did I Do Particularly Well?

I did well organizing the program into a class and separating the different functions. Using a map made it easier to count grocery items and display the results in alphabetical order. I also used comments and descriptive variable names to make the code easier to understand. The menu made the program simple to use and allowed users to select the information they wanted to see.

## Where Could I Enhance My Code?

One improvement would be to make the program handle grocery item names regardless of capitalization. For example, searching for "apples" should find "Apples." I could also improve error handling for missing input files and failures when creating the backup file. Another improvement would be to separate the file-handling logic from the menu more clearly and add additional tests for different inputs. These changes would make the program more reliable, easier to maintain, and more efficient to troubleshoot.

## What Was the Most Challenging Part?

The most challenging part was working with file input and output and making sure the program counted each grocery item correctly. I needed to understand how to read data from a text file, store the counts in a map, and write the results to another file. I overcame these challenges by reviewing course materials, checking the code carefully, and testing the different menu options. In the future, I can continue using zyBooks, course examples, C++ documentation, and debugging tools in Visual Studio to help solve programming problems.

## Which Skills Are Transferable to Other Projects?

This project helped me practice C++ programming, classes, maps, loops, conditional statements, file handling, and input validation. These skills can be used in other projects that need to process data, store information, or interact with users. I also gained experience breaking a larger problem into smaller functions and testing the program to make sure it works as expected.

## How Did I Make the Program Maintainable, Readable, and Adaptable?

I used meaningful names for variables and functions, added comments to explain important parts of the code, and organized related functionality into a `GroceryTracker` class. The map made it easier to store and retrieve item frequencies without manually tracking each grocery item. Separating the program into functions also makes it easier to update or add features in the future. For example, the program could be expanded to support more reports or save additional information about grocery purchases.

## AI Assistance Acknowledgment

I used ChatGPT to help review the project requirements, organize my reflection, and improve the clarity of my writing. I reviewed the material and am responsible for understanding the submitted code and reflection.

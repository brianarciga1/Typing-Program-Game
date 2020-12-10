# An Efficient Code Typing Trainer
 
Authors: [Scott Vo](https://github.com/hscottvo), [Danin Namiranian](https://github.com/Danin1993), [Brian Arciga](https://github.com/brianarciga1)

## Project Description
* Typing is an essential skill in today's technology-based society, especially to people who type for a living. The first thing that comes to mind with the thought of "professional typist" is programming. As a programmer, be it in C++ or SQL, typing is the most important interface between a programmer and their computer. Typing efficiency is important to programmers because they need to be efficient in writing code, and finding the where each letter is on a keyboard should be the least of their worries. 
  * There will be choices of text in the form of a set of random words, or a paragraph or quote. The test material will be pulled from a local database. 
  * Typing tests will be timed, with choices of time limits, such as 30 seconds, 1 minute, or two minutes. 
* We are using [ncurses](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html) be our main user interface by detecting keypresses. 
* The input will be the keypresses of the user. The output will be the words that the user types, in colors depending on the correctness of the user's input. 
* We intend to use the Composite, Observer and Strategy design patterns for the project. 
  * Composite will be useful to manage the multiple components that will be a part of the test, such as the text material window, timer, and key input. 
    * An Initializer object will be the main running loop of the program. It will instantiate Typing Tests with settings based on what the user has set beforehand. 
    * Text classes will handle the storage of test material and validating user inputs when compared to the material. 
    * UserList will hold a vector of Users to interface with the Observer class.
    * TypingTest will use the classes from the Strategy pattern to retrieve passages for the user to type.
  * Strategy pattern will be used to read and display typing material. 
    * There will be at least 3 main strategies, creating typing material with:
      1. Quotes
      2. Paragraphs
      3. A collection of random words
  * Observer will be used to keep track of users on a leader board. Users will be ranked based on their typing efficiency.
    * There would be three main functions. Users will have the option to add and reset their scores.
    * Users should also be able to return the score for the top users.
    * A leaderboard object would contain child Score (name TBD) objects and would change and return results based on test results and score queries.

## Class Diagram

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSwanho9HYGWpyReDs0W0ro39obf76mRsjeyf73z6PT0jZE5E_Qc7GBUylH1muTeXfJJjXDmGRLVoDr/pub?w=2552&amp;h=1644">

 ## Screenshots
![Typing Gameplay - Incorrect words are highlighted](https://user-images.githubusercontent.com/56327086/101737483-caa1fe80-3a79-11eb-80dc-e40c713de45a.JPG)
![Test Results](https://user-images.githubusercontent.com/56327086/101737106-48193f00-3a79-11eb-9926-380cafc8cfb0.JPG)
![User Login](https://user-images.githubusercontent.com/56327086/101737319-8d3d7100-3a79-11eb-9490-8b9f399d4da8.JPG)

 ## Installation/Usage
To build and compile: 
  In your terminal, install the [ncurses](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html) library by entering the command:  
  <code>sudo apt-get install libncurses5-dev libncursesw5-dev</code>  
To run the existing executable, enter the command:  
  <code>./TypingTest</code>  
and follow the instructions. 
 ## Testing
 Testing for non-void functions was done using GoogleTest. For features handling the program's GUI, the developer manually checked for bugs on normal, edge, and corner cases. 
 

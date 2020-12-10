# An Efficient Code Typing Trainer
 
Authors: [Scott Vo](https://github.com/hscottvo), [Danin Namiranian](https://github.com/Danin1993), [Brian Arciga](https://github.com/brianarciga1)

## Project Description
* Typing is an essential skill in today's technology-based society, especially to people who type for a living. The first thing that comes to mind with the thought of "professional typist" is programming. As a programmer, be it in C++ or SQL, typing is the most important interface between a programmer and their computer. Typing efficiency is important to programmers because they need to be efficient in writing code, and finding the where each letter is on a keyboard should be the least of their worries. 
  * There will be choices of quotes pulled from the internet, random strings of words, and we are looking to add code snippets as well if we can do it in time.
  * Typing tests will be timed, with choices of time limits, such as 30 seconds, 1 minute, or two minutes. 
* We are considering using [ncurses](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html) be our main user interface by detecting keypresses. 
* The input will be the keypresses of the user. The output will be the words that the user types, in colors depending on the correctness of the user's input. 
* We intend to use the Composite, Observer and Strategy design patterns for the project. 
  * Composite will be useful to manage the multiple components that will be a part of the program window, such as the typing box, text prompt, and timer. 
    * A Canvas object that inherits a Graphic object would be the main part of the window, and the other components would lie on it.
    * Then, a something like a Textbox object would be overlayed onto the Canvas to create an interface for the user to type the words that show up on the screen.
    * Each Graphic object that contains text in the form of a string will have member functions that will allow the text and its background change color, for example when a user gets a correct or incorrect spelling of a word.
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
 

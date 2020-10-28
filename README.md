# An Efficient Code Typing Trainer
 
Authors: \<[Scott Vo](https://github.com/hscottvo), [Danin Namiranian](https://github.com/Danin1993)\>

## Project Description
* Typing is an essential skill in today's technology-based society, especially to people who type for a living. The first thing that comes to mind with the thought of "professional typist" is programming. As a programmer, be it in C++ or SQL, typing is the most important interface between a programmer and their computer. Typing efficiency is important to programmers because they need to be efficient in writing code, and finding the where each letter is on a keyboard should be the least of their worries. 
  * There will be choices of quotes pulled from the internet, random strings of words, and we are looking to add code snippets as well if we can do it in time.
  * Typing tests will be timed, with choices of time limits, such as 30 seconds, 1 minute, or two minutes. 
* We are considering using [windows.h](https://docs.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows) to do our window managing and keypress detection. 
* The input will be the keypresses of the user. The output will be the words that the user types, in colors depending on the correctness of the user's input. 
* We intend to use the Composite and Abstract Factory design patterns for the project. 
  * Composite will be useful to manage the multiple components that will be a part of the program window, such as the typing box, text prompt, and timer. 
    * A Canvas object that inherits a Graphic object would be the main part of the window, and the other components would lie on it.
    * Then, a something like a Textbox object would be overlayed onto the Canvas to create an interface for the user to type the words that show up on the screen.
    * Each Graphic object that contains text in the form of a string will have member functions that will allow the text and its background change color, for example when a user gets a correct or incorrect spelling of a word.
  * Abstract Factory will be useful in instantiating the above objects, as some of them are very similar.
    * Depending on the user's settings, the program will present them with different forms of text, such as words or quotes. These would have different classes with different implementations, so the factory would help us organize the instantiation of the test material. 
    * There will be separate factories for each type of test material. For example, "Word" for a set of random words, "Quote" for a random 1-2 sentence quote, or "Paragraph" for a longer paragraph. 
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [toolname](link) - Short description
 > * What will be the input/output of your project?
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 

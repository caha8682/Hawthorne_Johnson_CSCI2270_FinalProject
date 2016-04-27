# Hawthorne_Johnson_CSCI2270_FinalProject
This project team consists of Cassidy Hawthorne and Abby Johnson. The project will use the data structure of linked lists and will be based off of homework 4 with 5 added functions. The project can be run through Code Blocks.

To run this project download main.cpp, CommunicationNetwork.h, and CommunicationNetwork.cpp. These functions must be run together. CommunicationNetwork.h is the header file and CommunicationNetwork.cpp is the corresponding code for the functions in the header.  When this project is run a menu pops up with 11 options:
1. Build Network
2. Print Network Path
3. Transmit Message Coast-To-Coast-To-Coast
4. Transmit Message from City A to City B
5. Total Number of Words Transmitted
6. Delete Message
7. Add City
8. Delete City
9. Distance Between Cities
10. Clear Network
11. Quit

Here's how each function works.
1. Build Network - must be the first command and it simply builds the network.
2. Print Network Path - this shows the current path between cities and is updated with cities are added or deleted
3. Transmit Message Coast-To-Coast-To-Coast - this prompts users for a message, of any length, and transmits the message through the network word by word
4. Transmit Message from City A to City B - this prompts users for a starting city, ending city, and message anf then transmits the message word by word between the two cities
5. Total Number of Words Transmitted - this function counts the total number of words transmitted through each city. The total number does not change when the message gets deleted
6. Delete Message - deletes message in all cities
7. Add City - this function prompts users for a new city to add and a previous city. The function adds the new city before the previous city. To add at the beginning of the network the previous city must be "First"
8. Delte City - this function prompts users for a city to delete and deletes it 
9. Distance Between Cities - this function prompts users for two cities and outputs the number of cities between them
10. Clear Network - this function deletes all cities
11. Quit - this function takes the user out of the program and clears the network if that has not been done yet

Add city and delete city do not show what the network looks like after adding or deleting a city. To see the new network use command 2 to print the network path.

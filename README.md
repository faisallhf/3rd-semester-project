# 3rd-semester-project
This is my third semester project in c++.
This C++ program is a simple contact book application that allows users to manage their contacts.

1. **Node Structure (Node):**
   - This structure defines the basic structure of a contact with two fields: name and phone number.
   - It also includes pointers to the next and previous nodes, allowing the creation of a linked list of contacts.

2. **ContactBook Class (ContactBook):**
   - This class represents the main contact book application.
   - It manages the linked list of contacts and provides various functions for adding, editing, searching, deleting, displaying, and saving contacts.

3. **Loading Animation (Loading):**
   - This function provides a loading animation when the program starts.

4. **Create Contact (CreateNode):**
   - This function allows users to create a new contact by entering a name and phone number.
   - Contacts are added to the linked list.

5. **Display Contacts (Display):**
   - This function displays all the contacts in the contact book, including their names and phone numbers.

6. **Search for a Contact (Search):**
   - Users can search for a contact by name, and the program displays the contact's details if found.

7. **Edit Contacts (EditContacts):**
   - Users can edit a contact's name and phone number by searching for it first.
   - After editing, the contact's information is updated.

8. **Delete Contacts (DeleteContactBySearch):**
   - Users can delete a contact by searching for it either by name or phone number.
   - Deleted contacts are removed from the linked list.

9. **Delete All Contacts (DeleteAllContacts):**
   - This function allows users to delete all contacts from the contact book.

10. **Save Contacts to File (SaveContact):**
    - Contacts are saved to a file called "contactbook.txt" for persistence.
    - The program writes the contact information to the file.

11. **Read Contacts from File (ReadContact):**
    - When the program starts, it reads contacts from the "contactbook.txt" file and populates the linked list with these contacts.

12. **Main Menu (MainMenu):**
    - This function displays the main menu of the contact book application.
    - Users can choose various actions like adding, editing, searching, deleting, displaying, or exiting the application.

13. **Main Function (main):**
    - The main function initializes the ContactBook class, loads contacts from the file, and displays the main menu to the user.

Overall, this project provides a user-friendly interface for managing contacts, including adding, editing, searching, and deleting contacts. It also ensures that contacts are saved and loaded from a file for data persistence across multiple program runs.

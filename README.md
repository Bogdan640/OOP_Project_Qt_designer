# OOP Trench Coat Shop Management System

This is a complex C++ Object-Oriented Programming (OOP) project that manages the infrastructure of a trench coat shop. The application offers two modes of operation: **Administrator Mode** and **Client Mode**, providing separate functionalities for managing and purchasing coats. The graphical interface of this project is created using **Qt Designer**.

## Features

### Administrator Mode
As an administrator, you have complete control over managing the trench coat database. The following functionalities are available to maintain and update the inventory:

- **Add a new coat:**  
  Input and store details of a new coat (size, color, price, quantity) in the database for future availability.
  
- **Remove an entire stock of coats:**  
  Delete all entries of a specific coat from the database, effectively removing the entire stock if no longer needed.

- **Remove a specific coat:**  
  Remove an individual coat from the database, keeping other stock intact.

- **Update coat information:**  
  Modify the details of an existing coat, such as updating its price, size, color, or other attributes.

- **Display all coats:**  
  View the list of all coats currently stored in the database, including their details and quantities, to assess the current stock.

- **Exit the application:**  
  Exit Administrator Mode and return to the main menu once inventory management is complete.

### Client Mode
As a client (user), you can browse through the collection of trench coats and manage your shopping experience. The following features are provided:

- **Browse available trench coats:**  
  View the collection of trench coats in the store. Navigate through the options and select coats to add to your shopping basket. Explore the variety of coats based on their sizes, colors, and prices.

- **View your shopping basket:**  
  Review the items added to your shopping basket, along with the total price of all selected coats.

- **Save your shopping basket to a file:**  
  Export and save the details of the items in your shopping basket to a file for future reference.

- **Exit the application:**  
  When you're done browsing or managing your basket, exit Client Mode.

## Graphical Interface

The application’s graphical interface is designed using **Qt Designer**, providing a user-friendly and visually appealing way to interact with both Administrator and Client modes.

## How to Run the Project

1. Clone this repository using Git:
   ```bash
   git clone https://github.com/Bogdan640/OOP_Project_Qt_designer.git

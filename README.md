# Proper Trench Coats - Coat Management Application

## Overview

The **Proper Trench Coats** application is a console-based program designed for managing a database of trench coats. It supports two main modes: **Administrator Mode** for stock management and **User Mode** for browsing and purchasing coats. This project is written in C++ with a focus on Object-Oriented Programming (OOP) principles and follows the **Model-View-Controller (MVC)** architecture.
The program runs in both **Terminal** mode and **Graphical Interface (GUI)** mode, providing flexibility for different types of users. Additionally, the application offers **Undo** and **Redo** functionalities for enhanced usability.

## Features

### Administrator Mode
In this mode, administrators can:
- **Add a Coat**: Add a new trench coat to the database with size, color, price, quantity, and photo URL.
- **Remove a Coat**: Remove either a full stock or individual coat based on size and color.
- **Update a Coat**: Update existing coat details such as price, quantity, and photo URL.
- **Display All Coats**: List all the coats in the database, with their details.

### User Mode
Users can:
- **Browse Coats**: View available trench coats, filtered by size.
- **Add to Basket**: Add selected coats to a shopping basket and track the total price.
- **Save Basket**: Save the shopping basket to a file.
- **View Basket**: Display all items in the shopping basket and their total cost.

###  Undo/Redo Services
The program includes **Undo** and **Redo** functionalities that allow the administrator to easily revert or repeat their last actions. This feature applies to operations like adding, removing, or updating coats in the database.

- **Undo**: Reverts the last modification (e.g., adding a coat, removing a coat).
- **Redo**: Re-applies the last reverted action.

### File Handling and Exception Management
- **File Saving**: Users can save the shopping basket to a file by providing a file path.
- **Exception Handling**: The system manages various runtime errors such as invalid inputs and file I/O issues.

### MVC Architecture
The application follows the **Model-View-Controller (MVC)** design pattern:
- **Model**: Represents the data (coats and shopping basket).
- **View**: Provides a console-based user interface.
- **Controller**: Handles the communication between the view and the model.

## How to Run

1. Clone the repository.
2. Compile the C++ source files.
3. Run the executable in the console.

## Example Usage

Upon running the program, the user will be prompted to choose between **Administrator Mode** or **User Mode**. From there, they can interact with the application by following the menu options.

### Administrator Mode
- Add, remove, update, and display coats in the database.

### User Mode
- Browse available coats, add coats to the shopping basket, view the total price, and save the basket to a file.

## Graphical Representation

The application also allows the creation of a graphical representation of the data. For example, we can create a **bar chart** that represents the number of coats available for each size. This visual representation provides an intuitive understanding of the stock distribution across various sizes.

## Technologies Used
- **C++**
- **Object-Oriented Programming (OOP)**
- **Model-View-Controller (MVC) Architecture**
- **Exception Handling**



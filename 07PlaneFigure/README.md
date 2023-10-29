# Plane Figures Calculator

This C++ program calculates the area and perimeter of four simple plane figures: a rectangle, a circle, a square, and a triangle. The program takes advantage of the concepts of Inheritance and Polymorphism, utilizing a base class called "PlaneFigure" and derived classes ("Rectangle", "Circle", "Square", and "Triangle").

## Program Overview

1. **Introduction and User Input:**
   - The program starts by explaining its purpose to the user.
   - It prompts the user to select a plane figure (rectangle, circle, square, or triangle) and requests necessary information based on the user's selection.

2. **Calculation and Output:**
   - The program calculates and displays the perimeter and area of the selected figure.
   - It utilizes polymorphism to call overridden methods for perimeter and area specific to the chosen figure.

3. **Repeat or Exit:**
   - After displaying the calculated values, the program asks the user if they would like to find the perimeter and area of another figure.
   - If the user chooses to calculate another figure, the process repeats; otherwise, the program exits.

## Implementation Details

- **Base Class: `PlaneFigure`**
  - Defines common attributes and methods for all plane figures.
  - Contains pure virtual methods `perimeter()` and `area()`, which are overridden by derived classes.
  
- **Derived Classes: `Rectangle`, `Circle`, `Square`, and `Triangle`**
  - Inherited from the `PlaneFigure` base class.
  - Implement specific calculations for perimeter and area based on the properties of each figure.
  
- **Polymorphism and Inheritance:**
  - Utilizes polymorphism to invoke appropriate methods for perimeter and area based on the selected figure.
  - Demonstrates inheritance by inheriting properties and methods from the base class.

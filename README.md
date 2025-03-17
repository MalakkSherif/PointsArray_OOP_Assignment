# PointsArray Project

## 📌 Project Overview
This project is an implementation of a `PointsArray` class as part of the Object-Oriented Programming course at Cairo University. The `PointsArray` class represents a dynamic 2D array of `Point` objects and provides various functionalities for manipulating the array using object-oriented principles.

---

## 🏗️ Implemented Features
### 🔹 Point Class
Defines individual points with X and Y coordinates and provides essential operations:
- **Attributes:**
  - `x`: Integer representing the X-coordinate.
  - `y`: Integer representing the Y-coordinate.
- **Methods:**
  - Setters and getters for `x` and `y`.
  - `print()`: Displays the coordinates as `(x, y)`.

### 🔹 PointsArray Class
Manages a dynamic 2D array of `Point` objects with various operations:
- **Attributes:**
  - `array`: 2D dynamic array of `Point` objects.
  - `rows`: Number of rows.
  - `columns`: Number of columns.
- **Core Functionalities:**
  - Constructor initializes all points to `(0,0)`.
  - Copy constructor for deep copying.
  - Getter methods for row and column counts.
  - Operator overloading for easy input/output and arithmetic operations.
  - Functions for modifying rows and columns dynamically.
  - Destructor for proper memory management.

---

## ⚙️ Key Features
### Input Parameters:
- Number of rows and columns.
- 2D array elements (points with X and Y coordinates).

### Operations Supported:
- **Basic Functionality:**
  - Initialize a `PointsArray`.
  - Copy an existing `PointsArray`.
  - Retrieve row and column counts.
- **Data Manipulation:**
  - Add an integer value to all points.
  - Swap two rows efficiently.
  - Delete a column dynamically.
  - Add a new column at a specific position.
- **Display Options:**
  - Print `PointsArray` in matrix format.
  - Overloaded insertion (`>>`) and extraction (`<<`) operators for streamlined input/output.

---

## 🖥️ Program Menu
1️⃣ **Initialize PointsArray** (define rows & columns)
2️⃣ **Copy an existing PointsArray**
3️⃣ **Display number of rows**
4️⃣ **Display number of columns**
5️⃣ **Enter PointsArray elements**
6️⃣ **Display PointsArray elements**
7️⃣ **Add an integer to all points**
8️⃣ **Swap two rows**
9️⃣ **Delete a column**
🔟 **Add a new column**
1️⃣1️⃣ **Print PointsArray as a matrix**
1️⃣2️⃣ **Exit the program**

🔄 The menu repeats until the user chooses to exit.

---

## 🔧 Technical Details
- **Programming Language:** C++
- **Course:** Object-Oriented Programming
- **Institution:** Cairo University, Faculty of Computers & Artificial Intelligence

---

## 🚀 How to Use
1️⃣ Compile the program:
   ```sh
   g++ main.cpp points_array.cpp -o program
   ```
2️⃣ Run the executable:
   ```sh
   ./program
   ```
3️⃣ Follow the on-screen menu instructions to interact with the `PointsArray`.

---

## 👨‍💻 Contributors
- **Malak Sherif**
- **Amira Emad** 

---
### 📚 Developed for the Object-Oriented Programming Course at Cairo University


# X11 GUI Framework: Basic Window, Panel, and Button Management in C++

This project provides a lightweight object-oriented framework for creating graphical user interfaces (GUIs) using the X11 windowing system in C++. It includes core classes for managing windows, panels, and buttons, with custom color handling and a clean separation of concerns.

---

## Features

- RGB Color Management: Simple conversions between RGB values and X11 color format.
- Button Class: Create and render buttons with custom sizes, labels, and colors.
- Panel Class: Organize buttons inside resizable, movable panel containers.
- CuWindow Class: Manage the overall application window, background, and GUI elements.
- Overlapping Detection: Panels and Buttons detect and prevent overlap for clean layouts.
- Custom Drawing: Rendering handled manually through X11 library calls for flexibility.

---

## Project Structure

| File              | Purpose                                                               |
| ----------------- | --------------------------------------------------------------------- |
| RGB.h/.cc         | Manage RGB color conversion and operations.                           |
| Button.h/.cc      | Define and draw interactive button elements.                          |
| Panel.h/.cc       | Create containers that organize multiple buttons.                     |
| CuWindow.h/.cc    | Main window management, event handling, and panel organization.       |
| defs.h            | Constants and predefined color values.                                |
| main.cc           | Test suite to demonstrate functionality of all classes.               |
| Makefile          | Build instructions for compiling the project.                         |


---

### Build Instructions

Run any of the following commands in your terminal:

make  
or  
make all  
or  
make a1  

This will generate an executable named a1.

---

## Running the Application

After compilation, run:

./a1  

This will open a window displaying various panels and buttons, demonstrating GUI management and rendering functionalities.

---

## Notes

- The Tester class is used to validate the functionality of the framework.
- Memory management, array bounds, and overlap detection are carefully handled.
- Only standard C++ libraries (iostream, string, sstream, iomanip) are used.
- No external libraries beyond X11 are required.

This program was created by @MRESHMA25

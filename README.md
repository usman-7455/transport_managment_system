# transport_managment_system

# Transport Management System

This is a C++ based Transport Management System designed to manage data related to vehicles, drivers, customers, and service bookings. It provides a basic interface to handle transportation services, user authentication, booking history, and maintenance records.

## Features

- Manage vehicles, customers, and drivers
- Book and track transportation services
- Maintain booking and maintenance history
- User authentication via admin password
- Simple text file-based data storage

## Folder Structure

- `functions/`, `super_interface/`, etc.: Contain C++ header and source files for different components
- `.sln`, `.vcxproj`: Visual Studio project and solution files
- `.txt` files: Data files for entities like `drivers`, `customers`, `servicesbooked`, etc.

## How to Run

1. **Open with Visual Studio**:
   - Double-click `transport_management_system.vcxproj` to open the project in Visual Studio.
   
2. **Build the project**:
   - Go to `Build > Build Solution` (or press `Ctrl + Shift + B`).

3. **Run the project**:
   - Press `Ctrl + F5` or click `Start Without Debugging`.

Ensure all data files (`.txt`) are in the same directory as the executable to avoid file not found errors.


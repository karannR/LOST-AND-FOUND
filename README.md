# College Lost and Found System (GUI Version)

A simple desktop application built with C++ and Qt that lets students
report lost items and check if their item has been found.

## What's inside

| File | What it does |
|------|-------------|
| `main.cpp` | Entry point - opens the main window |
| `mainwindow.h` / `mainwindow.cpp` | GUI logic - handles all button clicks |
| `mainwindow.ui` | Layout of the window (open in Qt Designer) |
| `lostandfound.h` / `lostandfound.cpp` | Core classes and DSA logic |
| `CMakeLists.txt` | Build configuration |

## DSA Concepts Used

- **Hashing (`unordered_map`)** - fast lookup of found items by name
- **Queue** - stores pending lost reports in order (FIFO)
- **Priority Queue** - high-value items (ID card, wallet, phone, laptop)
  are marked as urgent
- **Sorting** - found items list is sorted by date (most recent first)
- **OOP** - `Item` (base), `FoundItem`, `LostReport`, and
  `LostAndFoundCenter` classes with inheritance and encapsulation

## How to Build and Run

### Step 1: Install Qt

Download the free open-source Qt installer from:
<https://www.qt.io/download-open-source>

During install, select:
- Qt 6.5 or later
- MinGW compiler (on Windows) or your platform's default
- Qt Creator
- CMake

### Step 2: Open the project

Option A - Qt Creator (easier):
1. Open Qt Creator
2. File > Open File or Project
3. Select `CMakeLists.txt` from this folder
4. Configure with your Qt kit
5. Click the green Run button

Option B - VS Code:
1. Install the "Qt C++" and "CMake Tools" extensions
2. Register your Qt installation via Command Palette: `Qt: Register Qt Installation`
3. Open this folder in VS Code
4. Select CMake kit at the bottom
5. Press F5 to build and run

### Step 3: Use the app

The app opens with 6 tabs:

1. **Search** - type any keyword to check if your item has been found
2. **Report Lost Item** - fill the form to add a lost report
3. **Report Found Item (Staff)** - staff can add items handed in
4. **All Found Items** - browse everything, sorted by date
5. **Urgent Items** - high-priority items shown first (priority queue)
6. **Pending Reports** - see the queue of unmatched lost reports and
   process them one by one

## Sample data

The app comes pre-loaded with 3 sample items so the tables are not empty
on the first run.

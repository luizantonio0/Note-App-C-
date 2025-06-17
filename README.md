# Note App C

This is a simple note-taking application written in C. It allows you to create, view, update, and remove notes, storing everything in memory during execution.

## Features
- Add a new note
- List all notes
- Update an existing note
- Remove a note
- Automatic sorting of notes by title

## How to Use
1. Compile the program:
   
   ```sh
   gcc -o main.exe main.c
   ```

2. Run the program:
   
   ```sh
   ./main.exe
   ```

3. Follow the interactive menu to manage your notes.

## Project Structure
- `main.c`: Main source code of the application.
- `build/`, `output/`: Build output folders.

## Notes
- Notes are not saved to a file, only in memory.
- Limit of 100 notes.

---
Developed for educational purposes.

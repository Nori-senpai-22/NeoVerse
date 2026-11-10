# NeoVerse Simulation

NeoVerse is a C++ city-management simulation demonstrating authentication,
sensor data management, polymorphism, event processing, and file persistence.

## Requirements

- Windows, macOS, or Linux
- A C++ compiler with C++14 support
- MinGW g++ on Windows, or GCC/Clang on macOS and Linux

## Project Structure

```text
NeoVerse-main/
|-- include/              Header files
|-- src/                  C++ source files
|   |-- main.cpp          Program entry point
|-- README.md
```

## How to Run the Application

Open a terminal in the project folder. Build the application the first time, or
after changing the source code, then run the generated executable. On later runs,
you can skip the build command and launch the executable directly.

### Windows

These commands are for PowerShell, not Bash. Open PowerShell in the folder that
contains the outer `NeoVerse-main` folder, then run:

```powershell
cd .\NeoVerse-main\NeoVerse-main
$sourceFiles = Get-ChildItem .\src\*.cpp | ForEach-Object { $_.FullName }
g++ -std=c++14 $sourceFiles -I .\include -o .\neoverse_sim.exe
\.\neoverse_sim.exe
```

If PowerShell is already in the project folder (the folder containing `src` and
`include`), skip the `cd` line. To launch the program again after building, run:

```powershell
.\neoverse_sim.exe
```

### macOS or Linux

In Bash, do not use the Windows `.exe` command or backslash paths. For this
workspace, if your terminal is at `/workspaces/NeoVerse`, run:

```bash
cd NeoVerse-main/NeoVerse-main
g++ -std=c++14 src/*.cpp -Iinclude -o neoverse_sim
./neoverse_sim
```

If your terminal is already in the project folder (the folder containing
`src/` and `include/`), skip the `cd` command.

## Login Credentials

The program asks for a username and password when it starts. You can use
either of these accounts:

| Username | Password | Clearance |
|---|---|---|
| `alex_sys` | `secure123` | High |
| `sarah_ai` | `neo2035` | Medium |

## After Login

After a successful login, the program displays the main NeoVerse control menu.
Use the number keys to choose an action and press Enter after each input.

Available options:

1. Add sensor reading
2. Remove outdated sensor readings
3. Display sensor readings
4. Sort & analyze readings
5. Count critical alerts
6. Add historical log
7. Display historical logs
8. Add standard event
9. Add emergency override
10. Process next emergency
11. Process next standard event
12. Process events by minimum severity
13. Show queues / load report
14. Export sensor readings to CSV
15. Save engineers & logs
0. Exit

A simple workflow is:

- Choose `3` to view current sensor data
- Choose `4` to sort and analyze readings
- Choose `8` or `9` to create events
- Choose `13` to inspect queue and load status
- Choose `0` when you are finished

This lets you explore the simulation immediately after authentication without
needing to read the source code first.

## Features Demonstrated

- Engineer authentication using `std::vector` and `std::find_if`
- City sensor readings and historical log management
- Critical sensor alert analysis using STL algorithms
- Object-oriented city components and polymorphism
- Standard events processed using a queue
- Emergency overrides processed using a stack
- Saving engineers and city logs to data files
- Loading configuration data from `config.txt`

## Generated Files

After a successful run, the program may create or update:

- `engineers.dat` - Saved engineer data
- `city_logs.dat` - Saved city log data
- `config.txt` - Optional configuration file read by the program

These files are created in the project folder unless another path is configured.

## Troubleshooting

### `g++ is not recognized`

Install MinGW-w64 or another GCC distribution, then add its `bin` folder to
the Windows PATH environment variable. Restart PowerShell after changing PATH.

### `No such file or directory`

Make sure PowerShell is running in the project folder:

```powershell
cd path\to\NeoVerse-main
```

You can confirm the location with:

```powershell
Get-Location
```

### Login fails

Enter one of the exact username and password pairs listed above. The password
is case-sensitive.
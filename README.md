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

## Build and Run on Windows

Open PowerShell in the project folder and run:

```powershell
cd C:\FAITHABANGI\NeoVerse-main
g++ -std=c++14 src\*.cpp -Iinclude -o neoverse_sim.exe
.\neoverse_sim.exe
```

If your terminal is already open in the project folder, you only need:

```powershell
g++ -std=c++14 src\*.cpp -Iinclude -o neoverse_sim.exe
.\neoverse_sim.exe
```

## Build and Run on macOS or Linux

Open a terminal in the project folder and run:

```bash
g++ -std=c++14 src/*.cpp -Iinclude -o neoverse_sim
./neoverse_sim
```

## Login Credentials

The program asks for a username and password when it starts. You can use
either of these accounts:

| Username | Password | Clearance |
|---|---|---|
| `alex_sys` | `secure123` | High |
| `sarah_ai` | `neo2035` | Medium |

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
cd C:\FAITHABANGI\NeoVerse-main
```

You can confirm the location with:

```powershell
Get-Location
```

### Login fails

Enter one of the exact username and password pairs listed above. The password
is case-sensitive.
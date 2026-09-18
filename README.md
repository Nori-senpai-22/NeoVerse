# Step 1: Navigate to your project folder
cd path/to/NeoVerse

# Step 2: Compile the code
# For Mac / Linux (GCC or Clang):
g++ -std=c++14 src/*.cpp -Iinclude -o neoverse_sim

# For Windows (MinGW):
g++ -std=c++14 src/*.cpp -Iinclude -o neoverse_sim.exe

# Step 3: Run the simulation
# Mac / Linux:
./neoverse_sim

# Windows:
neoverse_sim.exe
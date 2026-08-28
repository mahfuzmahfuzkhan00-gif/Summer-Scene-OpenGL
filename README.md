# Train Journey - Scene 1: Summer Scene 🌞

OpenGL/C++ Group Project - Interactive Four-Season Train Journey

## Project Structure

```
Train-Journey-Scene1/
├── summer_scene.cpp          # Main Scene 1 code
├── Summer.cbp               # Code::Blocks project file
├── README.md                # This file
├── .gitignore               # Git ignore rules
└── bin/                     # Compiled executables (generated)
```

## Setup Instructions

### Prerequisites
- **Code::Blocks IDE** (Free download from https://www.codeblocks.org/)
- **MinGW Compiler** (Usually comes with Code::Blocks)
- **OpenGL Libraries** (FreeGLUT, OpenGL, GLU)

### Windows Setup (Using Code::Blocks)

1. **Install Dependencies:**
   - Download and install Code::Blocks with MinGW
   - Install FreeGLUT development files

2. **Open Project:**
   - Open Code::Blocks
   - File → Open → Select `Summer.cbp`

3. **Compile:**
   - Project → Build Project (Ctrl+F9)
   - Or Build → Build (for specific target)

4. **Run:**
   - Project → Run (Ctrl+F10)
   - Or double-click the executable in `bin/Debug/` or `bin/Release/`

### Linux Setup (Debian/Ubuntu)

```bash
# Install required libraries
sudo apt-get install freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev

# Compile
g++ -std=c++11 -o scene1 summer_scene.cpp -lglut -lGL -lGLU -lm

# Run
./scene1
```

### macOS Setup

```bash
# Install GLUT and OpenGL (usually pre-installed)
# Just compile with:
g++ -std=c++11 -o scene1 summer_scene.cpp -framework GLUT -framework OpenGL

# Run
./scene1
```

## Scene 1: Summer Landscape 🌻

### Objects in Scene
- ☀️ **Sun** - Bright, changes brightness with right-click
- ☁️ **Clouds** - Moving slowly across sky
- 🌳 **Trees** - 3 trees swaying in the breeze
- 🚂 **Train** - Moving along the railway track
- 🚗 **Car** - Moving on the ground
- 🏠 **Rural House** - Static background building
- 🌊 **River** - With animated wave effect
- 🌾 **Grass & Fields** - Realistic grassland
- 🏔️ **Hills** - Distant background hills
- 💨 **Smoke** - From the train engine

### Animation Features
- Train moves smoothly along track with wheels and windows
- Car movement independent of train
- Clouds drift slowly across sky
- Trees sway realistically in wind
- River water has animated wave highlights
- Smoke puffs from train engine (fading effect)
- All animations run at ~60 FPS

## Controls 🎮

### Keyboard Controls
| Key | Action |
|-----|--------|
| **S** | Start/Stop all animations |
| **T** | Start/Stop train movement |
| **C** | Start/Stop car movement |
| **X** | Toggle tree sway animation |
| **Z** | Move to next scene (Monsoon) |
| **ESC** | Exit program |

### Mouse Controls
| Action | Effect |
|--------|--------|
| **Left Click on Train** | Toggle train movement on/off |
| **Right Click on Sun** | Toggle sun brightness |

## Code Structure & Naming Convention

### Important: Follow Naming Guidelines!

All Scene 1 functions and variables use the **`summer`** prefix to avoid conflicts:

```cpp
// ✅ Correct (Scene 1 Summer)
void summerDrawSun() { }
void summerMoveTrain() { }
float summerTrainX = 0;
bool summerAnimationsRunning = true;

// ❌ Wrong (will cause conflicts during merge)
void drawSun() { }
void moveTrain() { }
float trainX = 0;
```

### Function Categories

**Drawing Functions:**
- `summerDrawTrack()` - Railway track
- `summerDrawSun()` - Sun with glow
- `summerDrawClouds()` - Cloud system
- `summerDrawTrees()` - 3 animated trees
- `summerDrawRiver()` - Animated river
- `summerDrawTrain()` - Complete train
- `summerDrawCar()` - Vehicle
- `summerDrawRuralHouse()` - Background building
- `summerDrawGrass()` - Ground
- `summerDrawHills()` - Hills
- `summerDrawSky()` - Background sky

**Animation Functions:**
- `summerAnimateAll()` - Master animation controller
- `summerMoveTrain()` - Train movement logic
- `summerMoveCar()` - Car movement logic
- `summerAnimateClouds()` - Cloud drift
- `summerAnimateTrees()` - Tree sway
- `summerAnimateRiver()` - Wave animation
- `summerAnimateSmoke()` - Smoke effect

**Interaction Functions:**
- `summerHandleMouseClick()` - Mouse input
- `summerHandleKeyboard()` - Keyboard input

### Key Variables

**Position & Movement:**
```cpp
float summerTrainX = 5.0f;          // Train position
float summerCarX = 30.0f;           // Car position
float summerCloud1X = 10.0f;        // Cloud positions
float summerTree1X = 15.0f;         // Tree positions
```

**Control Flags:**
```cpp
bool summerTrainMoving = false;     // Is train moving?
bool summerCarMoving = false;       // Is car moving?
bool summerAnimationsRunning = true; // Are animations on?
```

**Animation Parameters:**
```cpp
float summerTrainSpeed = 0.15f;     // Train speed
float summerTreeSwayAngle = 0.0f;   // Tree sway angle
float summerRiverWavePhase = 0.0f;  // Wave animation phase
```

## Common Display Settings (DO NOT CHANGE!)

These are shared across all scenes - modifications require team notification:

```cpp
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const float ORTHO_LEFT = 0;
const float ORTHO_RIGHT = 80;
const float ORTHO_BOTTOM = 0;
const float ORTHO_TOP = 45;
const float TRAIN_TRACK_Y = 17.0f;
```

## Git Workflow 🚀

### For Team Members

```bash
# 1. Clone repository
git clone https://github.com/YOUR_USERNAME/Train-Journey-Scene1.git
cd Train-Journey-Scene1

# 2. Before working, always pull latest
git pull origin main

# 3. Create your feature branch
git checkout -b summer-scene-your-name

# 4. Make changes and commit
git add summer_scene.cpp
git commit -m "Add tree animations to summer scene"

# 5. Push to your branch
git push origin summer-scene-your-name

# 6. Create Pull Request on GitHub
# - Go to repository
# - Click "Pull Requests" → "New Pull Request"
# - Select your branch → Create PR
# - Add description of changes
# - Wait for review → Merge
```

### Avoiding Conflicts

1. ✅ Always use `summer` prefix for all new functions/variables
2. ✅ Pull latest code before starting work: `git pull origin main`
3. ✅ Work in separate branches: `git checkout -b your-feature-name`
4. ✅ Review existing functions before creating new ones
5. ✅ Document what you're adding in commit messages

### Merge Checklist

Before creating a Pull Request:
- [ ] All function names have `summer` prefix
- [ ] No conflicts with existing variable names
- [ ] Code compiles without errors
- [ ] Tested in Code::Blocks
- [ ] Commit message is descriptive
- [ ] Pulled latest `main` branch first

## Customization Tips

### Changing Colors
All colors use OpenGL RGB format (0.0 to 1.0):
```cpp
glColor3f(0.2f, 0.5f, 0.8f);  // Blue
glColor3f(0.0f, 0.6f, 0.0f);  // Green
glColor3f(1.0f, 1.0f, 1.0f);  // White
```

### Adjusting Speeds
```cpp
summerTrainSpeed = 0.15f;      // Increase for faster train
summerCloudSpeed = 0.05f;      // Decrease for slower clouds
summerTreeSwaySpeed = 0.05f;   // Adjust tree sway rate
```

### Repositioning Objects
```cpp
float summerSunX = 70.0f, summerSunY = 35.0f;  // Sun position
float summerTree1X = 15.0f, summerTree1Y = 25.0f;  // Tree position
const float TRAIN_TRACK_Y = 17.0f;  // (Don't change this!)
```

## Troubleshooting

### Problem: "Cannot find GL.h"
**Solution:** Install OpenGL development libraries
```bash
# Windows: Use Code::Blocks installer
# Linux: sudo apt-get install libgl1-mesa-dev
# macOS: Pre-installed usually
```

### Problem: "Cannot find glut.h"
**Solution:** Install FreeGLUT development libraries
```bash
# Windows: Download from freeglut.sourceforge.net
# Linux: sudo apt-get install freeglut3-dev
# macOS: brew install freeglut
```

### Problem: Window opens but nothing displays
**Solution:** Check gluOrtho2D values are not modified:
```cpp
gluOrtho2D(0, 80, 0, 45);  // ✅ Correct
gluOrtho2D(0, 1024, 0, 768);  // ❌ Wrong
```

### Problem: Compilation fails with "undefined reference"
**Solution:** Ensure all libraries are linked in Code::Blocks:
- Project → Build Options → Linker settings
- Add: `freeglut`, `opengl32`, `glu32`, `winmm`, `gdi32`

## Team Members

| Name | ID | Role |
|------|-----|------|
| Khandaker Ahmad Nazmus Sakib | 23-54318-3 | Scene 1 Lead |
| Sadiatut Taiyeba | 23-55823-3 | Scene 1 |
| Hasibul Islam Nabil | 22-49909-3 | Scene 1 |
| Md.Redwanul Islam | 23-54770-3 | Scene 1 |

## Next Steps

- [ ] Compile and test Scene 1
- [ ] Push to GitHub
- [ ] Other scenes (Monsoon, Winter, Spring) development
- [ ] Scene transitions
- [ ] Final integration and testing

## Resources

- [OpenGL Tutorial](https://learnopengl.com/)
- [GLUT Documentation](https://www.opengl.org/resources/libraries/glut/)
- [Git Basics](https://git-scm.com/doc)
- [Code::Blocks Help](https://wiki.codeblocks.org/)

## License

Educational Project - International American University

---

**Questions?** Ask the team lead or check the GitHub Issues section!

**Happy Coding!** 🚀


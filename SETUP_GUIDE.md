# Complete Setup & Compilation Guide

## ⚠️ IMPORTANT: Read This Before Starting!

This guide covers all platforms. Choose your operating system and follow carefully.

---

## 🪟 Windows Setup (Code::Blocks Method - RECOMMENDED)

### Step 1: Download Code::Blocks
1. Go to https://www.codeblocks.org/downloads/
2. Download **"Code::Blocks 20.03 (with MinGW Compiler)"**
3. Run the installer and follow instructions
4. When asked about compiler, select **GCC Compiler**

### Step 2: Verify Installation
1. Open Code::Blocks
2. Go to **Settings → Compiler → Global compiler settings**
3. Check that **GCC Compiler** is selected
4. Click **OK**

### Step 3: Install FreeGLUT Libraries
1. Download from: http://freeglut.sourceforge.net/
2. Extract the zip file
3. Copy files:
   - `include/GL/*` → `C:\Program Files\CodeBlocks\MinGW\x86_64-w64-mingw32\include\GL\`
   - `lib/*` → `C:\Program Files\CodeBlocks\MinGW\x86_64-w64-mingw32\lib\`

### Step 4: Open Project
1. Extract the project files to a folder
2. Open Code::Blocks
3. File → Open → Select **Summer.cbp**

### Step 5: Configure Project Settings
1. Project → Properties
2. Go to **Build targets → Debug → Compiler settings**
3. In **Compiler flags** tab, ensure `-Wall` and `-std=c++11` are present
4. Go to **Linker settings** tab
5. Add these libraries (if not already there):
   - freeglut
   - opengl32
   - glu32
   - winmm
   - gdi32

### Step 6: Compile
1. Click **Build → Clean** (first time)
2. Click **Build → Build Project** (Ctrl+F9)
3. Check the output window - should say "Build successful"

### Step 7: Run
1. Click **Build → Run** (Ctrl+F10)
2. The program window should open showing the summer scene

---

## 🐧 Linux Setup (Debian/Ubuntu)

### Step 1: Install Dependencies

```bash
# Update package list
sudo apt-get update

# Install OpenGL and FreeGLUT
sudo apt-get install build-essential
sudo apt-get install freeglut3-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libglu1-mesa-dev
```

### Step 2: Compile from Terminal

```bash
# Navigate to project directory
cd /path/to/Train-Journey-Scene1

# Compile
g++ -std=c++11 -o scene1 summer_scene.cpp -lglut -lGL -lGLU -lm

# Or using clang
clang++ -std=c++11 -o scene1 summer_scene.cpp -lglut -lGL -lGLU -lm
```

### Step 3: Run

```bash
./scene1
```

### Using Code::Blocks on Linux

```bash
sudo apt-get install codeblocks codeblocks-contrib

# Then open Code::Blocks and open Summer.cbp
```

---

## 🍎 macOS Setup

### Step 1: Install Compiler Tools

```bash
# Install Xcode command line tools
xcode-select --install

# Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Step 2: Install OpenGL and FreeGLUT

```bash
# GLUT and OpenGL usually come with macOS
# But install FreeGLUT for compatibility
brew install freeglut
```

### Step 3: Compile

```bash
# Using system GLUT and OpenGL
g++ -std=c++11 -o scene1 summer_scene.cpp -framework GLUT -framework OpenGL -framework Cocoa

# Or if using FreeGLUT from Homebrew
g++ -std=c++11 -o scene1 summer_scene.cpp -L/usr/local/opt/freeglut/lib -I/usr/local/opt/freeglut/include -lglut -framework OpenGL -lm
```

### Step 4: Run

```bash
./scene1
```

### Using Code::Blocks on macOS

```bash
brew install codeblocks

# Open Code::Blocks and open Summer.cbp
```

---

## 📋 Compilation Troubleshooting

### Error: "fatal error: GL/gl.h: No such file or directory"

**Windows (Code::Blocks):**
- Project → Build options → Compiler settings → Directories → Add include path to OpenGL folder

**Linux:**
```bash
sudo apt-get install libgl1-mesa-dev
```

**macOS:**
- This shouldn't happen - GLUT is built-in

### Error: "undefined reference to `__gluPerspective@16'"

**Windows (Code::Blocks):**
- Check Linker settings in Project Properties
- Ensure these are listed:
  - freeglut
  - opengl32
  - glu32
  - winmm
  - gdi32

**Linux:**
```bash
sudo apt-get install libglu1-mesa-dev
```

### Error: "cannot find -lfreeglut"

**Windows:**
- Download and install FreeGLUT properly
- Copy library files to MinGW lib folder

**Linux:**
```bash
sudo apt-get install freeglut3-dev
```

**macOS:**
```bash
brew install freeglut
# Use the command from Step 3 above with full paths
```

---

## 🔍 Verify Installation

### Windows (Code::Blocks)
```
Settings → Compiler → Global compiler settings
→ Toolchain executables tab
→ GCC compiler executable: mingw32-g++.exe (or g++.exe)
```

### Linux
```bash
which g++
which freeglut-config
```

### macOS
```bash
clang++ --version
pkg-config --list-all | grep glut
```

---

## ✅ Quick Test Compilation

### Windows
1. Open Code::Blocks
2. File → New → Project → Console application
3. Select C++
4. Copy-paste `summer_scene.cpp` code
5. Try to compile

### Linux
```bash
# Quick test
g++ -std=c++11 -o test summer_scene.cpp -lglut -lGL -lGLU -lm 2>&1
```

### macOS
```bash
# Quick test
g++ -std=c++11 -o test summer_scene.cpp -framework GLUT -framework OpenGL 2>&1
```

---

## 🚀 Alternative: Online Compiler (Temporary Testing Only)

If local setup is too complicated, you can test code at:
- https://www.onlinegdb.com/ (C++ compiler)

**Note:** OpenGL features may not work online. Use this only for syntax checking.

---

## 📦 Required Files for GitHub

When uploading to GitHub, include:

```
Train-Journey-Scene1/
├── summer_scene.cpp       ✅ Main code
├── Summer.cbp             ✅ Project file
├── README.md              ✅ Documentation
├── SETUP_GUIDE.md         ✅ This file
├── .gitignore             ✅ Git configuration
└── bin/                   ❌ DO NOT COMMIT
└── obj/                   ❌ DO NOT COMMIT
```

---

## 🔗 Useful Links

- **FreeGLUT:** http://freeglut.sourceforge.net/
- **OpenGL:** https://www.opengl.org/
- **Code::Blocks:** https://www.codeblocks.org/
- **MinGW:** http://www.mingw.org/

---

## 💡 Tips for Success

1. **Use the same compiler version** across team members
2. **Test locally before committing** to GitHub
3. **Keep include/lib paths consistent** if working on Windows
4. **Use `-std=c++11` flag** for modern C++ features
5. **Link all required libraries** in order: glut, GL, GLU, m (math)

---

## 🆘 Still Having Issues?

1. Check that ALL libraries are installed
2. Verify compiler is in PATH
3. Try compiling a simple OpenGL test program first
4. Check GitHub Issues section
5. Ask team lead for help

**Good luck! 🎓**


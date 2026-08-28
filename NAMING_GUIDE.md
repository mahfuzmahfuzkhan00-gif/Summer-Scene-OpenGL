# Naming Convention & Code Organization Guide 📝

## 🎯 Golden Rule

**ALL Scene 1 (Summer) code must use the `summer` prefix!**

```
summer + [Category] + [Description]
```

---

## 📋 Variable Naming

### Objects/Positions
```cpp
// Format: summer[ObjectName][Property]X/Y
float summerTrainX = 5.0f;        // Train X position
float summerTrainY = 17.0f;       // Train Y position
float summerCarX = 30.0f;         // Car X position
float summerTree1X = 15.0f;       // First tree X
float summerTree1Y = 25.0f;       // First tree Y
float summerCloud1X = 10.0f;      // First cloud X
float summerSunX = 70.0f;         // Sun X position
float summerSunY = 35.0f;         // Sun Y position
float summerRiverWavePhase = 0.0f; // River animation phase
```

### Movement/Speed
```cpp
// Format: summer[ObjectName]Speed/Direction
float summerTrainSpeed = 0.15f;   // Train movement speed
float summerCarSpeed = 0.1f;      // Car movement speed
float summerCloudSpeed = 0.05f;   // Cloud drift speed
float summerTreeSwaySpeed = 0.05f; // Tree sway speed
```

### Animation Parameters
```cpp
// Format: summer[ObjectName][AnimationType]
float summerTrainX = 0;           // Will animate
float summerTreeSwayAngle = 0.0f; // Sway angle
float summerSmokeOpacity = 1.0f;  // Smoke transparency
float summerSunBrightness = 1.0f; // Sun brightness
```

### Flags/Booleans
```cpp
// Format: summer[ObjectName][State] or summer[ActionName]
bool summerTrainMoving = false;      // Is train moving?
bool summerCarMoving = false;        // Is car moving?
bool summerAnimationsRunning = true; // Are all animations on?
bool summerSmokeVisible = true;      // Is smoke showing?
```

---

## 🎨 Function Naming

### Drawing Functions
```cpp
// Format: summerDraw[ObjectName]()
void summerDrawSun();          // Draw the sun
void summerDrawClouds();       // Draw all clouds
void summerDrawCloud(float x, float y);  // Draw single cloud
void summerDrawTrees();        // Draw all trees
void summerDrawTree(float x, float y, float angle);  // Draw single tree
void summerDrawTrain();        // Draw train
void summerDrawCar();          // Draw car
void summerDrawRiver();        // Draw river
void summerDrawTrack();        // Draw railway track
void summerDrawGrass();        // Draw grassland
void summerDrawHills();        // Draw hills
void summerDrawSky();          // Draw sky background
void summerDrawRuralHouse();   // Draw house
void summerDrawSmoke();        // Draw train smoke
```

### Animation Functions
```cpp
// Format: summerAnimate[ObjectName]() or summerMove[ObjectName]()
void summerAnimateAll();       // Master animation controller
void summerMoveTrain();        // Update train position
void summerMoveCar();          // Update car position
void summerAnimateClouds();    // Update cloud positions
void summerAnimateTrees();     // Update tree sway angle
void summerAnimateRiver();     // Update river wave phase
void summerAnimateSmoke();     // Update smoke effect
```

### Interaction Functions
```cpp
// Format: summerHandle[InputType]()
void summerHandleMouseClick(int button, int state, int x, int y);
void summerHandleKeyboard(unsigned char key, int x, int y);
void summerHandleSpecialKeys(int key, int x, int y);
```

### Utility/Helper Functions
```cpp
// Format: summer[Action]() or summer[Calculation]()
void summerResetAll();         // Reset scene to initial state
void summerToggleAnimations(); // Start/stop all animations
float summerCalculateDistance(float x1, float y1, float x2, float y2);
```

---

## 🏗️ Code Organization Structure

### Recommended File Organization

```cpp
// ============ WINDOW & COMMON SETUP ============
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
// ... (common for all scenes)

// ============ SCENE 1 - SUMMER VARIABLES ============
// Position variables
float summerTrainX = 5.0f;
float summerCarX = 30.0f;
// ... (all position variables)

// Movement variables
float summerTrainSpeed = 0.15f;
// ... (all speed variables)

// State variables
bool summerTrainMoving = false;
// ... (all boolean flags)

// ============ SCENE 1 - DRAWING FUNCTIONS ============
void summerDrawTrack() { }
void summerDrawSun() { }
void summerDrawClouds() { }
// ... (all drawing functions)

// ============ SCENE 1 - ANIMATION FUNCTIONS ============
void summerMoveTrain() { }
void summerMoveCar() { }
// ... (all animation functions)

// ============ SCENE 1 - INTERACTION FUNCTIONS ============
void summerHandleMouseClick() { }
void summerHandleKeyboard() { }
// ... (all interaction functions)

// ============ MAIN DISPLAY & TIMER ============
void display() { }
void timer() { }

// ============ MAIN FUNCTION ============
int main() { }
```

---

## ⚠️ What NOT to Do

### ❌ Wrong Naming Examples

```cpp
// Bad: No scene prefix
void drawSun() { }              // Will conflict!
void moveTrain() { }            // Will conflict!
float trainX = 0;               // Will conflict!

// Bad: Inconsistent prefix
void summerDrawSun() { }        // ✅ Good
void draw_sun() { }             // ❌ Inconsistent
void SummerDrawSun() { }        // ❌ Wrong case
void drawSummer_Sun() { }       // ❌ Wrong order

// Bad: Too short or unclear
void draw() { }                 // What does this draw?
void anim() { }                 // What animates?
float x = 0;                    // Which object's X?

// Bad: Modifying common code without prefix
const float TRAIN_TRACK_Y = 17.0f;  // ✅ Common (don't change)
float trainTrackY = 17.0f;          // ❌ Wrong - creates duplicate
```

### ✅ Correct Naming Examples

```cpp
// Good: Consistent prefixes
void summerDrawSun() { }        // Clear: Draw sun for summer
void summerMoveTrain() { }      // Clear: Move train in summer
float summerTrainX = 0;         // Clear: Train X in summer
float summerCloudSpeed = 0.05f; // Clear: Speed of summer clouds

// Good: Clear object references
void summerDrawTree1() { }      // Specific tree
void summerDrawTree2() { }      // Another tree
void summerDrawCloud(float x) { } // Parameterized function

// Good: Descriptive boolean names
bool summerTrainMoving = false;       // Is train moving?
bool summerAnimationsRunning = true;  // Are animations on?
bool summerSmokeVisible = true;       // Is smoke visible?
```

---

## 📊 Quick Reference Table

| Category | Pattern | Example |
|----------|---------|---------|
| Variable (Position) | `summer[Object][Direction]` | `summerTrainX`, `summerSunY` |
| Variable (Speed) | `summer[Object]Speed` | `summerCarSpeed` |
| Variable (Angle) | `summer[Object]Angle` | `summerTreeSwayAngle` |
| Variable (Boolean) | `summer[Object/Action][State]` | `summerTrainMoving` |
| Function (Draw) | `summerDraw[Object]` | `summerDrawTrain()` |
| Function (Animate) | `summerAnimate[Object]` | `summerAnimateClouds()` |
| Function (Move) | `summerMove[Object]` | `summerMoveTrain()` |
| Function (Handle Input) | `summerHandle[InputType]` | `summerHandleKeyboard()` |

---

## 🔄 Before Every Commit

Use this checklist to ensure your code follows guidelines:

```
☐ All new variables start with "summer"
☐ All new functions start with "summer"
☐ Variable names clearly indicate what they represent
☐ No functions have same name as common/shared functions
☐ Boolean variables clearly indicate their state
☐ Code is organized by category (Drawing, Animation, Interaction)
☐ No modifications to common window settings
☐ No modifications to common track setup
```

---

## 🚨 Conflict Prevention Checklist

**Before adding a new function or variable:**

1. ✅ Search existing code for similar names
   ```bash
   grep -n "summerTrain" summer_scene.cpp
   ```

2. ✅ Check if name is descriptive enough
   - ❌ `float x = 0;` → ✅ `float summerTrainX = 0;`

3. ✅ Verify it has the scene prefix
   - ❌ `void drawTrain()` → ✅ `void summerDrawTrain()`

4. ✅ Commit message mentions what you changed
   ```
   git commit -m "Add tree sway animation to summer scene"
   ```

---

## 📚 Examples from Code

### Variable Declaration Block
```cpp
// Position & Movement
float summerTrainX = 5.0f;
float summerTrainSpeed = 0.15f;
bool summerTrainMoving = false;

// Descriptive constants
const float SUMMER_TRAIN_MIN_X = 5.0f;
const float SUMMER_TRAIN_MAX_X = 75.0f;
```

### Drawing Function
```cpp
void summerDrawTrain()
{
    // Train body
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(summerTrainX, TRAIN_TRACK_Y);
    // ... more vertices
    glEnd();
    
    // Train cabin/engine
    glColor3f(0.6f, 0.05f, 0.05f);
    // ... cabin drawing
}
```

### Animation Function
```cpp
void summerMoveTrain()
{
    if (summerTrainMoving) {
        summerTrainX += summerTrainSpeed;
        
        if (summerTrainX > SUMMER_TRAIN_MAX_X) {
            summerTrainX = SUMMER_TRAIN_MIN_X;
        }
    }
}
```

---

## ✨ Pro Tips

1. **Use CamelCase** for multi-word names
   - `summerTreeSwaySpeed` ✅ not `summer_tree_sway_speed`

2. **Put the object name first**
   - `summerTrainSpeed` ✅ not `speedSummerTrain`

3. **Use numbers for multiple instances**
   - `summerTree1`, `summerTree2`, `summerTree3` ✅

4. **Be consistent in capitalization**
   - Always use CamelCase like: `summerDrawTrain()`

5. **Keep names readable but concise**
   - `summerTreeSwayAngle` ✅ (clear)
   - `sTA` ❌ (too short)
   - `summerTreeSwayAnimationAngleVariable` ❌ (too long)

---

**Follow these guidelines and merging will be painless! 🎉**


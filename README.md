#                   Toby the Meowstronaut

> *"Space is hard when you're a cat... but someone's gotta fly."*  

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![Raylib](https://img.shields.io/badge/Raylib-000000?style=flat&logo=raylib&logoColor=white)
![Emscripten](https://img.shields.io/badge/WebAssembly-654FF0?style=flat&logo=webassembly&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-000000?style=flat&logo=jetbrains&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Development-yellow)
![License](https://img.shields.io/badge/License-MIT-green)

---

##  Play Now
 **[Click here to play Toby the Meowstronaut](https://zianbytes.github.io/ZB-GAMES/)** — instant browser play, no downloads needed!  
*(Only browser friendly)*

---

##  Game Summary
**Toby the Meowstronaut** is a retro-pixel side-scroller where you guide Toby, a fearless (and slightly snack-obsessed) feline astronaut, through dangerous space pillars to rack up high scores and survive as long as possible.  

- **Genre:** Side-scroller / Survival  
- **Engine:** C++20 with [Raylib](https://www.raylib.com/)  
- **Core Mechanic:** Dodge incoming obstacles while enjoying a spacey soundtrack  
- **Status:** Web + mobile-ready roadmap in active development  

---

##  Features
-  Home screen with space-themed UI & floating glow text  
-  Pause/Resume system (`P` to pause, `Space` to resume)  
-  Real-time score & timer  
-  Game Over screen with Restart (`R`) / Exit (`E`)  
-  Dynamic, gradient-shaded obstacles  
-  Smooth player animation (2-frame sprite + vertical movement)  
-  Pixel-perfect collision detection  
-  Full audio immersion — lobby music, engine hums, button clicks, collision SFX  
-  Raylib → WebAssembly compilation for browser play  

---

## 📂 Project Structure
```
TobyTheMeowstronaut/
├── assets/                 # Sprites, music, sound effects
│   ├── sprites/            # Player, spaceship, obstacles, treats
│   ├── backgrounds/        # Space/parallax backgrounds
│   └── audio/              # Music & sound effects
│
├── src/                    # Game source files
│   ├── main.cpp
│   ├── game.cpp / game.h
│   ├── player.cpp / player.h
│   ├── obstacle.cpp / obstacle.h
│
├── raylib_web/              # WebAssembly Raylib build files
├── index.html               # Web export entry point
├── CMakeLists.txt           # CMake build configuration
└── README.md                # This file
```

---

##  Development Journey
Toby began as a 100×100 pixel spaceship sprite drawn in **Pixilart**. From there:
1. Built a **game loop** from scratch in CLion  
2. Created modular classes: `Game`, `Player`, `Obstacle`  
3. Implemented sprite animation and custom obstacle rendering  
4. Added **keyboard input handling** for precise controls  
5. Layered in music & SFX for full immersion  
6. Compiled to **WebAssembly** with Emscripten for browser play  

---

##  Roadmap
-  Player login & passcode  
-  Online leaderboard  
-  Mobile version (iOS & Android)  
-  AI-mode Toby (machine-learning auto-play)  

---

##  Links
- **Play Now:** [zianbytes.github.io/ZB-GAMES](https://zianbytes.github.io/ZB-GAMES/)  
- **GitHub:** [github.com/zianBytes/TobyTheMeowstronaut](https://github.com/zianBytes/TobyTheMeowstronaut)  

---

##  Credits
- **Developer:** Mohammed Zian Vhuyya  
- **Character Inspiration:** Toby (real cat, part-time astronaut)  
- **Art & Assets:** Hand crafted in Pixilart ( Did it on my macbook, I'm too broke for an Ipad :( ) 
- **Music/SFX:** Curated royalty-free tracks  

---

##  Special Thanks
Toby for being the eternal muse,  
to everyone who playtested early builds,  
and to ChatGPT for enduring endless commits, bugs, and cosmic chaos.( YES I VIBECODED THIS NOW SYBAU).

---




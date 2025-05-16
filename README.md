### 🎯 RayTracer – B-OOP-400

  A modular raytracer written in C++ for the Epitech B-OOP-400 curriculum.
  Renders 3D scenes with primitives, lights, shadows and config-based setup.

---

## ✨ Features

- ✅ Sphere and plane primitive support
- ✅ Translated objects (`TranslatedPrimitive`)
- ✅ Ray-object intersection
- ✅ Customizable camera (position, FOV, orientation)
- ✅ Lighting:
  - Ambient
  - Directional
  - Point
- ✅ Shadow projection via shadow rays
- ✅ Scene configuration via `.cfg` (libconfig++)
- ✅ Outputs `.ppm` files (convertible to `.png`)
- ✅ Several example scenes provided

---

## 🛠️ Build Instructions

### ✅ Requirements

- `g++` with C++17 support
- `make`
- `libconfig++` (install via `sudo apt install libconfig++-dev`)
- [ImageMagick](https://imagemagick.org/) (for converting `.ppm` to `.png`)

### 🔧 To build:

```bash
make
```
This compiles the raytracer binary in the project root.

### 🚀 Usage
📂 Render a scene
```bash
./raytracer scenes/example.cfg
```
Creates:
lua
output.ppm

### 🖼️ Convert to PNG
```bash
convert output.ppm output.png
```
📁 Scene File Format (.cfg)
- Scene files use libconfig++ syntax and are located in the scenes/ folder.

🧩 Supports
- ✅ Custom camera (position, orientation, FOV)

- ✅ Multiple spheres and planes

- ✅ Ambient, directional and point lights


### 🖼️ Output Examples
Render the scenes and convert using convert output.ppm output.png

- 🌪 Spiral Scene

- 🧱 Gallery Scene

- 🌑 Shadow Test

- 🎯 Exact Match


### 💡 Contribute & Suggest
Got an idea? Found a bug? Want to add something cool?

- 💬 Open an issue

- 🚀 Submit a pull request

- 🖌️ Share your creative .cfg scenes

All contributions are welcome.

## ⚠️ Be Careful – Epitech Students

This project was created for the **B-OOP-400** module.  
If you're an Epitech student:

> ❗ **Do not copy this project as-is.**  
> ❌ Submitting this directly may result in a **-42** for plagiarism.

Use it to **learn, get inspired, and build your own version.**  
Always respect your school’s academic integrity policy.

# 📚 License
This project was created for the 2024–2025 Epitech B-OOP-400 module.

Feel free to explore, learn from, and expand upon it.


---






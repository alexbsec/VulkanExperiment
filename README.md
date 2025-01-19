# VulkanExperiment

This is a simple Vulkan engine following Vulkan tutorials. The project aims to provide a basic engine implementation and serves as a learning resource for Vulkan.

## Prerequisites

Before compiling, ensure you have the following installed:
- A C++23-compatible compiler (e.g., GCC, Clang, or MSVC).
- CMake (version 3.10 or higher).
- Vulkan SDK installed and configured on your system.

## Dependencies

This project depends on GLM and Vulkan.

### Installing GLM

To install GLM, follow these steps

#### Arch Linux

```bash
sudo pacman -S glm
```

#### Ubuntu/Debian

```bash
sudo apt-get install libglm-dev
```

#### Fedora/RHEL

```bash
sudo dnf install glm-devel
```

#### MacOS

```bash
brew install glm
```

#### Windows

You can download GLM from its GitHub repository:

1. Visit GLM GitHub Repository.
2. Download the latest release.
3. Add the glm directory to your project's include path.

#### Using `vcpkg`

If you're using `vcpkg` as your package manager, you can install using

```bash
vcpkg install glm
```

### Installing Vulkan

To install Vulkan, please follow Vulkan's [tutorial](https://vulkan-tutorial.com/Development_environment) page

## Building

To build the project, you must first create the build directory:

```bash
mkdir build && cd build
```

Then, you run 

```bash
cmake .. && cd ..
```

Back on the root directory, if you are using NeoVim with clangd as your LSP,
you must run the following command to enable C++23 syntax support:

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
```

This will create a file called `compile_commands.json` inside the build directory.
After that, if the symbolic link is not working, remove the current one and run
the following command in the root directory of the project:

```bash
ln -s build/compile_commands.json compile_commands.json
```

Finally, to build, simply run:

```bash
cmake --build build
```

### Compiling shaders

#### On Unix systems
To compile shaders on Unix systems, use `compile.sh` file. First, find your
`glslc` executable path. Then, change the alias in the `compile.sh` to the 
path to `glslc` executable. Example:

```bash
alias glslc=/path/to/glslc
```

#### On Windows

To compile shaders on Windows, modify the `compile.bat` script as follows:

1. Locate the path to your `glslc.exe` file.
2. Update the line in the script to reflect the correct path to `glslc.exe`. Replace:

```bat
set GLSLC="C:\path\to\glslc.exe"
```

with your actual `glslc.exe` location.

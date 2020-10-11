# Opengl Example (FreeGLUT)

## Requirement
[freeglut](http://freeglut.sourceforge.net/) applications with MinGW and MSVC.
[Visual Studio](https://visualstudio.microsoft.com/pt-br/)

## Building

First: "Include Directories" and "Library Directories"
settings under "VC++ Directories", and the "Environment" setting under "Debugging" may need to be updated if your GLUT
header files, import libraries, and DLLs are in a different location. Secondly, the "Additional Dependencies" under
"Linker" -> "Input" may need to be changed if you're not using freeglut. For example, if you're using GLUT for Win32,
change "freeglut.lib" to "glut32.lib".

# VTKSphereWidget

A Qt + VTK-based GUI application that visualizes and dynamically deforms a 3D sphere using random parameters.
This application is based on an example of Qt + VTK published on https://examples.vtk.org/site/Cxx/Qt/MinimalQtVTKApp/.
The official example lacks any formal structure, i.e. it is _Spaghetti Code_ or _monolithic_,
therefore, is not practical.

_VTKSphereWidget_ is designed using a well-established architecture, commonly used for Qt (C++),
namely, Model-View-Controller (MVC). It provides a template for some of the most essential components of 
a Qt+VTK widget including _VTK sources, VTK rendered window, Qt Layout, Qt Widget and window_. The list is
non-exhaustive, yet lays the ground for adding features and sources on demand.

This project includes standard tests based on GoogleTest. The tests are only examples 
and mainly concern constructors and initializations.


## ✨ Features

- Randomized sphere deformation with VTK
- Qt-based GUI with interactive controls
- Real-time rendering using QVTKOpenGLNativeWidget

## 🚀 Getting Started

### Prerequisites

- CMake >= 3.16
- Qt >= 6.9.0 (with Widgets)
- VTK >= 9.4.2
- C++17 compatible compiler

### Installation

```bash
git clone https://github.com/yourusername/VTKSphereWidgetProject.git
cd VTKSphereWidgetProject
mkdir build && cd build
cmake ..
make

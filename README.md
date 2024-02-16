# 3D Rotating Cube Simulation

This project is a simple yet fascinating demonstration of a 3D rotating cube simulation running in the terminal. It utilizes ASCII characters to visually represent the rotation of a cube in three dimensions. This simulation is achieved through the manipulation of sin and cos functions alongside a basic z-buffer for rendering.

## Features

- Real-time 3D cube rotation within the terminal.
- ASCII character-based visualization.
- Adjustable parameters for rotation speed and cube size.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Terminal or command prompt

### Installation

1. Clone the repository to your local machine:
   git clone https://github.com/IlanVinogard/Cube3D.git

3. Navigate to the project directory:
   cd Cube3D

5. Compile the project using your C++ compiler. For example, with g++:
   g++ -o cubeSimulation main.cpp -std=c++11



### Usage

To run the simulation, execute the compiled program:
./cubeSimulation


The simulation will start running in your terminal. You can adjust the cube's rotation speed and size by modifying the `velocity` and `cubeSize` variables in the code.

## Screenshot

![3D Rotating Cube Simulation](https://github.com/IlanVinogard/Cube3D/blob/master/cube.png)

## Contributing

We welcome contributions to this project! If you have suggestions for improvements or encounter any issues, please feel free to open an issue or submit a pull request.

### Steps to Contribute

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/AmazingFeature`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
5. Push to the branch (`git push origin feature/AmazingFeature`).
6. Open a pull request.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Acknowledgments

- Special thanks to everyone who has contributed to this project.
- Inspired by traditional ASCII art and 3D computer graphics.

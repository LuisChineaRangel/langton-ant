<br />
<p align="center">
  <h3 align="center">Langton's Ant</h3>

  <p align="center">
    <br />
    <a href="https://github.com/iluzioDev/langton-ant"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/iluzioDev/langton-ant">View Demo</a>
    ·
    <a href="https://github.com/iluzioDev/langton-ant/issues">Report Bug</a>
    ·
    <a href="https://github.com/iluzioDev/langton-ant/issues">Request Feature</a>
  </p>
</p>

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#written-in">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#download-and-installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#bugs">Usage</a></li>
    <li><a href="#references">References</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About the Project

C++ implementation of Langton's Ant Turing Machine:

*Squares on a plane are colored variously either black or white. We arbitrarily identify one square as the "ant". The ant can travel in any of the four cardinal directions at each step it takes. The "ant" moves according to the rules below.*

- *At a white square, turn 90° clockwise, flip the color of the square, move forward one unit*
- *At a black square, turn 90° counter-clockwise, flip the color of the square, move forward one unit*

### Written In

* [C++](https://www.cplusplus.com/)

## Getting Started

### Download and Installation

Latest release can be found at [here](https://github.com/iluzioDev/langton-ant/releases) as source code.

1. Download latest release
2. Compile
   ```sh
   make
   ```
3. Create your Project Structure
   ```sh
   make project
   ```
4. Execute
   ```sh
   make run
   ```

## Usage

Once launched, the user will be prompted to input the dimensions (rows and columns) of a MxN Grid.

The program will introduce a Langton's Ant at the center of the grid, in order to move it with the defined behavior until the user exits by pressing *enter*.

## Bugs

Please report all bugs [here](https://github.com/iluzioDev/langton-ant/issues). If appropriate, please attach a small test volume which you think Langton's Ant isn't handling correctly.

## References

[Langton's Ant | Wikipedia](https://en.wikipedia.org/wiki/Langton%27s_ant)

## License

This program is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

## Contact

Luis Marcelo Chinea Rangel - [@luismchr_](https://twitter.com/luismchr_) - luismarcelochinearangel@gmail.com

Project Link: [https://github.com/iluzioDev/langton-ant](https://github.com/iluzioDev/langton-ant)
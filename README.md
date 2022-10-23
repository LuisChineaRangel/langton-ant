# Langton's Ant

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Twitter](https://img.shields.io/twitter/follow/luctstt.svg?label=Follow&style=social)](https://twitter.com/iluzioDev)

---

https://user-images.githubusercontent.com/45295283/197367303-6d8bdd8f-50ec-436d-9a3e-30e88560c219.mp4

## Introduction 📋

Langton's ant is a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior. It was invented by Chris Langton in 1986.

Squares on a plane are colored variously either black or white. We arbitrarily identify one square as the "ant". The ant can travel in any of the four cardinal directions at each step it takes. The "ant" moves according to the rules below.

- At a white square, turn 90° clockwise, flip the color of the square, move forward one unit.
- At a black square, turn 90° counter-clockwise, flip the color of the square, move forward one unit.

## Features ✨

* Use of Multithreading for better performance.
* Support for Windows and UNIX.
* Compatibility whith UTF-8.

## Install 🔧

```
git clone https://github.com/iluzioDev/langton-ant
cd langton-ant
make
```

## Usage 💡

Given a board size (via User Input), the program will indefinitely execute the movements of a Langton's ant introduced in the center of the grid. Users can cancel the study at any time.

## Maintainers 👷

<table>
  <tr>
    <td align="center"><a href="https://github.com/iluzioDev"><img src="https://avatars.githubusercontent.com/u/45295283?v=4" width="100px;" alt="IluzioDev"/><br /><sub><b>IluzioDev</b></sub></a><br />💻</td>
  </tr>
</table>

## License ⚖️

Distributed under the MIT License. [Click here](LICENSE.md) for more information.

---
<div align="center">
	<b>
		<a href="https://www.npmjs.com/package/get-good-readme">File generated with get-good-readme module</a>
	</b>
</div>

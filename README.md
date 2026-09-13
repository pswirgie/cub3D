*This project has been created as part of the 42 curriculum by pswirgie, nbaudoin.*
<p id="top"></p>

<br>
<div align="center">

# Cub3D
</div>

- [Cub3D](#cub3d)
	- [1. Description](#1-description)
	- [2. Instructions](#2-instructions)
	- [3. Resources](#3-resources)

<br><br>

## 1. Description

Cub3D is a graphics programming project that introduces raycasting techniques, inspired by the rendering engine used in the original *Wolfenstein 3D*. The goal is to build a simple 3D maze game from a 2D map, using ray casting to render walls, textures, and perspective in real time.

[back to top](#top)

<br>

## 2. Instructions

1. Clone the repository: `git clone [url]`
2. Move into the project directory: `cd [directory_name]`
3. Build the project: run `make`
4. Run the program with a map file: `./cub3D [path_to_map/name_map.cub]`

[back to top](#top)

<br>

## 3. Resources

**Raycasting:**
- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [DDA Line Generation Algorithm – GeeksforGeeks](https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/)
- [Raycasting – ESIEE Paris](https://perso.esiee.fr/~buzerl/sphinx_IMA/80%20raycast/raycast.html)

**AI assistance was used for:**
- Researching raycasting algorithms and understanding wall orientation logic
- Correcting English grammar in code comments and in this README
- Auditing the code and guiding robustness fixes, plus one recursive-to-iterative flood-fill refactor and dead-code cleanup
- Running a test pass (norminette, valgrind, edge-case maps)

Every change was reviewed, understood, applied by hand, and peer-checked before being committed.

[back to top](#top)

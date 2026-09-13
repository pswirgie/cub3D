*This project has been created as part of the 42 curriculum by pswirgie, nbaudoin.*
<p id="top"></p>

<!-- new lines -->
<br>
<div align="center">

# Cub3D
</div>

- [Cub3D](#cub3d)
	- [1. Description](#1-description)
	- [2. Instructions](#2-instructions)
	- [3. Ressources](#3-ressources)

<!-- new lines -->
<br><br>

## 1. Description

Cub3D is a graphics programming project that introduces raycasting techniques, inspired by the rendering engine used in the original *Wolfenstein 3D*. The goal is to build a simple 3D maze game from a 2D map, using ray casting to render walls, textures, and perspective in real time.

[back to top](#top)
<!-- new lines -->
<br>

## 2. Instructions

1. Clone the repository: `git clone [url]`
2. Move into the project directory: `cd [directory_name]`
3. Build the project: tap `make` and press Enter
4. Run the program with a map file: tap `./cub3d [path_map/name_map.cub]` and press Enter

[back to top](#top)
<!-- new lines -->
<br>

## 3. Ressources

**Raycasting:**
- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [DDA Line Generation Algorithm – GeeksforGeeks](https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/)
- [Raycasting – ESIEE Paris](https://perso.esiee.fr/~buzerl/sphinx_IMA/80%20raycast/raycast.html)

**AI assistance was used for:**
- Correcting English grammar in code comments
- Researching raycasting algorithms and solutions
- Understanding wall direction/orientation logic
- Implementing texture rendering
- Correct README
- Auditing the code and guiding robustness fixes also
  	one recursive to iterative flood-fill factor and cleanup;
- A test pass (norminette, valgrind, edge-case maps).

Every change was reviewed, understood, applied by hand, and peer-checked before commit.

[back to top](#top)

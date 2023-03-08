## Advanced R-TYPE

<img src="https://i.postimg.cc/W4yMwhgc/500px-R-Type-Logo.png" alt="alt text">

<a name="readme-top"></a>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#specificities">Specificities</a></li>
        <li><a href="#technologies-used">Technologies Used</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation-linux">Installation (Linux)</a></li>
        <li><a href="#prerequisites-windows">Prerequisites (Windows)</a></li>
        <li><a href="#installation-windows">Installation (Windows)</a></li>
      </ul>
      <a href="#other-information">Other Information</a>
      <ul>
        <li><a href="#game-controls">Game Controls</a></li>
        <li><a href="#authors">Authors</a></li>
      </ul>
    </li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

The goal of this project is to implement our own version of the game R-Type but with a twist: 
this version is a network game featuring one-to-four players whose goal is to fight together
against a wave of enemies!

For more information on this game, refer to http://www.hardcoregaming101.net/r-type/.

Dev Documentations: https://epitech-9.gitbook.io/r-type/r-type/r-type

Network Documentations: https://docs.google.com/document/d/13TY6sqcqzN5Dmy5ObR_jOVzKZVRteO7p3xVBY8bpffM/edit?usp=sharing

### Specificities

- This project is cross-platform and can run on both Windows and Linux.
- This project has its own implementation of a Game Engine using the Entity-Component-System (ECS) architectural pattern with SDL2

[![Classe-UML-1.png](https://i.postimg.cc/6qqrp0LR/Classe-UML-1.png)](https://postimg.cc/jnVw8y1d)

### Technologies Used

- C++
- SDL2
- Asio

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

For a more in-depth use of this project, refer to the documentation.

## Linux

### Installation (Linux)

1. Clone the repo
   ```sh
   git clone https://github.com/EpitechPromo2025/B-CPP-500-MPL-5-1-rtype-hugo.marrasse.git
   ```
2. Install and setup project
   ```sh
   ./install.sh build
   ```
3. Launch Server
   ```sh
   ./r-type_server
   ```
3. Launch Client
   ```sh
   ./r-type_client
   ```
## Windows

### Prerequisites (Windows)

* Visual Studio
   
### Installation (Windows)

1. Download the repository

2. Install and setup the project
- Use the install.ps1 file in Visual Studio

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Other Information

### Game Controls

**Player**

 Button        | Direction
 --------------|-------------
 Arrow Up      | Top
 Arrow Down    | Down
 Arrow Left    | Left
 Arrow Right   | Right
 Space         | Shoot
 
 ### Authors
 
 * Maya Hill
 * Hugo Nini
 * Bastien Boymond
 * Hugo Marrassé
 * Diogo Faria-Martins
 
 <p align="right">(<a href="#readme-top">back to top</a>)</p>
 


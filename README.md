# Console-game

## Video

[![vlcsnap-2019-02-10-10h23m41s399](https://user-images.githubusercontent.com/8284699/52531979-094fbc00-2d1e-11e9-9444-84bef0a8df6b.png)](https://drive.google.com/open?id=1yP540PzOtkcgXA2jWglmGom61g3GFsaf)

## About project
This is a small ASCII console game developed in C++ using MS visual studio 2017. The entire concept is from 3D buzz.... I however build my own algorithms to have a similar game from ground up. The whole concept has been an experiment! and hopefully it runs very well on your machine!

The project consists of a Level, draw engine, player, enemy, and fireball classes that are inter-related and interact with each other.

The level comprises of the game play environment and is controlled by the level class. The level class uses the draw engine to draw to the console the ASCII characters (the play environment, the player and the enemies, and the bullets characters from the player to kill the enemy).

A simple AI function is created in the enemy class to track the player's position and move towards him. The AI also randomly can help the enemy to avoid the bullets fired from the player.

The player(in the character class) gets input from the keyboard (W, A, S, D) to move in the respective direction. The goal of the player is to run from the enemy as fast as he can. If he also has a perfect chance, he can shoot and kill the enemy.

Hope you enjoy testing out the project!

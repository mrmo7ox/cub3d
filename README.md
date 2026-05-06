# cub3d

my own 3d game engine built in c using raycasting for the 1337 curriculum.

## the story
this project is where things got really crazy. going from printing text in a terminal to actually rendering a 3d world pixel by pixel was a huge jump. i had to dive deep into the math behind raycasting, figuring out how to shoot rays from the player's field of view and calculate distances to the walls so they look 3d. half the struggle was just parsing the `.cub` configuration files and making sure the map is fully closed with no leaks.

## the goal
the main objective was to make a wolfenstein 3d style engine. it starts by parsing the map file to extract floor/ceiling colors and the paths to the wall textures. then the execution part takes over, handling the player's movement and keyboard hooks. i had to implement the math to cast rays, map the `.xpm` textures onto the walls, and render everything smoothly. i even threw in a garbage collector to make sure all the memory allocated during parsing gets cleaned up properly.

## the lesson
i learned so much about graphics programming and optimization. pushing pixels to an image buffer instead of drawing straight to the window was a game-changer for performance. handling the trignometry for the player's rotation and applying textures based on exactly where the ray hit the wall melted my brain a few times, but getting that first 3d room to render correctly was incredible.

## how to use
to play around with it, just open the terminal and run `make` to compile the executable. then run the program and pass it a map file, like `./cub3d maps/hi.cub`. the window will pop up and you can walk around the maze using the keyboard.

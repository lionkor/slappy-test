# Asteroids

### Project description:
The player is a little rocket ship. He can fire bullets.

The player is either
* restricted to the screen space area, or
* gets teleported to the other side if he goes out of bounds.

Astroids spawn randomly at the edge of the screen and move around.

Enemies spawn occasionally at the edge and go towards the player.

Both asteroids and enemies can be shot.

### S4kyt says: General idea regarding implementation aimed towards Player,Skybox, and collision.
  * Player: can be drawn with vectors, consisting out of 4 points which if we connect correctly we get our rocket ship from the original game. Something to note regarding player: lets say we have player's points (ones we wanna connect to get player complete), lets name those points from A-D, that leaves us with smth like:
    * pModel_A, pModel_B, pModel_C, p_Model_D (pModel being playerModel and A-D being the 4 "corners" for player. Since player model is perfectly mirrorable, we could also: A and C can be each other's inverses, so maybe we can make it that much simpler somehow? Still trying to figure out how.
  * "Skybox" (Player limit:
    * Player needs collision which we'll have by implementing a new property to player called pModel_Collision of boolean type, having collision always on of course with a while loop in dear player (or maybe somewhere else, but im pretty sure it has to be a loop, maybe in update?).
    * Skybox also needs collision which I would solve with adding the 4 corners (4 corners somehow have to be position according to the window's resolution size of course), making them connect the same way we did with player, vectors, etc. We could name the corners the same way like player so its clean and easy to understand, from left to right, and from top to bottom. A-B-C-D Something to note here: We could also solve this by using A and its inverse called A' for naming convention and B with B'. This way we'd reduce the amount of weird variables by 2, making it that much simpler and easy to read. I hope.

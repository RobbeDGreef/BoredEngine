# BoredEngine
The bored engine is a very simple and light 2D game engine. It is a personal
learning project and that is obviously where it got its name from. 
The engine does not house a lot of features right now and a lot of stuff will
change in the future.

You are welcome to help contribute to this project and help this engine grow


## Creating a game with BoredEngine
First you will need a project file structure so to create this run the 
cli python file:

`python3 cli/BoredEngine --create-project <yourprojectnamehere> <yourprojectpathhere>`

Then `cd` into your fresh project and start creating an awesome game!
If you want to compile your masterpiece just use the CLI again:

`python3 cli/BoredEngine --build <yourprojectpathhere>`

Don't try to build the project yourself (without the CLI) it will most likely
just become a mess.

## The engine

### Currently this engine has
- Component based gameobject system
- Actor system
- Background support
- Sprites
- Bind based event system
- Configurable through config header files
- Basic level class system
- CLI based control, create project, building project

### What is going to be added
Well a lot... but in the near future 
- Multiple layer background system to create depth off feel when the player moves
- Redo of the event system and making the event configurable 
  like for example the Unreal Engine event system
- Collision detection
- Physics engine
- GUI system
- Networking (I like implementing network stuff so this might come sooner 
  then you might expect)
- Player controller class, this class will poses actors and that way 
  characters become easier to implement
- And offcourse last but not least, a GUI for the engine

## How do I start my own engine project?
The internet is your friend, the layer based implementation this engine
uses commes from [the Hazel Engine](https://github.com/TheCherno/Hazel) written by Yan Chernikov
who has tutorials on the subject of game engines on [youtube](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT).

I created some small stupid games in Unreal Engine a couple of years ago
so, while I am used to the way they implemented their engine and you will
definitely find similarities between the two, it isn't a copy of their engine.

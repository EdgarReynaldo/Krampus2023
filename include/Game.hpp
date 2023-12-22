



#ifndef Game_HPP
#define Game_HPP


#include <vector>
#include <string>

class Allegro5System;
class Allegro5FileSystem;
class Allegro5DialogManager;
class Allegro5SoundManager;
class EagleGraphicsContext;
class Scene;

#include <hash_set>
#include <vector>

class Game {
protected :
   bool quit;

   bool redraw;


   std::vector<Scene*> screen_set;

   std::vector<Scene*> screen_vec;

public :
//   Game();
Game() :
      quit(false),
      redraw(true),
      screen_set(),
      screen_vec()
{
}

   bool Init(std::vector<std::string> args);
   void Run();


   bool Quit() {return quit;}



};



#endif // Game_HPP


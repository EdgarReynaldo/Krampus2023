



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

   Allegro5System* sys;

   EagleGraphicsContext* win;

   Allegro5FileSystem* fsys;

   Allegro5DialogManager* dman;

   Allegro5SoundManager* soundman;
   
   std::vector<Scene*> screen_set;
   
   std::vector<Scene*> screen_vec;
   
public :
//   Game();
Game() :
      quit(false),
      redraw(true),
      sys(0),
      win(0),
      fsys(0),
      dman(0),
      soundman(0),
      screen_set(),
      screen_vec()
{
}
   
   bool Init(std::vector<std::string> args);
   void Run();
   
   
   bool Quit() {return quit;}



};



#endif // Game_HPP


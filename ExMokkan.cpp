/**
My wishlist (just for ideas, no need to use all of them):

1. I like building, management games, and systems that interact with each other.
2. Science fiction
3. A game where violence isn't front-and-center.
4. Resource management / economy could be an interesting design pillar.
5. Exploration!

Mars Colony Alpha
Deus Ex Mokkanista


Mars images
Courtesy NASA/JPL-Caltech.

1001 free fonts
28 days later
ch nuclear war regular
christmas snow



*/

#include "Eagle.hpp"

#include "Eagle/backends/Allegro5Backend.hpp"

#include "ExMokkan.hpp"
Allegro5System* sys = 0;
Allegro5GraphicsContext* win = 0;
Allegro5FileSystem* fsys = 0;
Allegro5DialogManager* dman = 0;
Allegro5SoundManager* soundman = 0;


EagleFont* font = 0;
EagleFont* font_28days = 0;
EagleFont* font_nuclear = 0;
EagleFont* font_snow = 0;

int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;

#include "Game.hpp"



int main(int argc , char** argv) {

   std::vector<std::string> args;

   int i = 0;
   while (i < argc) {
      args.push_back(argv[i]);
      ++i;
   }
   sys = GetAllegro5System();

   int ret = sys->Initialize(EAGLE_FULL_SETUP);
   if (ret != EAGLE_FULL_SETUP) {
      EAGLE_ASSERT(ret & EAGLE_STANDARD_SETUP);
      EagleLog() << "Failed init states : " << std::endl;
      PrintFailedEagleInitStates(EAGLE_FULL_SETUP , ret);
   }
   SCREEN_WIDTH = 1920;
   SCREEN_HEIGHT = 1080;

   win = dynamic_cast<Allegro5GraphicsContext*>(sys->CreateGraphicsContext("A5 window" , 1920 , 1080 , EAGLE_FULLSCREEN , -1 , -1));
   EAGLE_ASSERT(win);

   fsys = dynamic_cast<Allegro5FileSystem*>(sys->GetFileSystem());

   dman = dynamic_cast<Allegro5DialogManager*>(sys->GetDialogManager());

   soundman = new Allegro5SoundManager();

   font = win->GetFont("Data/Fonts/Verdana.ttf" , -72);
   font_28days = win->GetFont("Data/Fonts/28DaysLater.ttf" , -108);
   font_nuclear = win->GetFont("Data/Fonts/CFNuclearWarRegular.ttf" , -108);
   font_snow  = win->GetFont("Data/Fonts/ChristmasSnow.ttf" , -232);


   bool quit = false;

   while (!quit) {
      Game game;
      if (!game.Init(args)) {return -1;}
      game.Run();
      quit = game.Quit();
   }

   delete soundman;
   soundman = 0;

   return 0;
}




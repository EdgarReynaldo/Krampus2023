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

#include "Game.hpp"



int main(int argc , char** argv) {

   std::vector<std::string> args;

   int i = 0;
   while (i < argc) {
      args.push_back(argv[i]);
      ++i;
   }
   
   bool quit = false;

   while (!quit) {
      Game game;
      if (!game.Init(args)) {return -1;}
      game.Run();
      quit = game.Quit();
   }

   return 0;
}




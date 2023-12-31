


#include "Game.hpp"
#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"


#include "Resources.hpp"
#include "Scene.hpp"
#include "Intro.hpp"
#include "Story.hpp"
#include "GameScene.hpp"
#include "ExMokkan.hpp"




Game::Game() :
      quit(false),
      redraw(true),
      screen_set(),
      current_scene(0)
{}



bool Game::Init(std::vector<std::string> args) {

   (void)args;

   win->Clear();
   win->FlipDisplay();

   screen_set.push_back(new Intro());
   screen_set.push_back(new Story());
   screen_set.push_back(new GameScene());
//   nextscene = screen_set[1];
//   screen_vec.push_back(screen_set[1]);
//   screen_vec.push_back(screen_set[2]);
   if ((screen_set[0]->Init() == SCENE_READY) &&
       (screen_set[1]->Init() == SCENE_READY) &&
       (screen_set[2]->Init() == SCENE_READY)) {
      screen_set[0]->nextscene = screen_set[1];
      screen_set[1]->nextscene = screen_set[2];
      current_scene = screen_set[0];
   }
   else {
      EagleError() << "Failed to initialize all screens." << std::endl;
   }

   return true;
}

void Game::Run() {

   sys->GetSystemTimer()->Start();

   while (!quit) {
      if (redraw) {
         win->Clear();
         if (current_scene) {
            current_scene->Display();
         }
         win->FlipDisplay();
         redraw = false;
      }
      do {
         EagleEvent e = sys->WaitForSystemEventAndUpdateState();
         if (e.type == EAGLE_EVENT_DISPLAY_CLOSE) {
            quit = true;
         }
         else if (e.type == EAGLE_EVENT_KEY_DOWN && e.keyboard.keycode == EAGLE_KEY_ESCAPE) {
            current_scene = current_scene->nextscene;
            if (!current_scene) {quit = true;}
            redraw = true;
         }
         else if (e.type == EAGLE_EVENT_TIMER) {
            if (current_scene) {
               int ret = current_scene->Update(e.timer.eagle_timer_source->SPT());
               if (ret == SCENE_COMPLETE) {
                  current_scene = current_scene->nextscene;
                  if (!current_scene) {quit = true;}
               }
            }
            redraw = true;
         }
         if (current_scene) {
            current_scene->HandleEvent(e);
         }
      } while (!sys->UpToDate());
   }
}








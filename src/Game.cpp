


#include "Game.hpp"
#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"


#include "Resources.hpp"
#include "Scene.hpp"
#include "ExMokkan.hpp"




Game::Game() :
      quit(false),
      redraw(true),
      screen_set(),
      screen_vec(),
      nextscene(0)
{}



bool Game::Init(std::vector<std::string> args) {

   (void)args;

   win->Clear();
   win->FlipDisplay();

   screen_set.push_back(new Intro());
   screen_set.push_back(new GameScene());
   screen_vec.push_back(screen_set[0]);
   nextscene = screen_set[1];
   if (screen_set[0]->Init() == SCENE_READY && screen_set[1]->Init() == SCENE_READY) {

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
         for (unsigned int i = 0 ; i < screen_vec.size() ; ++i) {
            screen_vec[i]->Display();
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
            if (screen_vec.empty()) {
               quit = true;
            }
            else {
               if (nextscene) {
                  screen_vec.back() = nextscene;
                  nextscene = 0;
               }
               else {
                  screen_vec.pop_back();
               }
               redraw = true;
            }
         }
         else if (e.type == EAGLE_EVENT_TIMER) {
            for (int i = screen_vec.size() - 1 ; i >= 0 ; --i) {
               if (screen_vec[i]->Update(e.timer.eagle_timer_source->SPT()) == SCENE_QUIT) {
                  if (nextscene) {
                     screen_vec[i] = nextscene;
                  }
                  else {
                     std::vector<Scene*>::iterator it = screen_vec.begin();
                     int j = i;
                     while (j--) {
                        ++it;
                     }
                     screen_vec.erase(it);
                  }
               }
            }
            redraw = true;
         }
         for (int i = screen_vec.size() - 1 ; i >= 0 ; --i) {
            if (screen_vec[i]->HandleEvent(e)) {
               break;
            }
         }
      } while (!sys->UpToDate());
   }
}








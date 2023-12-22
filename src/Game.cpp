


#include "Game.hpp"
#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"


#include "Resources.hpp"
#include "Scene.hpp"
#include "ExMokkan.hpp"




bool Game::Init(std::vector<std::string> args) {

   (void)args;

   win->Clear();
   win->FlipDisplay();

   screen_set.push_back(new Intro());
   screen_vec.push_back(screen_set[0]);
   screen_set[0]->Init();

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
            if (!screen_vec.empty()) {
               screen_vec.pop_back();
               redraw = true;
            }
            else {
               quit = true;
            }
         }
         else if (e.type == EAGLE_EVENT_TIMER) {
            for (int i = screen_vec.size() - 1 ; i >= 0 ; --i) {
               screen_vec[i]->Update(e.timer.eagle_timer_source->SPT());
            }
            redraw = true;
         }
         for (int i = screen_vec.size() - 1 ; i >= 0 ; --i) {
            screen_vec[i]->HandleEvent(e);
         }
      } while (!sys->UpToDate());
   }
}








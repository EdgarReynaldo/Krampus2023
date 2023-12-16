


#include "Game.hpp"
#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"


#include "Resources.hpp"
#include "Scene.hpp"





bool Game::Init(std::vector<std::string> args) {
   
   (void)args;
   
   
   sys = GetAllegro5System();
   EAGLE_ASSERT(sys);
   
   int sysret = sys->Initialize(EAGLE_FULL_SETUP);
   EAGLE_ASSERT(sysret & EAGLE_STANDARD_SETUP);
   
   fsys = GetAllegro5FileSystem();
   
   dman = dynamic_cast<Allegro5DialogManager*>(sys->GetDialogManager());
   
   Allegro5SoundManager sandman;
   soundman = &sandman;
   
   
   
   EagleGraphicsContext* win = sys->CreateGraphicsContext("Our Window" , 640 , 480 , EAGLE_OPENGL | EAGLE_WINDOWED);
   
   EAGLE_ASSERT(win && win->Valid());
   
   win->Clear();
   win->FlipDisplay();
   
   return true;
}

void Game::Run() {

   sys->GetSystemTimer()->Start();

   while (!quit) {
      if (redraw) {
         win->Clear();
         for (unsigned int i = 0 ; i < screen_vec.size() ; ++i) {
            screen_vec[i]->Display(win);
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








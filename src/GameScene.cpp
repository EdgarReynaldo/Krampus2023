



#include "GameScene.hpp"

#include "ExMokkan.hpp"
#include "Eagle/GraphicsContext.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"



int GameScene::Init() {
   grid.Resize(60 , 34 , 32.0);
   return SCENE_READY;
}



void GameScene::Display() {
   EAGLE_ASSERT(win);
   grid.DrawGrid(win , 0 , 0);
}



bool GameScene::HandleEvent(EagleEvent e) {
   (void)e;
   return false;
}


int GameScene::Update(double dt) {
   Scene::Update(dt);
   if (elapsed > 10.0) {
      return SCENE_QUIT;
   }
   return SCENE_RUNNING;
}




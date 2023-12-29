



#include "GameScene.hpp"

#include "ExMokkan.hpp"
#include "Eagle/GraphicsContext.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"



int GameScene::Init() {
   grid.Resize(32 , 18 , 60.0);
   return SCENE_READY;
}

//1920/60 = 32
//1080/60 = 18;

void GameScene::Display() {
   grid.DrawGrid(win , 0 , 0);
}



bool GameScene::HandleEvent(EagleEvent e) {
   (void)e;
   return false;
}


int GameScene::Update(double dt) {
   Scene::Update(dt);
   return SCENE_RUNNING;
}








#include "Scene.hpp"
#include "Eagle/GraphicsContext.hpp"
#include "Eagle/Font.hpp"
#include "ExMokkan.hpp"

#include "Eagle/backends/Allegro5Backend.hpp"


Scene::Scene() :
      elapsed(0.0)
{}



bool Scene::HandleEvent(EagleEvent e) {
   (void)e;
   return false;
}



int Scene::Update(double dt) {
   elapsed += dt;
   return SCENE_RUNNING;
}



///------------------     Intro     ----------------------



Intro::Intro() {}



int Intro::Init() {
   EAGLE_ASSERT(win);
   
   if (font && font_28days && font_nuclear && font_snow) {
      return SCENE_READY;
   }
   return SCENE_NOT_READY;
}



void Intro::Display() {
   EAGLE_ASSERT(win);
   int a = (elapsed>=5.0)?255:255*(elapsed/5.0);
   if (elapsed <= 10.0) {
      win->DrawTextString(font_28days , StringPrintF("MARS COLONY ALPHA") , 960 , 515 , EagleColor(255,64,64,a) , HALIGN_CENTER , VALIGN_BOTTOM);
      win->DrawTextString(font_nuclear , StringPrintF("DEUS EX MOKKANISTA") , 960 , 565 , EagleColor(192,32,32,a) , HALIGN_CENTER , VALIGN_TOP);
   }
   else if (elapsed <= 20.0) {
      win->DrawTextString(font_snow , StringPrintF("Krampus Hack") , 960 , 530 , EagleColor(255,255,255,255) , HALIGN_CENTER , VALIGN_BOTTOM);
      win->DrawTextString(font_snow , StringPrintF("2023") , 960 , 550 , EagleColor(255,255,255,255) , HALIGN_CENTER , VALIGN_TOP);
   }
}



int Intro::Update(double dt) {
   (void)Scene::Update(dt);
   if (elapsed > 20.0) {
      return SCENE_QUIT;
   }
   return SCENE_RUNNING;
}



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




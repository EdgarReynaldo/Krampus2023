



#include "Scene.hpp"
#include "Eagle/GraphicsContext.hpp"
#include "Eagle/Font.hpp"


Scene::Scene() :
      elapsed(0.0)
{}



bool Scene::HandleEvent(EagleEvent e) {
   (void)e;
   return false;
}



void Scene::Update(double dt) {
   elapsed += dt;
}



///------------------     Intro     ----------------------



Intro::Intro() :
      font(0)
{}



bool Intro::Init(EagleGraphicsContext* win) {
   font = win->GetFont("Data/Fonts/Verdana.ttf" , -72);

   return true;
}



void Intro::Display(EagleGraphicsContext* win) {
///   win->Clear();
   int a = 255*(elapsed/10.0);
   if (a > 255) {a = 255;}
   win->DrawTextString(font , StringPrintF("MARS COLONY ALPHA") , 960 , 515 , EagleColor(255,64,64,a) , HALIGN_CENTER , VALIGN_BOTTOM);
   win->DrawTextString(font , StringPrintF("DEUS EX MOKKANISTA") , 960 , 565 , EagleColor(192,32,32,a) , HALIGN_CENTER , VALIGN_TOP);
///   win->FlipDisplay();
}





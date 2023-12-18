



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
      font(0),
      font_28days(0),
      font_nuclear(0),
      font_snow(0)
{}



bool Intro::Init(EagleGraphicsContext* win) {
   font = win->GetFont("Data/Fonts/Verdana.ttf" , -72);
   font_28days = win->GetFont("Data/Fonts/28DaysLater.ttf" , -108);
   font_nuclear = win->GetFont("Data/Fonts/CFNuclearWarRegular.ttf" , -108);
   font_snow  = win->GetFont("Data/Fonts/ChristmasSnow.ttf" , -232);
   return true;
}



void Intro::Display(EagleGraphicsContext* win) {
   int a = (elapsed>=10)?255:255*(elapsed/10.0);
   if (elapsed <= 10.0) {
      win->DrawTextString(font_28days , StringPrintF("MARS COLONY ALPHA") , 960 , 515 , EagleColor(255,64,64,a) , HALIGN_CENTER , VALIGN_BOTTOM);
      win->DrawTextString(font_nuclear , StringPrintF("DEUS EX MOKKANISTA") , 960 , 565 , EagleColor(192,32,32,a) , HALIGN_CENTER , VALIGN_TOP);
   }
   else if (elapsed <= 20.0) {
      win->DrawTextString(font_snow , StringPrintF("Krampus Hack") , 960 , 510 , EagleColor(255,255,255,255) , HALIGN_CENTER , VALIGN_BOTTOM);
      win->DrawTextString(font_snow , StringPrintF("2023") , 960 , 570 , EagleColor(255,255,255,255) , HALIGN_CENTER , VALIGN_TOP);
   }
}





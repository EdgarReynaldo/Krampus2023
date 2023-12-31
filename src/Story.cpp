



#include "Story.hpp"
#include "ExMokkan.hpp"

#include "Eagle/Image.hpp"
#include "Eagle/GraphicsContext.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"



Story::Story() :
      Scene(),
      mars(0)
{
}



int Story::Init() {
   mars = win->LoadImageFromFile("Data/Images/Mars.jpg");
   if (mars && mars->Valid()) {
      return SCENE_READY;
   }
   return SCENE_NOT_READY;
}



void Story::Display() {
   win->Clear();
   double pct = elapsed>20.0?1.0:elapsed/20.0;
   Transform t = win->GetTransformer()->GetIdentityTransform();
   t.Translate(-mars->W()/2.0 , -mars->H()/2.0);
   t.Scale(pct , pct);
   t.Translate(mars->W()/2.0 , mars->H()/2.0);
   win->PushViewTransform(t);
   win->DrawImageCenter(mars , Rectangle(0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT));
   win->PopViewTransform();
   EagleColor c(255,0,0,255);
   if (elapsed < 10.0) {
      c.SetColor(255,255,255,255);
   }
   else if (elapsed < 15.0) {
      c.SetColor(255,255,0,255);
   }
   win->DrawTextString(font_28days , StringPrintF("%5.0f kM away" , 5000.0*(1.0-pct)) ,
                        SCREEN_WIDTH/2.0 , 10.0 , c , HALIGN_CENTER , VALIGN_TOP);
   if (elapsed >= 15.0) {
      win->DrawTextString(font_28days , "Final Approach" , SCREEN_WIDTH/2.0 , SCREEN_HEIGHT - 10 ,
                           c , HALIGN_CENTER , VALIGN_BOTTOM);
   }
}



bool Story::HandleEvent(EagleEvent e) {
   (void)e;
   return false;
}



int Story::Update(double dt) {
   Scene::Update(dt);
   if (elapsed >= 20.0) {
      return SCENE_COMPLETE;
   }
   return SCENE_RUNNING;
}






#include "Credits.hpp"



#include "ExMokkan.hpp"
#include "Eagle/Font.hpp"
#include "Eagle/backends/Allegro5/Allegro5GraphicsContext.hpp"

#include "Eagle/Interpolate.hpp"


Credits::Credits() :
      Scene(),
      credits(),
      fonts(),
      colors(),
      totalheight(0),
      maxwidth(0)
{}



int Credits::Init() {

   credits ={"KrampusJoke23\n" \
             "and plenty of\n" \
             "self-deprecation\n" \
             "brought to you\n" \
             "by Edgar Reynaldo\n" \
             "\n" \
             "\n",
             "Fonts by 1001\n" \
             "FreeFonts :",
             "\nChristmasSnow.ttf",
             "\n28DaysLater.ttf",
             "\nNUCLEARWAR.TTF" \
             "\n\n",
             "Images courtesy\n" \
             "NASA JPL\n\n"};
   fonts = {win->GetFont("Data/Fonts/ChristmasSnow.ttf"       , -48),
            win->GetFont("Data/Fonts/Verdana.ttf"             , -48),
            win->GetFont("Data/Fonts/ChristmasSnow.ttf"       , -48),
            win->GetFont("Data/Fonts/28DaysLater.ttf"         , -48),
            win->GetFont("Data/Fonts/CFNuclearWarRegular.ttf" , -48),
            win->GetFont("Data/Fonts/ChristmasSnow.ttf"       , -48)};
   colors = {EagleColor(255,255,255,255),
             EagleColor(0,255,0,255),
             EagleColor(127,255,255,255),
             EagleColor(255,127,0,255),
             EagleColor(255,0,0,255),
             EagleColor(0,127,255,255)};


   totalheight = 0;
   maxwidth = fonts[0]->Width("ChristmasSnow.ttf");
   for (unsigned int i = 0 ; i < 6 ; ++i) {
      totalheight += fonts[i]->Height(credits[i] , 12);
   }
   return SCENE_READY;
}



void Credits::Display() {
   double pct = elapsed/30.0;
   if (pct <= 1.0) {
      int startx = (SCREEN_WIDTH - maxwidth)/2 - 36;
      int starty = SCREEN_HEIGHT;
      int destx = (SCREEN_WIDTH - maxwidth)/2 + 36;
      int desty = 0 - totalheight;
      int deltax = 0;
      int deltay = 0;
      int ls = 12;
      for (unsigned int i = 0 ; i < 6 ; ++i) {
         win->DrawMultiLineTextString(fonts[i] , credits[i] , Interpolate(startx , destx , pct) + deltax , Interpolate(starty , desty , pct) + deltay , colors[i] , ls , HALIGN_LEFT , VALIGN_TOP);
         deltax += ls;
         deltay += fonts[i]->Height(credits[i] , ls);
      }
   }
}



bool Credits::HandleEvent(EagleEvent e) {
   return false;
}



int Credits::Update(double dt) {
   Scene::Update(dt);
   if (elapsed > 30.0) {return SCENE_COMPLETE;}
   return SCENE_RUNNING;
}

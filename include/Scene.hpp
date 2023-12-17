



#ifndef Screen_HPP
#define Screen_HPP


class EagleGraphicsContext;
#include "Eagle/Events.hpp"
class EagleFont;


class Scene {
public :
   double elapsed;

   Scene();
   virtual ~Scene() {}
   
   virtual bool Init(EagleGraphicsContext* win)=0;

   virtual void Display(EagleGraphicsContext* win)=0;
   virtual bool HandleEvent(EagleEvent e);
   virtual void Update(double dt);
};

class Intro : public Scene {
   
protected :
   EagleFont* font;
   EagleFont* font_28days;
   EagleFont* font_nuclear;
   EagleFont* font_snow;
public :
   Intro();
   
   virtual bool Init(EagleGraphicsContext* win) override;
   
   virtual void Display(EagleGraphicsContext* win) override;
   
   
};



#endif // Screen_HPP

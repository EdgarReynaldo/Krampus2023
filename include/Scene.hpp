



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

   virtual bool Init()=0;

   virtual void Display()=0;
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

   virtual bool Init() override;

   virtual void Display() override;


};

#include "Hexagon.hpp"

class GameScene : public Scene {
protected :
   HexGrid grid;
public :

   virtual bool Init();
   virtual void Display();
   virtual bool HandleEvent(EagleEvent e);
   virtual void Update(double dt);
};


#endif // Screen_HPP

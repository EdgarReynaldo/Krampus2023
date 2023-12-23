



#ifndef Screen_HPP
#define Screen_HPP


class EagleGraphicsContext;
#include "Eagle/Events.hpp"
class EagleFont;

enum SCENE_STATUS {
   SCENE_NOT_READY = 0,
   SCENE_READY     = 1,
   SCENE_RUNNING   = 2,
   SCENE_QUIT      = 3
};



class Scene {
public :
   double elapsed;

   Scene();
   virtual ~Scene() {}

   virtual int Init()=0;

   virtual void Display()=0;
   virtual bool HandleEvent(EagleEvent e);
   virtual int Update(double dt);
};

class Intro : public Scene {

protected :
   EagleFont* font;
   EagleFont* font_28days;
   EagleFont* font_nuclear;
   EagleFont* font_snow;
public :
   Intro();

   virtual int Init() override;

   virtual void Display() override;
   virtual int Update(double dt) override;

};

#include "Hexagon.hpp"

class GameScene : public Scene {
protected :
   HexGrid grid;
public :

   virtual int Init();
   virtual void Display();
   virtual bool HandleEvent(EagleEvent e);
   virtual int Update(double dt);
};


#endif // Screen_HPP

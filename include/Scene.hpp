



#ifndef Screen_HPP
#define Screen_HPP


#include "Eagle/Events.hpp"



enum SCENE_STATUS {
   SCENE_NOT_READY = 0,
   SCENE_READY     = 1,
   SCENE_RUNNING   = 2,
   SCENE_COMPLETE  = 3,
   SCENE_QUIT      = 4
};



class Scene {
public :
   double elapsed;

   Scene();
   virtual ~Scene() {}

   virtual int Init();

   virtual void Display();
   virtual bool HandleEvent(EagleEvent e);
   virtual int Update(double dt);
};


#endif // Screen_HPP

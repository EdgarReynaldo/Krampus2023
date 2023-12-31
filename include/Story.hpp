



#ifndef Story_Scene_HPP
#define Story_Scene_HPP

#include "Scene.hpp"


class EagleImage;

class Story : public Scene {

protected :
   EagleImage* mars;

public :
   Story();


   virtual int Init();

   virtual void Display();
   virtual bool HandleEvent(EagleEvent e);
   virtual int Update(double dt);



};

#endif // Story_Scene_HPP

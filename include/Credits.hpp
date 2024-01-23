

#ifndef Credits_HPP
#define Credits_HPP

#include <vector>
#include <string>
class EagleFont;
#include "Eagle/Color.hpp"

#include "Scene.hpp"



class Credits : public Scene {

protected :
   std::vector<std::string> credits;
   std::vector<EagleFont*> fonts;
   std::vector<EagleColor> colors;

   int totalheight;
   int maxwidth;


public :
   Credits();


   virtual int Init();

   virtual void Display();
   virtual bool HandleEvent(EagleEvent e);
   virtual int Update(double dt);

};






#endif // Credits_HPP




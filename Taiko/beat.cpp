#include "beat.h"
#include <iostream>
using namespace std;
beat::beat()
{

}


void beat::move()
{
    this->setPos(this->pos().x()- 1 , this->pos().y());
}

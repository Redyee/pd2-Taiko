#include "shoot.h"

shoot::shoot()
{

}


void shoot::move()
{
    this->setPos(this->pos().x()+ 1 , this->pos().y());
}

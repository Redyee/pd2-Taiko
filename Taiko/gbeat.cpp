#include "gbeat.h"

gbeat::gbeat()
{

}


void gbeat::move()
{
    this->setPos(this->pos().x()- 1 , this->pos().y());
}

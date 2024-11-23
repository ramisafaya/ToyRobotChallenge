#pragma once
#include "Entity.h"
class Robot : public Entity
{
	public:
		bool move() override;
		bool rotateLeft() override;
		bool rotateRight() override;
};


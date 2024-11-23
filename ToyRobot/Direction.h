#pragma once
class Direction
{
	public:
		// order W, N, E, S is important so we can add or subtract for RIGHT and LEFT operations
		enum class Facing { west, north, east, south };

		Direction();
		Direction(Facing dir);

		void turnLeft();
		void turnRight();

		Facing getDirection();

	private:
		Facing mFacingDirection;
};


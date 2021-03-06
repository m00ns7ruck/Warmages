#include "Collision.hpp"

bool Collision::AABB( const SDL_Rect& rec1, const SDL_Rect& rec2 )
{
    if (
	rec1.x + rec1.w >= rec2.x &&
	rec2.x + rec2.w >= rec1.x &&
	rec1.y + rec1.h >= rec2.y &&
	rec2.y + rec2.h >= rec1.y
	)
	return true;
    else
	return false;
}

bool Collision::AABB( const ColliderComponent& col1, const ColliderComponent& col2 )
{
    if( AABB( col1.getCollider(), col2.getCollider()) )
    {
	// printf("%s hit: %s\n", col1.getTag().c_str(), col2.getTag().c_str() );
	return true;
    }

    return false;
}

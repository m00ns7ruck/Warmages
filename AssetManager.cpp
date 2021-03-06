#include "AssetManager.hpp"

#ifdef _WIN32

#include "ECSystem\Components.hpp"

#endif



#ifdef _WIN64

#include "ECSystem\Components.hpp"

#endif



#ifdef __linux__

#include "ECSystem/Components.hpp"

#endif



AssetManager::AssetManager( Manager* mngr ) : manager( mngr )
{}

AssetManager::~AssetManager()
{}

void AssetManager::createProjectile( Vector2D pos, Vector2D vel, int range, int speed, std::string id )
{
    auto& projectile( manager->addEntity() );
    projectile.addComponent< TransformComponent >( pos.getX(), pos.getY(), 32, 32, 1 );
    projectile.addComponent< SpriteComponent >( id, false );
    projectile.addComponent< ProjectileComponent >( range, speed, vel );
    projectile.addComponent< ColliderComponent >( "projectile" );
    projectile.addGroup( Game::groupProjectiles );

}

void AssetManager::createGameObject( Vector2D pos, bool stat, int scl, int durability, int mass, std::string id )
{
    auto& gameObject( manager->addEntity() );
    gameObject.addComponent< TransformComponent >( pos.getX(), pos.getY(), 32, 32, scl );
    gameObject.addComponent< SpriteComponent >( id, false );
    gameObject.addComponent< ObjectComponent >( durability, stat, mass );
    gameObject.addComponent< ColliderComponent >( "GameObj" );
    gameObject.addGroup( Game::groupObjects );
}

void AssetManager::addTexture( std::string id, const char *path )
{
    textures.emplace( id, TextureManager::LoadTexture( path ) );
}

SDL_Texture* AssetManager::getTexture( std::string id )
{
    return textures[id];
}

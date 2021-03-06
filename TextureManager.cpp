#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture( const char *filename )
{
    SDL_Surface* surf = IMG_Load( filename );
    if ( surf == NULL )
	printf( "No image was loaded because: %s\n", SDL_GetError() );

    SDL_Texture* texture = SDL_CreateTextureFromSurface( Game::renderer, surf );
    SDL_FreeSurface( surf );

    return texture;
}

void TextureManager::Draw ( SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flipFlag )
{
    SDL_RenderCopyEx( Game::renderer, texture, &src, &dest, NULL, NULL, flipFlag );
}

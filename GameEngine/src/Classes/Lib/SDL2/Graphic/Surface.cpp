#include "Lib/SDL2/Graphic/Surface.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    Surface::Surface(std::string path) {
        this->surface = IMG_Load(path.c_str());
        if (this->surface == NULL) {
            throw Utils::Error("Error: Couldn't load surface " + path);
        }
    }

    Surface::Surface(SDL_Surface *surface)
    {
        this->surface = surface;
    }

    Surface::~Surface() {
        SDL_FreeSurface(this->surface);
    }

    SDL_Surface *Surface::getSurface() {
        return (this->surface);
    }

    Utils::Vector2<int> Surface::getDim() {
        return (Utils::Vector2<int>(this->surface->w, this->surface->h));
    }

}
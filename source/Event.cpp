/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Event.h"


TkEvent::TkEvent() {
}

//------------------------------------------------------------------------------
TkEvent::~TkEvent() {
    //Do nothing
}
void TkEvent::dispatch(SDL_Event* e) {
    switch(e->type) {
        case SDL_ACTIVEEVENT: {
            switch(e->active.state) {
                case SDL_APPACTIVE:    {
                    break;
                }
            }
            break;
        }

        case SDL_KEYDOWN: {
            break;
        }
        case SDL_MOUSEMOTION: {
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            switch(e->button.button) {
                case SDL_BUTTON_LEFT: {
                    break;
                }
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:    {
            switch(e->button.button) {
                case SDL_BUTTON_LEFT: {
                    break;
                }
            }
            break;
        }
        case SDL_QUIT: {
            break;
        }
        default: {
            break;
        }
    }
}

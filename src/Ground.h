/* Ground.h
 *
 * Copyright 2005 Eliot Eshelman
 * eliot@6by9.net
 *
 *
 *  This file is part of Battlestar Tux.
 *
 *  Battlestar Tux is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  Battlestar Tux is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Battlestar Tux; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef GROUND_H_
#define GROUND_H_

#include "SDL_opengl.h"

#include "Game.h"

class GroundSegment;


enum GroundType {
	MENU_GROUND,		// Display while in menus
	SOLID_GROUND		// Solid earth below
};


/* Lowest viewable level on the screen.  It's the ground. */
class Ground {
	public:
				Ground( GroundType type, Game* g );
				~Ground();

				void Draw();

				GroundType getType();
				GLuint getTexture();

				// Constant Z position for the ground.
				static const float zPos = -2.0;

				// Number of ground segments necessary to fill the screen.
				static const int numSegX = 2;
				static const int numSegY = 2;

				// Size of each segment.
				static const float segSize = 40;

	private:
				// Take the bottom segment and move it to the top.
				void rotateSegments();

				// Particular variation of ground texturing.
				GroundType groundType;

				// Ground texture for the segments.
				GLuint texture;

				// The first in the list of ground pieces.
				GroundSegment* rootSeg;

				Game* game;
};


#endif /*GROUND_H_*/
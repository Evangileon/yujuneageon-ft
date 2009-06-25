/* Battlestar TUX
 * Copyright (C) 2008-2009 Eliot Eshelman <battlestartux@6by9.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef HexShip_H
#define HexShip_H

#include <assert.h>
#include <Ogre.h>
#include <vector>

#include "HexCell.h"

class HexShip {
public:
    HexShip();
    HexShip(const Ogre::String& name, const Ogre::Vector3& pos);
    ~HexShip();

    void update(unsigned long lTimeElapsed);

    void applyCentralImpulse(const Ogre::Vector3& impulse);

    // Since the HexShip itself is not an Ogre object, we will use the OgreNode
    // of the core HexCell when one is needed.
    Ogre::SceneNode* getOgreNode() {
        assert(coreCell);
        return coreCell->getOgreNode();
    }

private:
    HexShip(const HexShip&);
    HexShip & operator = (const HexShip&);

    HexCell* coreCell;
    std::vector<HexCell*> shipCells;
};

#endif


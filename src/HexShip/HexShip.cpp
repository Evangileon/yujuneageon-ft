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

#include <assert.h>
#include <Ogre.h>

#include "HexShip.h"


HexShip::HexShip(const std::string& name, const Ogre::Vector3& pos) :
    mName(name),
    mShipCells()
{
    mCoreCell = new HexCell(name + "CoreCell", 1, 1000);
    //TODO: Create actual ship and add core cell.
}

HexShip::~HexShip() {
    delete mCoreCell;
}


void HexShip::addHexCell(HexCell* cell, const Ogre::Vector2& pos) {
    cell->setPosition(pos);
    mShipCells.push_back(cell);

    rebuildCollisionHull();
}


void HexShip::removeHexCell(HexCell* cell) {
    assert(cell != mCoreCell);

    // Find and remove the correct HexCell.
    std::vector<HexCell*>::iterator iter;
    for(iter = mShipCells.begin(); iter != mShipCells.end(); iter++) {
        if(*iter == cell)
            mShipCells.erase(iter);
    }

    rebuildCollisionHull();
}


void HexShip::update( unsigned long lTimeElapsed ) {
}


void HexShip::applyCentralImpulse(const Ogre::Vector3& impulse) {
    assert(mCoreCell);
    mCoreCell->applyCentralImpulse(impulse);
}


void HexShip::toXml(TiXmlElement* node) const {
    TiXmlElement* shipNode = new TiXmlElement("HexShip");

    //shipNode->SetAttribute("name", mName);

    std::vector<HexCell*>::const_iterator iter;
    for(iter = mShipCells.begin(); iter != mShipCells.end(); iter++) {
        (*iter)->toXml(shipNode);
    }

    // If a valid XML element wasn't passed, return one.
    // If a valid XML element was passed, link to it.
    if(!node)
        node = shipNode;
    else
        node->LinkEndChild(shipNode);
}


void HexShip::rebuildCollisionHull() {
    //TODO: Rebuild compound collision shape.
}


//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Fax.h"

Define_Module(Fax);

void Fax::initialize()
{
    // TODO - Generated method body

    int F = getAncestorPar("f");
    EV<<"Send to PC"<<F<<endl;

    if(F<=3){
        cPacket *p = new cPacket();
    //Message Send From Switch[0] to PC[0]
    if(F==0){

        p->setKind(7);
    }

    else {
        p->setKind(8);
    }
    cMessage *msg=check_and_cast<cMessage *>(p);
    send(msg,"out");
  }
}

void Fax::handleMessage(cMessage *msg)
{
    // TODO - Generated method body



}

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

#include "Printer.h"

Define_Module(Printer);

cQueue *q= new cQueue();

void Printer::initialize()
{
    // TODO - Generated method body
}

void Printer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    int type= msg->getKind();
    if(type!=3 && type!=9){
        delete(msg);
        EV<<"Message ignored"<<endl;

    }


    else if(type==3 || type==9){
       cPacket *p = check_and_cast<cPacket *>(msg);


       q->insert(msg);
       EV<<"msg inserted"<<endl;


    }

}

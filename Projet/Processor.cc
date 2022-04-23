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

#include "Processor.h"

Define_Module(Processor);

void Processor::initialize()
{
    // TODO - Generated method body
}

void Processor::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    int type=msg->getKind();
     EV<<type<<endl;
    if(type==0)
    {
                  cMessage *copy= msg->dup();
                  copy->setKind(2);
                  send(copy,"out",2);
                   EV<<"Send message"<<endl;
    }

    if(type==1)
    {
                        cMessage *copy= msg->dup();
                        copy->setKind(4); //Message send from Switch[1] to Router
                        send(copy,"out",0);
                         EV<<"Send message from Switch[2] to Router"<<endl;
    }


    if(type==2)
    {
                     cMessage *copy= msg->dup();
                     copy->setKind(5);
                     send(copy,"out",1);
                      EV<<"Send message from router to Switch[1] "<<endl;
    }

    if(type==3){
                              cMessage *copy= msg->dup();
                              send(copy,"out",3);
                               EV<<"Send message from Switch[0] to Printer  "<<endl;
               }

if(type==4 || type==7){
                        cMessage *copy= msg->dup();
                        send(copy,"out",0);
if(type==7){
    EV<<"PC[0] received Fax"<<endl;
}
else{   EV<<"Send message from Switch[1] or Router  "<<endl;
}
}


if(type==5)
{
    for (int i=0; i<= gateSize("out")-1; i++){
                     EV<<"Entering for"<<endl;
                       const  char *switchGate= this->gate("out",i)->getNextGate()->getOwnerModule()->getName();
                            EV<<"switchGate"<< i << endl;
                              if(i!=0 && i!=4){
                            cMessage *copy= msg->dup();
                            copy->setKind(6);
                            send(copy,"out",i);
                             EV<<"Send message from Switch[1] to PC"<<endl;
                              }
                        }
}

if(type==8){

    msg->setKind(9);
    send(msg,"out",2);
    EV<<"Message send to Router from Fax "<<endl;

}

if(type==9){

    msg->setKind(10);
    send(msg,"out",1);

    EV<<"Packet arrived from Fax to Switch[1]"<<endl;
}


if(type==10){

    send(msg,"out",3);
    EV<<"Packet arrived from Fax to Printer"<<endl;
}

}

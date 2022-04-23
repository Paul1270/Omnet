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

#include "PC.h"

Define_Module(PC);

void PC::initialize()
{
    // TODO - Generated method body
    if(getIndex()==0){
        {

            cMessage *msg= new cMessage("send me the packet");
            msg->setKind(0);            //Message send from PC[0] to Switch[0]
            sendDelayed(msg,simTime()+dblrand(),"out");         //Message Delay Randomly
             EV<<"Sent a message" <<endl;

     }
  }
}

void PC::handleMessage(cMessage *msg)
{
    // TODO - Generated method body // message handle from pc[0] to other
    int index= msg->getKind();
    if(index==0)
    {
        if(getIndex()==0){
            delete(msg);
            EV<<"Message ignored for PC[0]"<<endl;
        }
    }

    if(index==6) //type=6 : Message send from Switch[1] to PC

    {
         if(getIndex()!=0){

        EV << "Message arrived" << endl;
        cPacket *p = new cPacket("p");
        p->setByteLength(intuniform(50,100));
        cMessage *msg= check_and_cast <cMessage *>(p);
        msg->setKind(1); // type 1 : send message from PC to Switch[1]
        cMessage *cpy= msg->dup();
        send(cpy,"out");
        EV<<"Sent the packet to switch[1]" <<endl;
        }
    }

if(index==4){

    if(getIndex()!=0){
    delete(msg);
    EV<<"Message sent from Switch[1] to Switch[0] ignored by PC"<<endl;
}

    else  if(getIndex()==0){
      cPacket *p= new cPacket("p");
    p -> decapsulate();

            int length = p -> getByteLength();
                EV<<"Packet Size is: "<< length << endl;
                if (length>64){
                    delete(p);
                    EV<<"Message TOO BIG" <<endl;
                }
                else{
                           cMessage *msg= check_and_cast <cMessage *>(p);
                            msg->setKind(3);
                            cMessage *cpy= msg->dup();
                            send(cpy,"out");
                            EV<<"Sent the packet to Printer" <<endl;
                }
      }
}

if(index==3){


    delete(msg);
    EV<<"Message sent from Switch[0] to PC[0] IGNORED "<<endl;
}

}

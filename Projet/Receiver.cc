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

#include "Receiver.h"

Define_Module(Receiver);

void Receiver::initialize()
{
    // TODO - Generated method body
}

void Receiver::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    int type=msg->getKind();
    if(type == 0 || type==7 || type==8 )
    {
        for (int i=0; i<= gateSize("in")-1; i++){

        const char *previousGate= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getName();
        EV<<"previousGate"<< previousGate << endl;

                           if (strcmp (previousGate ,"switch") == 0){

                            if(getIndex()==0){
                              send(msg,"out");
                              EV<<"message send from receiver of switch[0] of type 0"<<endl;
                              break;
                           }
                        }
       }


   }

    if(type == 1)

    {

        for (int i=0; i<= gateSize("in")-1; i++){

                const char *previousGate= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getName();
                EV<<"previousGate"<< previousGate << endl;

                                   if (strcmp (previousGate ,"switch") == 0){
                                       int index= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getIndex();
                                    if(index==1){
                                       send(msg,"out");
                                       EV<<"message send from receiver of switch[1] of type 1"<<endl;
                                       break;
                                   }
                                }
                }
    }

    if(type==2 || type==9)

    {
    for (int i=0; i<= gateSize("in")-1; i++){

            const char *previousGate= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getName();
            EV<<"previousGate"<< previousGate << endl;

                               if (strcmp (previousGate ,"Router") == 0){

                                   send(msg,"out");
                                   EV<<"message send from receiver of router of type 2"<<endl;
                                   break;
                            }


            }
    }





    if(type==3){


        for (int i=0; i<= gateSize("in")-1; i++){

        const char *previousGate= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getName();
        EV<<"previousGate"<< previousGate << endl;

                           if (strcmp (previousGate ,"switch") == 0){

                           int index= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getIndex();
                           if(index==1){
                                                                     delete(msg);
                                                                     EV<<"msg ignored by switch[0]"<<endl;
                         }
                           else if(index==0){

                              send(msg,"out");
                              EV<<"message send from receiver of switch[0] of type 3"<<endl;
                              break;
                           }
                        }

                           else{
                               delete(msg);
                               EV<<"ignored by router"<<endl;
                           }
       }
    }

    if(type==4)             //Send from switch[1] to router
    {
        for (int i=0; i<= gateSize("in")-1; i++){

                const char *previousGate= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getName();
                EV<<"previousGate"<< previousGate << endl;

                                   if (strcmp (previousGate ,"Router") == 0){

                                       send(msg,"out");
                                       EV<<"message send from receiver of router of type 4"<<endl;
                                        break;

                                }

                                   if (strcmp (previousGate ,"switch") == 0){
                                       int index= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getIndex();

                                        if(index==0){
                                       send(msg,"out");

                                       EV<<"message send from receiver of switch[0] of type 4 "<<endl;
                                       break;
                                             }

                                      }
                }
        }


    if(type==5 || type==10)             //Message send from router to switch[1]

    {
        for (int i=0; i<= gateSize("in")-1; i++){

                        const char *previousGate= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getName();
                        EV<<"previousGate"<< previousGate << endl;



                                           if (strcmp (previousGate ,"switch") == 0){
                                                  int index= this->gate("in",i)->getPreviousGate()->getOwnerModule()->getIndex();
                                                if(index==1){
                                               send(msg,"out");

                                               EV<<"message send from receiver of switch[1] of type 5 "<<endl;
                                               break;
                                                     }

                                           }
                        }

    }

    if(type==6){

        delete(msg);
        EV<<"Msg of type 6 ignored"<<endl;

    }
}

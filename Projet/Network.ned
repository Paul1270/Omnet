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
network Network


{
    parameters:
        int f;

    submodules:
        Router: Router;
        switch[2]: Switch;
        PC[3]: PC;
        Printer[2]: Printer;
        Fax: Fax;
    connections:

        //Connection between Switch[0] and PC[0]
        PC[0].in <-- switch[0].out++;
        PC[0].out --> switch[0].in++;

		//Connection between Switch[0] and Fax
        Fax.in <-- switch[0].out++;
        Fax.out --> switch[0].in++;

        //Connection between Router and Switch[0],[1]
        for i=0..1 {
            switch[i].in++ <-- Router.out++;
            switch[i].out++ --> Router.in++;
        }

        //Connection between Switch[1] and PC[1],[2]
        for i=1..2 {
            PC[i].in <-- switch[1].out++;
            PC[i].out --> switch[1].in++;
        }

        //Connection between Switch[0],[1] and Printer[0][1]
        for i=0..1, for j=0..1 {
            Printer[i].in <-- switch[j].out++ if i==j;
            Printer[i].out --> switch[j].in++ if i==j;
        }
}

/*
 * StringD.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: orce
 */
#include <StringD.h>
#include <Arduino.h>

#include <RemoteDebug.h>        //https://github.com/JoaoLopesF/RemoteDebug
extern RemoteDebug Debug;


StringD::StringD(char* StringToParase, const char* Delimiter){
	StS=StringToParase;
	delimiter=Delimiter;
	//pos_del=NULL;
	Process();
}


/**
 * @brief Private function that is launched by constructor. Function performs an analysis of the String
 */
void StringD::Process(){

	//determine the number of nodes
	unsigned int pos=1;
	unsigned int prev_pos=0;

	nodes=0; // initialise number of nodes
	while(StS.indexOf(delimiter,pos)!=-1){
		if (pos>prev_pos){
			// there one more node increment variable of number of nodes
			nodes++;
			prev_pos=pos; // memorise the current position of the delimiter

			Debug.println(StS.indexOf(delimiter,pos));

			pos=StS.indexOf(delimiter,pos)+1;//move start position for next search
		}
		yield();
	}
	Debug.printf("Number of nodes %d\r\n",nodes);


	// memorise the positions of the delimiters
	pos=1;
	prev_pos=0;
	nodes=0; // initialise number of nodes

	while(StS.indexOf(delimiter,pos)!=-1){
		if (pos>prev_pos){
			// there one more node increment variable of number of nodes

			prev_pos=pos; // memorise the current position of the delimiter

			Debug.println(StS.indexOf(delimiter,pos));

			pos_del[nodes]=StS.indexOf(delimiter,pos);//move start position for next search
			pos=pos_del[nodes]+1;

			nodes++;
		}
		yield();
	}

	Debug.printf("Number of nodes %d\r\n",nodes);

	Debug.printf("Pointer address inside class of nodes var %x\r\n",&nodes);


}


StringD::~StringD(){
	//delete [] pos_del;
}

void StringD::PrintPosDelimiters(){

}

int StringD::getnodes(){
	Debug.printf("Number of nodes in class function getnodes %d\r\n",nodes);

	return nodes;
}

//
//String StringD::Node(int position){
//
//}

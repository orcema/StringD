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
	//m_pos_del=NULL;
	Process();
}


/**
 * @brief Private function that is launched by constructor. Function performs an analysis of the String
 */
void StringD::Process(){

	//determine the number of m_nodes
	unsigned int pos=1;
	unsigned int prev_pos=0;

	m_nodes=0; // initialise number of m_nodes
	while(StS.indexOf(delimiter,pos)!=-1){
		if (pos>prev_pos){
			// there one more node increment variable of number of m_nodes
			m_nodes++;
			prev_pos=pos; // memorise the current position of the delimiter

			Debug.println(StS.indexOf(delimiter,pos));

			pos=StS.indexOf(delimiter,pos)+1;//move start position for next search
		}
		yield();
	}
	Debug.printf("Number of m_nodes %d\r\n",m_nodes);


	// memorise the positions of the delimiters
	pos=1;
	prev_pos=0;
	m_nodes=0; // initialise number of m_nodes

	while(StS.indexOf(delimiter,pos)!=-1){
		if (pos>prev_pos){
			// there one more node increment variable of number of m_nodes

			prev_pos=pos; // memorise the current position of the delimiter

			Debug.println(StS.indexOf(delimiter,pos));

			m_pos_del[m_nodes]=StS.indexOf(delimiter,pos);//move start position for next search
			pos=m_pos_del[m_nodes]+1;

			m_nodes++;
		}
		yield();
	}

	Debug.printf("Number of m_nodes %d\r\n",m_nodes);

	Debug.printf("Pointer address inside class of m_nodes var %x\r\n",&m_nodes);


}


StringD::~StringD(){
	//delete [] m_pos_del;
}

void StringD::PrintPosDelimiters(){

}

uint8_t StringD::max_node(){
	Debug.printf("Number of m_nodes in class function getnodes %d\r\n",m_nodes);

	return m_nodes;
}

String get_node(uint8_t node){
//	if (node<1 || node>m_nodes){
//
//	}
}


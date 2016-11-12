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
	Debug.printf("length of char array = %d\r\n",sizeof(*StringToParase));
	StS=StringToParase;
	Debug.printf("length of StS  = %d\r\n",StS.length());
	m_delimiter=Delimiter;
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
	while(StS.indexOf(m_delimiter,pos)!=-1){
		if (pos>prev_pos){
			// there one more node increment variable of number of m_nodes
			m_nodes++;
			prev_pos=pos; // memorise the current position of the m_delimiter

			Debug.println(StS.indexOf(m_delimiter,pos));

			pos=StS.indexOf(m_delimiter,pos)+1;//move start position for next search
		}
		yield();
	}
	Debug.printf("Number of m_nodes %d\r\n",m_nodes);


	// memorise the positions of the m_delimiters
	pos=1;
	prev_pos=0;
	m_nodes=0; // initialise number of m_nodes

	while(StS.indexOf(m_delimiter,pos)!=-1){
		if (pos>prev_pos){
			// there one more node increment variable of number of m_nodes

			prev_pos=pos; // memorise the current position of the m_delimiter

			Debug.println(StS.indexOf(m_delimiter,pos));

			m_pos_del[m_nodes]=StS.indexOf(m_delimiter,pos);//move start position for next search
			pos=m_pos_del[m_nodes]+1;

			m_nodes++;
		}
		yield();
	}
	m_nodes++; // increment node by one for the last node

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

char* StringD::get_node(uint8_t node){

	if (node<1 | node > m_nodes){
		return (char*) "Invalid_Node"; // return node selected is out of boundaries
	}

	uint8_t left=0; // initialise left position to 1st character in string

	uint8_t right=m_pos_del[node-1]; //set right boundary for node extract

	if(node>1){
		//set left boudary for node extract with an exception, always 0 for 1st node in string
		left=m_pos_del[node-2]+1;
	}


	// return the node content
	if (node==m_nodes){
		// last node, no need for end pisition in substring
		return (char*)StS.substring(left,StS.length()).c_str();
	}else{
//		return (char*)StS.substring(m_pos_del[node-1]+1,m_pos_del[node]-1).c_str();
		return (char*)StS.substring(left,right).c_str();

	}
}


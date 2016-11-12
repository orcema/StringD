/*
 * StringD.h
 *
 *  Created on: Nov 5, 2016
 *      Author: orce
 */

#ifndef LIB_STRINGD_SRC_STRINGD_H_
#define LIB_STRINGD_SRC_STRINGD_H_




#include "WString.h"


class StringD {
	public:
		String m_delimiter; // node m_delimiter for split up of string content
		//StringD();


		StringD(char* StringToParase, const char* Delimiter);
		StringD(void* StringToParase, const char* Delimiter,int length);
		~StringD(); // destructor
		//String Node(int position); // pointer to the
		void PrintPosDelimiters(); // print the positions of the delimiters
		int m_nodes; // number of nodes in the string
		uint8_t m_pos_del[254]; //array of delimiter positions in the string
		uint8_t max_node(); //getter function for the total number of nodes identified
		char* get_node(uint8_t node);// function to get a specific node

	private:
//		int m_StartPos; // start position of the node in the string
//		int EndPos; // end position of the node in the string
		void Process(); // analyse String content
		String StS; // copy of String content to be analysed
		int m_length; // data length to be analysed

};

#endif /* LIB_STRINGD_SRC_STRINGD_H_ */

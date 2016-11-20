/*
 * StringD.h
 *
 *  Created on: Nov 5, 2016
 *      Author: orce
 */

#ifndef LIB_STRINGD_SRC_STRINGD_H_
#define LIB_STRINGD_SRC_STRINGD_H_

// define Debug_StringD to get debugging


#include "WString.h"


class StringD {
	public:
		StringD(char* StringToParase, const char* Delimiter);
		StringD(void* StringToParase, const char* Delimiter,int length);
		~StringD(); // destructor
		//String Node(int position); // pointer to the
		uint8_t max_node(); //getter function for the total number of nodes identified
		const char* get_node (uint8_t node);// function to get a specific node
		String NodeSelected; //substring of Sts

	private:
		void Process(); // analyse String content
		String StS; // copy of String content to be analysedv
		int m_length; // data length to be analysed
		int m_nodes; // number of nodes in the string
		uint8_t m_pos_del[254]; //array of delimiter positions in the string
		String m_delimiter; // node m_delimiter for split up of string content

};

#endif /* LIB_STRINGD_SRC_STRINGD_H_ */

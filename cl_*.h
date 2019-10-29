#ifndef CL_1_H
#define CL_1_H


#include "cl_base.h"

class cl_1: public cl_base{
	public:
	void get_name_by_addr(string);
	static void signal_1 (string &){};
	static void signal_2 (string &){};
	static void signal_3 (string &){};

	
};

#endif // CL_1_H
___________________________________
#ifndef CL_2_H
#define CL_2_H


#include "cl_base.h"

class cl_2: public cl_base{
public:
	
	static void hendler_1(cl_base *, string &);
	static void hendler_2(cl_base *, string &);

	
};

#endif // CL_2_H
_________________________________
#ifndef CL_3_H
#define CL_3_H


#include "cl_base.h"

class cl_3: public cl_base
{
public:
	cl_3();
	static void hendler_1(cl_base *,string &);
	
};

#endif // CL_3_H
_____________________________
#ifndef CL_4_H
#define CL_4_H


#include "cl_base.h"

class cl_4: public cl_base
{
public:
	cl_4();
	
	
};

#endif // CL_4_H

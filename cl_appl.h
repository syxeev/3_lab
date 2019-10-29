#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_1.h"

#include "cl_2.h"

#include "cl_3.h"

#include "cl_4.h"

using namespace std;

class cl_application: public cl_base
{
public: cl_application();
	//   ~cl_application ( );
	
	void bild_tree_objects();
	int exec_app();
	void signal_1 (string & s_text){}
private: cl_base * p_ob;

	cl_1 * p_ob_1, * ob_1_p;
	cl_2 * p_ob_2, * ob_5_p;
	cl_3 * ob_3_p;
	cl_4 * p_ob_4;
	
};

#endif // CL_APPLICATION_H

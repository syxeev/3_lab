#include "cl_application.h"
#include <iostream>
#include <string>
using namespace std;

cl_application::cl_application()
{
	set_object_name("root");

}


void cl_application::bild_tree_objects()
{
	
	ob_1_p = new cl_1;
	ob_1_p->set_object_name("ob_1");
	ob_1_p->set_parent(this);
	
	p_ob_2 = new cl_2;
	p_ob_2->set_object_name("ob_2");
	p_ob_2->set_parent(ob_1_p);
	
	ob_3_p = new cl_3;
	ob_3_p->set_object_name("ob_3");
	ob_3_p->set_parent(p_ob_2);
	
	p_ob_4 = new cl_4;
	p_ob_4->set_object_name("ob_4");
	p_ob_4->set_parent(p_ob_2);
	
	ob_5_p = new cl_2;
	ob_5_p->set_object_name("ob_5");
	ob_5_p->set_parent(ob_1_p);
	
	p_ob_1 = new cl_1;
	p_ob_1->set_object_name("ob_6");
	p_ob_1->set_parent(this);
	
	p_ob_1 = new cl_1;
	p_ob_1->set_object_name("ob_7");
	p_ob_1->set_parent(this);
	
	p_ob_2 = new cl_2;
	p_ob_2->set_object_name("ob_8");
	p_ob_2->set_parent(p_ob_1);
}

int cl_application::exec_app()
{
	output(this,0);
	string text;
	int signal;
	
	ob_1_p->set_connect(SIGNAL_D(ob_1_p->signal_1), ob_5_p, HENDLER_D(ob_5_p->hendler_1) );
	ob_1_p->set_connect(SIGNAL_D(ob_1_p->signal_2), ob_5_p, HENDLER_D(ob_5_p->hendler_2) );
	ob_1_p->set_connect(SIGNAL_D(ob_1_p->signal_2), ob_3_p, HENDLER_D(ob_3_p->hendler_1) );
	
	do{
		cin>>signal;
		switch(signal){
				
				case 1:
				cin>>text;
				ob_1_p->emit_signal(SIGNAL_D(ob_1_p->signal_1),text);
				break;
				
				case 2:
				cin>>text;
				ob_1_p->emit_signal(SIGNAL_D(ob_1_p->signal_2),text);
				break;
				
				case 3:
				cin>>text;
				ob_1_p->emit_signal(SIGNAL_D(ob_1_p->signal_2),text);
				break;
			default:
				break;
		}
	}
	while(signal!=0);
	return 0;
}


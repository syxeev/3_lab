#include "cl_1.h"
#include <iostream>
using namespace std;

void cl_1::get_name_by_addr(string path){
	cout<<"Object name: "<<(get_object(path))->get_object_name()<<endl;
}
____________________________________________
#include "cl_2.h"

void cl_2::hendler_1 (cl_base *p_ob, string &s_text){
	cout<<endl<<"Object name: "<<p_ob->get_object_name()<<" Text: "<<s_text;
}
void cl_2::hendler_2 (cl_base * p_ob, string &s_text){
	cout<<endl<<"Object name: "<<p_ob->get_object_name()<<" Text: "<<s_text;
}
__________________________________________
#include "cl_3.h"
	
	cl_3::cl_3()
	{
		set_state(1);
	}
void cl_3::hendler_1 (cl_base * p_ob, string &s_text){
	cout<<endl<<"Object name: "<<p_ob->get_object_name()<<" Text: "<<s_text;
}
	______________________________________
  #include "cl_4.h"

	cl_4::cl_4()
	{
		set_state(0);
	}

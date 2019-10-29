#ifndef CL_BASE_H
#define CL_BASE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define SIGNAL_D(signal_f)((void(*)(string&))(&(signal_f)))
#define HENDLER_D(hendler_f) ((void(*)(cl_base *,string &))(&(hendler_f)))

using namespace std;

class cl_base
{
public:
		cl_base(cl_base * p_parent = 0);
	void set_connect(void(*p_signal)(string &),cl_base *,void (*p_hendler)(cl_base *, string &));
	void emit_signal(void (*p_signal)(string &),string &s_command);
	void set_object_name(string s_object_name);
	string get_object_name();
	
	//---------------------------------------------------------------    Иерахия объектов
	void set_parent(cl_base * p_parent);
	void add_child(cl_base * p_child);
	void delete_child(string s_object_name);
	string get_item(string,int);
	cl_base * get_root();
	cl_base * get_object(string);
	cl_base * take_child(string s_object_name);
	cl_base * get_child(string s_object_name);
	
	//---------------------------------------------------------------    Состояние объекта
	void set_state(int i_state);
	int get_state();
	
	//---------------------------------------------------------------    Сервис
	void show_object_state();
	void output(cl_base *, int);
	
private:

	struct o_sh{
	cl_base * p_cl_base;
	void (*p_hendler)(cl_base*p_ob, string &);
	};
	
	multimap<void(*)(string &), o_sh *> connects;
	multimap<void(*)(string &), o_sh *>::iterator it_connects;
	
	vector<cl_base*> children; // ссылки на подчиненных объектов
	vector<cl_base*>::iterator it_child;
	
	string object_name; // наименование объекта
	cl_base * p_parent; // ссылка на головной объект
	int i_state; // состояние объекта
	
	cl_base * get_object_root();
	void show_state_next(cl_base * ob_parent);
};

#endif // CL_BASE_H

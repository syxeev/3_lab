#include "cl_base.h"
#include <vector>
#include <string>
using namespace std;

void cl_base::set_connect(void(*p_signal)(string &), cl_base *p_ob_hendler, void(*p_hendler)(cl_base *, string &)){
	void(*p_key)(string &);
	o_sh *p_value;
	if(connects.size()>0){
		it_connects = connects.begin();
		while(it_connects != connects.end()){
			p_key = it_connects->first;
			p_value = it_connects->second;
			if((p_key)==p_signal && (p_value->p_cl_base) == p_ob_hendler && (p_value->p_hendler) == p_hendler)
				return;
			it_connects++;
		}
	}
	p_value = new o_sh;
	p_value->p_cl_base = p_ob_hendler;
	p_value->p_hendler = p_hendler;
	connects.insert({p_signal, p_value});
}
	void cl_base::emit_signal(void (*p_signal)(string &), string &s_command){
		void (*p_hendler)(cl_base * p_ob, string &);
		if (connects.empty())
			return;
		if(connects.count(p_signal) == 0)
			return;
		(p_signal)(s_command);
		it_connects = connects.begin();
		while(it_connects != connects.end()){
			if((it_connects->first) == p_signal){
				p_hendler = it_connects->second->p_hendler;
				(p_hendler)(it_connects->second->p_cl_base, s_command);
			}
			it_connects++;
		}
	}
	

string cl_base::get_item(string path, int level){
	int start = 1, end, count = 1;
	while(start){
		end = path.find('/', start);
		if(count == level)
			return path.substr(start, end - start);
		count++;
		start = end+1;
	}
	return "";
}
	
	
	cl_base *cl_base::get_root(){
		cl_base * head;
		if(!(p_parent))
	return this;
	head = p_parent;
	while(head->p_parent){
		head = head -> p_parent;
	}
	return head;
	}
	
	cl_base * cl_base::get_object(string path){
		string item;
		cl_base * head, * child;
		int level = 2;
		head = get_root();
		item = get_item(path,1);
			if (item!=(get_root()->get_object_name()))
				return 0;
		item = get_item(path, level);
		while (!item.empty()){
			child = head->get_child(item);
			if (child){
				head = child;
				level++;
				item = get_item(path, level);
			}
			else
				return 0;
		}
		return head;
	}
	
	
	
	void cl_base::output(cl_base * ob_parent, int howfar){
		if(ob_parent->p_parent!=0)
			cout<<endl;
		for(int i=0; i<howfar; i++){
			cout<<"    ";
		}
		cout<<ob_parent->get_object_name();
		
		if(ob_parent->children.size() == 0) return;
		ob_parent->it_child = ob_parent->children.begin();
		howfar++;
		
		while(ob_parent->it_child != ob_parent->children.end())
		{
			output(*(ob_parent->it_child), howfar);
			ob_parent->it_child++;
		}
	}

cl_base::cl_base(cl_base * p_parent)
{
	//-------------------------------------------------------------------------
	// Конструктор
	//-------------------------------------------------------------------------
	
	set_object_name("cl_base");
	
	if(p_parent)
	{
		this->p_parent = p_parent;
		p_parent->add_child(this);
	}
	else
	{
		this->p_parent = 0;
	}
}

void cl_base::set_object_name(string s_object_name)
{
	//-------------------------------------------------------------------------
	// Присвоить имя объекту
	//-------------------------------------------------------------------------
	
	object_name = s_object_name;
}

string cl_base::get_object_name()
{
	//-------------------------------------------------------------------------
	// Получить имя объекта
	//-------------------------------------------------------------------------
	
	return object_name;
}

void cl_base::set_parent(cl_base * p_parent)
{
	//-------------------------------------------------------------------------
	// Определение ссылки на головной объект
	//-------------------------------------------------------------------------
	
	if(p_parent)
	{
		this->p_parent = p_parent;
		p_parent->children.push_back(this);
	}
}

void cl_base::add_child(cl_base * p_child)
{
	//-------------------------------------------------------------------------
	// Добавление нового объекта в перечне объектов-потомков
	//-------------------------------------------------------------------------
	
	this->children.push_back(p_child);
}

void cl_base::delete_child(string s_object_name)
{
	//-------------------------------------------------------------------------
	// Удаление объекта из перечня объектов-потомков
	//-------------------------------------------------------------------------
	
	if(children.size() == 0) return;
	
	it_child = children.begin();
	
	while(it_child != children.end())
	{
		
		if((*it_child)->get_object_name() == s_object_name)
		{
			
			children.erase(it_child);
			return;
		}
		it_child++;
	}
}

cl_base * cl_base::take_child(string s_object_name)
{
	//-------------------------------------------------------------------------
	// Удалить подчиненый объект и вернуть ссылку
	//-------------------------------------------------------------------------
	cl_base * ob_child;
	//-------------------------------------------------------------------------
	
	ob_child = get_child(s_object_name);
	
	if(ob_child == 0) return 0;
	
	delete_child(s_object_name);
	
	return ob_child;
}

cl_base * cl_base::get_child(string s_object_name)
{
	//-------------------------------------------------------------------------
	// Получить ссылку на объект потомок по имени объекта
	//-------------------------------------------------------------------------
	
	if(children.size() == 0) return 0;
	
	it_child = children.begin();
	
	while(it_child != children.end())
	{
		
		if((*it_child)->get_object_name() == s_object_name)
		{
			
			return (*it_child);
		}
		it_child++;
	}
	
	return 0;
}

void cl_base::set_state(int i_state)
{
	//-------------------------------------------------------------------------
	// Определить состояние объекта
	//-------------------------------------------------------------------------
	
	this->i_state = i_state;
}

int cl_base::get_state()
{
	//-------------------------------------------------------------------------
	// Получить состояние объекта
	//-------------------------------------------------------------------------
	
	return i_state;
}


void cl_base::show_object_state()
{
	show_state_next((cl_base*)this);
}

//     =====     private:     =====
cl_base * cl_base::get_object_root()
{
	//-------------------------------------------------------------------------
	// Ссылка на корневой объект
	//-------------------------------------------------------------------------
	cl_base * p_parent_previous; // ссылка на очередной головной объект
	//-------------------------------------------------------------------------
	
	if(object_name == "root") return this;
	
	p_parent_previous = p_parent;
	
	while(p_parent_previous->p_parent)
	{
		
		p_parent_previous = p_parent_previous->p_parent;
	}
	
	return p_parent_previous;
}


void cl_base::show_state_next(cl_base * ob_parent)
{
	//-------------------------------------------------------------------------
	// Вывод готовности (состояния) очередного объекта в цикле обхода дерева
	//-------------------------------------------------------------------------
	
	if(ob_parent->get_state() == 1)
	{
		
		cout << "The object " << ob_parent->get_object_name() << " is ready" << endl;
	}
	else
	{
		
		cout << "The object " << ob_parent->get_object_name() << " is not ready" << endl;
	}
	
	if(ob_parent->children.size() == 0) return;
	
	ob_parent->it_child = ob_parent->children.begin();
	
	while(ob_parent->it_child != ob_parent->children.end())
	{
		
		show_state_next((*(ob_parent->it_child)));
		
		ob_parent->it_child++;
	}
}

#ifndef CL_BASE_H
#define CL_BASE_H

#include <string>
#include <vector>

using namespace std;

class cl_base
{
    string s_object_name;
    cl_base* p_head_object;
    vector<cl_base*> subordinate_objects;

public:
    cl_base(cl_base* p_head_object, string s_object_name = "Base object");
    bool set_object_name(string new_name);
    string get_object_name();
    cl_base* get_head_object();
    int get_count_subordinate_objects();
    void print_tree_structure();
    cl_base* find_subordinate_by_name(string name);
    cl_base* find_subordinate_by_index(int index);
    ~cl_base();
};

#endif
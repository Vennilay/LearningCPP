#include "cl_application.h"
#include <iostream>
#include <vector>

using namespace std;

cl_application::cl_application(cl_base* p_head_obj) : cl_base(p_head_obj) {}

void cl_application::build_tree_objects()
{
    string head_name, obj_name;
    cl_base* p_current_head = this;
    cl_base* p_last_obj = nullptr;
    cin >> head_name;
    this -> set_object_name ( head_name );
    while ( cin >> head_name >> obj_name && head_name != obj_name )
    {
        if ( p_last_obj != nullptr && head_name == p_last_obj -> get_object_name()  )
        {
            p_current_head = p_last_obj;
        }

        if ( head_name == p_current_head -> get_object_name() )
        {
            if ( p_current_head -> find_subordinate_by_name( obj_name ) == nullptr )
            {
                p_last_obj = new cl_derived( p_current_head, obj_name );
            }
        }
    }
}
int cl_application::exec_app() {
    int level, index;
    string new_name;
    this -> print_tree_structure();
    while ( cin >> level && level != 0 )
    {
        cin >> index >> new_name;
        vector < cl_base * > current_level;
        current_level.push_back( this );
        for ( int i = 1; i < level ; i++ )
        {
            vector < cl_base * > next_level;
            for ( int j = 0; j < current_level.size(); j++ )
            {
                cl_base* p_head = current_level[ j ];
                for ( int k = 1; k <= p_head -> get_count_subordinate_objects(); k++)
                {
                    next_level.push_back ( p_head -> find_subordinate_by_index( k ) );
                }
            }
            current_level = next_level;
            if (current_level.size() == 0)
            {
                break;
            }
        }
        if ( index > 0 && index <= current_level.size() )
        {
            current_level[ index - 1 ] -> set_object_name( new_name );
        }
    }
    this -> print_tree_structure();
    return 0;
}
#include <iostream>
#include "S.h"
#include "C.h"

using namespace std;

int main(){
	S obj_st;
	C obj_cl;

	int val1 = 0;
	int val2 = 0;

	cin >> val1;
	cin >> val2;

	obj_st.setPrivate(val1);
	obj_cl.setPrivate(val1);

	obj_st.publicProp = val2;
	obj_cl.publicProp = val2;

	cout << "The value of the public obj_st object property = " << obj_st.publicProp << endl;
	cout << "The value of the public obj_cl object property = " << obj_cl.publicProp << endl;
	cout << "The value of the obj_st object's private property = " << obj_st.getPrivate() << endl;
	cout << "The value of the obj_cl object's private property = " << obj_cl.getPrivate() << endl;

	return 0;

}
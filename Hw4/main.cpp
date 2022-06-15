#include "hw4_lib.h"
//###########################################################################################################################################################################

int main() {

	// I tested all functions here
	
	vector<DayofYearSet::DayofYear> set1, set2, set3, set4, set5;

	DayofYearSet::DayofYear obj(1, 1);		// I created the objects that I will use for testing
	set1.push_back(obj);
	DayofYearSet::DayofYear obj2(1, 2);
	set1.push_back(obj2);

	DayofYearSet::DayofYear obj3(2, 1);
	set2.push_back(obj3);
	DayofYearSet::DayofYear obj4(1, 1);
	set2.push_back(obj4);

	DayofYearSet::DayofYear obj5(1, 1);
	set3.push_back(obj5);
	DayofYearSet::DayofYear obj6(1, 2);
	set3.push_back(obj6);

	DayofYearSet Set_obj(set1), Set_obj1(set2), Set_obj2(set3);

	cout << "\nTEST SECTION\n***********************************************************\n\n";
	
	cout << "Tested << function\n\n";
	cout <<"Set_obj Info:\n"<< Set_obj << "\nSet_obj2 Info:\n" << Set_obj1 << "\n\n";

	cout << "Tested ==,!= function\n";
	bool answer = Set_obj == Set_obj2;
	cout << Set_obj.data[0].day << " " << Set_obj.data[0].month << "\n" << Set_obj.data[1].day << " " << Set_obj.data[1].month << "\n"; // I showed bool values ​​by printing the objects
	cout << Set_obj2.data[0].day << " " << Set_obj2.data[0].month << "\n" << Set_obj2.data[1].day << " " << Set_obj2.data[1].month << "\n == Answer: ";
	cout << answer << "\n";
	bool answer2 = Set_obj != Set_obj2;
	cout << Set_obj.data[0].day << " " << Set_obj.data[0].month << "\n" << Set_obj.data[1].day << " " << Set_obj.data[1].month << "\n";
	cout << Set_obj2.data[0].day << " " << Set_obj2.data[0].month << "\n" << Set_obj2.data[1].day << " " << Set_obj2.data[1].month << "\n != Answer:";
	cout << answer2 << "\n\n";

	cout << "Tested Add function\n";
	cout << Set_obj.data[0].day << " " << Set_obj.data[0].month << "\n" << Set_obj.data[1].day << " " << Set_obj.data[1].month << "\nAdded state (object(2,1)):\n";
	add(Set_obj, obj3);  // (Set_obj=1,1 1,2   obj3=2,1
	cout << Set_obj.data[0].day << " " << Set_obj.data[0].month << "\n" << Set_obj.data[1].day << " " << Set_obj.data[1].month << "\n" << Set_obj.data[2].day << " " << Set_obj.data[2].month;

	cout << "\n\nTested Remove function\n";
	cout << Set_obj.data[0].day << " " << Set_obj.data[0].month << "\n" << Set_obj.data[1].day << " " << Set_obj.data[1].month << "\nRemoved state (object(1,2))\n";
	remove(Set_obj, obj2);  // (Set_obj=1,1 1,2   obj2=1,2
	cout << Set_obj.data[0].day << " " << Set_obj.data[0].month << "\n";
	cout << "We can understand from these garbage values that there is no continuation of the values:" << Set_obj.data[1].day << " " << Set_obj.data[1].month << "\n\n";

	cout << "Tested Size Function\n";
	int size_test = size(Set_obj);
	cout << size_test << "\n\n";

	cout << "Static Function Test:\n";
	DayofYearSet test_static;
	cout <<"Objects created "<< test_static.num<<" times\n\n";

	cout << "Tested Operator +\n";
	cout << "Object 1:\n" << Set_obj1.data[0].day << " " << Set_obj1.data[0].month << "\n" << Set_obj1.data[1].day << " " << Set_obj1.data[1].month << "\n";
	cout << "Object 2:\n" << Set_obj2.data[0].day << " " << Set_obj2.data[0].month << "\n" << Set_obj2.data[1].day << " " << Set_obj2.data[1].month << "\n";
	DayofYearSet Set_objTest = Set_obj1 + Set_obj2;
	cout << "Mergeted:\n" << Set_objTest.data[0].day << " " << Set_objTest.data[0].month << "\n" << Set_objTest.data[1].day << " " << Set_objTest.data[1].month << "\n"
		<< Set_objTest.data[2].day << " " << Set_objTest.data[2].month << "\n\n";

	cout << "Tested Operator -\n";
	cout << "Object 1:\n" << Set_obj1.data[0].day << " " << Set_obj1.data[0].month << "\n" << Set_obj1.data[1].day << " " << Set_obj1.data[1].month << "\n";
	cout << "Object 2:\n" << Set_obj2.data[0].day << " " << Set_obj2.data[0].month << "\n" << Set_obj2.data[1].day << " " << Set_obj2.data[1].month << "\n";
	DayofYearSet Set_objTest2 = Set_obj1 - Set_obj2;
	cout << "Difference Set (Object1/Object2):\n" << Set_objTest2.data[0].day << " " << Set_objTest2.data[0].month << "\n\n";

	cout << "Tested Operator [] \n";
	DayofYearSet::DayofYear test;
	cout << "Element we access manually\n" << Set_objTest2[0].day << " " << Set_objTest2[0].month << "\n";
	test = Set_objTest2[0];
	cout << "The element we access using the [] operator\n" << test.day << " " << test.month << "\n\n";

	cout << "De Morgan Test With ! and ^ Operators:\n";
	DayofYearSet Xor = !Set_obj1;
	DayofYearSet Xor2 = !Set_obj2;
	DayofYearSet test3 = Xor ^ Xor2;
	DayofYearSet sum = Set_obj1 + Set_obj2;
	DayofYearSet Xor3 = !sum;
	if (test3 == Xor3)
		cout << "De Morgan says !(Set_obj+Set_obj2) = !Set_obj ^ !Set_obj2 \n\n";
	else
		cout << "This statement is also not in accordance with Morgan's rule.\n\n";


	cout << "***********************************************************\nTest Ended...\n";
}
	
	



#include "Table.h"

int main(){
	//String Parameter
    Table stringParameter(L"stringParameter");
    stringParameter.add<int>({1,2,3,4});
    stringParameter.add<double>({1.1,2.2,3.1,4.1});
    stringParameter.add<std::wstring>({L"lalal", L"te egene?",L"tzertzelos",L"AString!"});

    Object o;
    o.t = Object::ObjectType::STRING;
    o.str = L"babouska";
    stringParameter.addValue(&o);
    stringParameter.dump();

	//Numeric Parameter, storage type: double
    Table numericParameter(L"NumericParameter");
    numericParameter.add<int>({5,6,7,8});
    numericParameter.add<double>({1.12,2.22,3.12,4.12});
    numericParameter.add<std::wstring>({L"lalal", L"te egene?",L"tzertzelos",L"AString!"});

    Object o2;
    o2.t = Object::ObjectType::DOUBLE;
    o2.d = 1.3334;
    numericParameter.addValue(&o2);

    o2.d = 1.3335;
    numericParameter.addValue(&o2);
    numericParameter.dump();


    Table nullParameter(L"NullParameter");
    nullParameter.dump();
    return 0;
}
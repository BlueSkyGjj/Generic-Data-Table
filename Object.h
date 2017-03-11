#include <string>

typedef struct Object{
	enum ObjectType{
		INT,
		DOUBLE,
		STRING,
		ALL
	};
	ObjectType t;
    std::wstring str;
    int i;
    double d;
} Object;

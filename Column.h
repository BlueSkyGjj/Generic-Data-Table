#include <vector>
#include <iostream>
#include <memory>
#include "Object.h"

class Column{
public:
	virtual ~Column(){}
    virtual void add(Object *) = 0;
    virtual void dump() = 0;
    virtual int size() = 0;
};

template <class T>
class DataColumn : public Column{
    std::vector<T> values;
    public:
    	DataColumn():values({}){}
    	virtual ~DataColumn(){}
    	virtual void add(Object*) override;

    	void add(std::vector<T> v){
	        for(int i = 0;i<v.size();i++){
                values.push_back(v[i]);
	        }
    	}

    	virtual void dump() override{
    		for(auto &k : values){
    			std::wcout << "* " << k << std::endl;
    		}
            std::wcout << std::endl;
    	}

        virtual int size() override {return values.size();}
};

template<>
void DataColumn<int>::add(Object* o){
    values.push_back(o->i);
}

template<>
void DataColumn<std::wstring>::add(Object* o){
    values.push_back(o->str);	
}

template<>
void DataColumn<double>::add(Object* o){
	 values.push_back(o->d);
}
#include "Column.h"

class DataColumnFactory{
public:
    template<typename T>
    static std::unique_ptr<DataColumn<T>> getColumn(){
         std::unique_ptr<DataColumn<T>> column(new DataColumn<T>);
         return std::move(column);
    }

    static std::unique_ptr<Column> getColumnByType(Object* o){
        if(!o) return nullptr;
        switch(o->t){
            case Object::ObjectType::INT:{
                return std::move ( DataColumnFactory::getColumn<int>() );
            }
            case Object::ObjectType::DOUBLE:{
                return std::move ( DataColumnFactory::getColumn<double>() );
            }
            case Object::ObjectType::STRING:{
                return std::move ( DataColumnFactory::getColumn<std::wstring>() );
            }
            default: break;
        }
        return nullptr;
    }
};

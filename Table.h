#include "DataColumnFactory.h"
#include <assert.h>

class Table{
	using ColumnRsrc = std::unique_ptr<Column>;

    std::vector<ColumnRsrc> m_Columns;
    ColumnRsrc m_Value;
    std::wstring m_Name;

	public:
	Table(const std::wstring& name):m_Name(name){}
	~Table(){}

    template <typename T>
    void add(std::vector<T> t) {

        auto column = DataColumnFactory::getColumn<T>();
        column.get()->add(t);
        m_Columns.push_back(std::move(column) );
    }

    void addValue(Object* o){
        if(!o) return;
        if(!m_Value.get() ){
            m_Value = DataColumnFactory::getColumnByType(o);
        }            
        assert(m_Value.get());
        m_Value.get()->add(o);
    }

    void dump(){
        dumpTableGeneralInfo();

        int i = 0;
    	for(auto &column : m_Columns){
            std::wcout << "Column #" << ++i << std::endl;
    		column.get()->dump();
    	}

        if(m_Value.get()){
            std::wcout << "Column #" << ++i << std::endl;
            m_Value.get()->dump();
        }
    }

private:
    void dumpTableGeneralInfo(){
        std::wcout << "Table " << m_Name << " => ";
        std::wcout << m_Columns.size() + (m_Value.get() ? 1 : 0) << " X ";
        if(m_Columns.size()) std::wcout << m_Columns[0].get()->size() << std::endl;
        std::wcout << "Cells =>" << getCellNumber() << std::endl;
    }

    int getCellNumber(){
        int sum = 0;
        for(auto &column : m_Columns) sum += column.get()->size();
        if(m_Value.get()) sum += m_Value.get()->size();
        return sum;
    }
};
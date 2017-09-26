#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
//#include <initializer_list>

namespace Json_Rossi
{

	class JsonValue;

	class Json
	{
		enum Type
		{
			ETYPE_NUL = 0,
			ETYPE_NUMBER = 1,
			ETYPE_BOOL = 2,
			ETYPE_STRING = 3,
			ETYPE_ARRAY = 4,
			ETYPE_OBJ = 5,
		};
		typedef std::vector<Json> array;
		typedef std::map<std::string, Json> object;
	public:
		Json() noexcept;						//NULL
		Json(std::nullptr_t) noexcept;			//NULL
		Json(double _value);					//double
		Json(bool _value);						//bool
		Json(const std::string& _value);		//string
		Json(std::string _value);				//string
		Json(const char* _value);				//stirng
		Json(const array& _value);				//array
		Json(array&& _value);					//array
		Json(const object& _value);				//object
		Json(object&& _value);					//object

		~Json();

		Type type() const;

		bool isNull() const
		{
			return type() == ETYPE_NUL;
		}
		bool isNummber() const
		{
			return type() == ETYPE_NUMBER;
		}
		bool isBool() const
		{
			return type() == ETYPE_BOOL;
		}
		bool isString() const
		{
			return type() == ETYPE_STRING;
		}
		bool isObject() const
		{
			return type() == ETYPE_OBJ;
		}

	private:
		std::shared_ptr<JsonValue> m_ptr;
	};

	class JsonValue
	{
	protected:
		friend class Json;

	};
}	//namespace Json_Rossi

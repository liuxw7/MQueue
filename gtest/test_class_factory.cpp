#include <iostream>
#include "MQPool/logobj.h"
#include "MQPool/parse_json.h"
#include "MQPool/parse_json.h"
#include "MQPool/class_factory.h"

using namespace std;

//由于logobj没有实现自己的无参构造函数,所以这里的话我用parse_json来做示范

DECLARE_CLASS_CREATE(ParseJsonObj);
IMPL_CLASS_CREATE(ParseJsonObj);

int main() {
  //这个string可以直接从配置文件当中读取出来
  string class_name = "ParseJsonObj";

  if (class_name == "") {

  } else if(class_name == "ParseJsonObj") {
    ParseJsonObj* myjson = (ParseJsonObj*)ClassFactory::Instance().GetObject("ParseJsonObj");
	vector<map<string, string> > result_array = myjson->GetChildDataArray("Config.Server.Connection");
	for (auto key_value_map : result_array) {
	  for (auto the_pair : key_value_map) {
	    cout << the_pair.first << "---" << the_pair.second << endl;
	  }
	}
	delete myjson;
  } else if (class_name == "ParseXmlObj") {

  } else if (class_name == "LogObj") {

  }

  return 0;
}

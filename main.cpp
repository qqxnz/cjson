#include <QCoreApplication>
#include <QtDebug>
#include <cJSON.h>
#include   <iostream>
#include <string>
using   namespace   std   ;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    ///生成json

    cJSON * usr;

    usr=cJSON_CreateObject();   //创建根数据对象
    cJSON_AddStringToObject(usr,"name","fengxin");  //加入键值，加字符串
    cJSON_AddStringToObject(usr,"passwd","123");
    cJSON_AddNumberToObject(usr,"num",1);  //加整数


    char *out = cJSON_Print(usr);   //将json形式打印成正常字符串形式


    qDebug() << out << endl;



    ////json解析

    char * jsonStr = "{\"semantic\":{\"slots\":{\"name\":\"张三\"}}, \"rc\":0, \"operation\":\"CALL\", \"service\":\"telephone\", \"text\":\"打电话给张三\"}";
      cJSON * root = NULL;
      cJSON * item = NULL;//cjson对象

      root = cJSON_Parse(jsonStr);
      if (!root)
      {
          printf("Error before: [%s]\n",cJSON_GetErrorPtr());
      }
      else
      {

//          qDebug() << cJSON_Print(root) << endl;


          item = cJSON_GetObjectItem(root, "service");

//          qDebug() << cJSON_Print(item) << endl;

          string str ;

          str = cJSON_Print(item);

          cout << "字符串显示：" << str << endl;

          cout << "字符串显示：" << str.size() << endl;







//          printf("%s\n", "有格式的方式打印Json:");
//          printf("%s\n\n", cJSON_Print(root));
//          printf("%s\n", "无格式方式打印json：");
//          printf("%s\n\n", cJSON_PrintUnformatted(root));

//          printf("%s\n", "一步一步的获取name 键值对:");
//          printf("%s\n", "获取semantic下的cjson对象:");
//          item = cJSON_GetObjectItem(root, "semantic");//
//          printf("%s\n", cJSON_Print(item));
//          printf("%s\n", "获取slots下的cjson对象");
//          item = cJSON_GetObjectItem(item, "slots");
//          printf("%s\n", cJSON_Print(item));
//          printf("%s\n", "获取name下的cjson对象");
//          item = cJSON_GetObjectItem(item, "name");
//          printf("%s\n", cJSON_Print(item));

//          printf("%s:", item->string);   //看一下cjson对象的结构体中这两个成员的意思
//          printf("%s\n", item->valuestring);


//          printf("\n%s\n", "打印json所有最内层键值对:");
      }



    return a.exec();
}

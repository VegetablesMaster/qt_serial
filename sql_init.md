#### 添加ODBC数据源，在控制面板中找到管理工具，其中有ODBC数据源,我用的是64位的，打开后添加
```
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
```
![image](jpg/db_init_config.jpg)
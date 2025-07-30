#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>


int main(){

//structurs provided for mysql topics

MYSQL *conn;
MYSQL_RES *res; 
MYSQL_ROW row;
conn = mysql_init(NULL);
if (conn == NULL) {
    fprintf(stderr, "mysql_init() failed\n");
    return EXIT_FAILURE;
}

if(mysql_real_connect(conn, "localhost", "root","password","tflmentoringdb",0,NULL,0) == NULL) {
    fprintf(stderr, "mysql_real_connect() failed\n");
    mysql_close(conn);
    return EXIT_FAILURE;
}


//SQL query to create a table
//SELCT * from topics;
if (mysql_query(conn, "SELECT * FROM topics")) {
    fprintf(stderr, "SELECT * FROM topics failed. Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    return EXIT_FAILURE;
}

//retrive the result set
res = mysql_store_result(conn);

while((row = mysql_fetch_row(res)) != NULL) {
    printf("\n ID: %s, Title: %s, URL: %s\n", row[0], row[1], row[2]);
}

//clean up
mysql_free_result(res);
mysql_close(conn);
return EXIT_SUCCESS;
}


//gcc .\mysqltopicsdb.c -o db.exe -I "C:\Program Files\MySQL\MySQL Server 8.4\include" -L "C:\Program Files\MySQL\MySQL Server 8.4\lib" -l libmysql

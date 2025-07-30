#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>

int main()
{
    MYSQL *conn;
    char query[500];
    int id;
    char title[200];
     char url[200];

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
 printf("Enter ID you want to delete: ");
    scanf("%d", &id);

    sprintf(query, "DELETE FROM topics WHERE id = %d", id);

if(mysql_query(conn,query))
{
    printf("INSERT Failed: %s\n",mysql_error(conn));
    mysql_close(conn);
    return 1;
}
mysql_close(conn);
return 0;
}
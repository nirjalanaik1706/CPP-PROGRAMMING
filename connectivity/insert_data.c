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
printf("Enter ID you want to insert:\n");
    scanf("%d", &id);
    getchar(); // Clear newline left by scanf

    printf("Enter Title you want to insert:\n");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';  // Remove newline

    printf("Enter URL you want to insert:\n");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';  // Remove newline

    // Create and run the INSERT query
    sprintf(query, "INSERT INTO topics (id, title, url) VALUES (%d, '%s', '%s')", id, title, url);
if(mysql_query(conn,query))
{
    printf("INSERT Failed: %s\n",mysql_error(conn));
    mysql_close(conn);
    return 1;
}
mysql_close(conn);
return 0;
}
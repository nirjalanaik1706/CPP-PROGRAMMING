#include <iostream>
#include <mysql.h>
#include <cstring>

using namespace std;

int main() {
    MYSQL* conn;
    char query[500];
    int id;
    char title[100], url[200];

    conn = mysql_init(NULL);
    if (conn == NULL) {
        cout << "mysql_init() failed" << endl;
        return 1;
    }

    // Connect to MySQL
    if (mysql_real_connect(conn, "localhost", "root", "password", "tflmentoringdb", 0, NULL, 0) == NULL) {
        cout << "Connection failed: " << mysql_error(conn) << endl;
        mysql_close(conn);
        return 1;
    }

    // Get user input
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(); // clear newline

    cout << "Enter Title: ";
    cin.getline(title, sizeof(title));

    cout << "Enter URL: ";
    cin.getline(url, sizeof(url));

    // Format INSERT query
    sprintf(query, "INSERT INTO topics (id, title, url) VALUES (%d, '%s', '%s')", id, title, url);

    // Execute query
    if (mysql_query(conn, query)) {
        cout << "INSERT failed: " << mysql_error(conn) << endl;
        mysql_close(conn);
        return 1;
    }

    cout << "✅ Record inserted successfully." << endl;

    mysql_close(conn);
    return 0;
}

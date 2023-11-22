#!/bin/env python3
#
#
#
#
#
import pymysql.cursors
import cgitb
import cgi
import sys
cgitb.enable()

# Make the connection
DBHOST = 'cs3103.cs.unb.ca'
DBUSER = 'mmoustaf'
DBPASSWD = '4MJHyMN1'
DBDATABASE ='mmoustaf'
dbConnection = pymysql.connect(DBHOST,
                                        DBUSER,
                                        DBPASSWD,
                                        DBDATABASE,
                                        charset='utf8mb4',
                                        cursorclass= pymysql.cursors.DictCursor)

sql = "getquote"
# http headers
print ('Content-type: text/html')
print ()

# Run query and get result

print('<!DOCTYPE html>')
print('<head>\n\t<title>Get a Quote</title>\n\t<meta charset="utf-8">\n</head>')
print('<body>')
try:
        cursor = dbConnection.cursor()
        cursor.callproc(sql)
        results = cursor.fetchall()
        for row in results:
                print("<tr><td>Quote: {quote}</td></tr>".format(**row) )

except pymysql.MySQLError as e:
        print('<p>Ooops - Things messed up: </p>')
except Exception as e:
        print('<p>Something big went wrong.</p>')
        print(e)

print('</body>\n</html>')

cursor.close()
dbConnection.close()

#End

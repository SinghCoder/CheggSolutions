import sqlite3
import pandas as pd
conn = sqlite3.connect('chegg.db')

c = conn.cursor()

# # Create table
# c.execute('''CREATE TABLE Publisher
#     (name varchar(10) primary key, phone varchar(10), address varchar(8))
# ;''')

# # Insert a row of data
# c.execute('''INSERT INTO Publisher
#     (name, phone, address)
# VALUES
#     ('publisher1', 8888888888, 'address1'),
#     ('publisher2', 8888888887, 'address2'),
#     ('publisher3', 8888888886, 'address3'),
#     ('publisher4', 8888888885, 'address4')
# ;''')

# c.execute('''CREATE TABLE Book
#     (ISBN varchar(5) primary key, title varchar(6), year int, published_by varchar(10) , previous_edition varchar(5), foreign key (previous_edition) references Book(ISBN), foreign key (published_by) references Publisher(name))
# ;''')
c.execute('''DELETE FROM Book''')
c.execute('''INSERT INTO Book
    (ISBN, title, year, published_by, previous_edition)
VALUES
    ('isbn1', 'title1', 2000, 'publisher1', NULL),
    ('isbn2', 'title2', 2001, 'publisher2', NULL),
    ('isbn3', 'title3', 2002, 'publisher3', 'isbn2'),
    ('isbn4', 'title4', 2003, 'publisher1', 'isbn1'),
    ('isbn5', 'title5', 2004, 'ABC', NULL),
    ('isbn6', 'title6', 2005, 'ABC', NULL),
    ('isbn7', 'title7', 2006, 'ABC', NULL),
    ('isbn8', 'title8', 2007, 'ABC', NULL)
;
''')
# c.execute('''CREATE TABLE Author
#     (SSN varchar(4) primary key, first_name varchar(6), last_name varchar(6), address varchar(8), income int)
# ;''')
# c.execute('''INSERT INTO Author
#     (SSN, first_name, last_name, address, income)
# VALUES
#     ('ssn1', 'fname1', 'lname1', 'address1', 99999),
#     ('ssn2', 'fname2', 'lname2', 'address2', 99999),
#     ('ssn3', 'fname3', 'lname3', 'address3', 99999),
#     ('ssn4', 'fname4', 'lname4', 'address4', 99999)
# ;''')
# c.execute('''CREATE TABLE Write
#     (aSSN varchar(4) , bISBN varchar(5) ,constraint pk_ssn_isbn primary key(aSSN, bISBN), foreign key (aSSN) references Author(SSN), foreign key (bISBN) references Book(ISBN))
# ;''')
# c.execute('''INSERT INTO Write
#     (aSSN, bISBN)
# VALUES
#     ('ssn1', 'isbn1'),
#     ('ssn2', 'isbn2'),
#     ('ssn3', 'isbn3'),
#     ('ssn1', 'isbn4')
# ;''')
# c.execute('''CREATE TABLE Author_Editor
#     (aeSSN varchar(4) primary key , works_for varchar(11), foreign key (aeSSN) references Author(SSN), foreign key (works_for) references Publisher(name))
# ;''')
# c.execute('''INSERT INTO Author_Editor
#     (aeSSN, works_for)
# VALUES
#     ('ssn1', 'publisher_1'),
#     ('ssn2', 'publisher_2'),
#     ('ssn3', 'publisher_3'),
#     ('ssn4', 'publisher_4')
# ;''')
print('-----------------------Publisher-----------------------')
print(pd.read_sql_query("SELECT * FROM Publisher", conn))
print('-------------------------------------------------------')
print('-------------------------Book--------------------------')
print(pd.read_sql_query("SELECT * FROM Book", conn))
print('-------------------------------------------------------')
print('------------------------Author-------------------------')
print(pd.read_sql_query("SELECT * FROM Author", conn))
print('-------------------------------------------------------')
print('-------------------------Write-------------------------')
print(pd.read_sql_query("SELECT * FROM Write", conn))
print('-------------------------------------------------------')
print('---------------------Author_Editor---------------------')
print(pd.read_sql_query("SELECT * FROM Author_Editor", conn))
print('-------------------------------------------------------')
print('------------------------Query1-------------------------')
print(pd.read_sql_query("SELECT ISBN FROM Book b_second WHERE published_by != (SELECT published_by FROM Book b_first WHERE b_first.ISBN = b_second.previous_edition)", conn))
print('-------------------------------------------------------')
print('------------------------Query2-------------------------')
print(pd.read_sql_query("SELECT title FROM Book WHERE published_by='ABC' ORDER BY year LIMIT 1", conn))
print('-------------------------------------------------------')

# c.execute('''SELECT * FROM Publisher''')
# c.execute('''SELECT * FROM Book''')
# c.execute('''SELECT * FROM Author''')
# c.execute('''SELECT * FROM Write''')
# c.execute('''SELECT * FROM Author_Editor''')

# Save (commit) the changes
conn.commit()

# We can also close the connection if we are done with it.
# Just be sure any changes have been committed or they will be lost.
conn.close()
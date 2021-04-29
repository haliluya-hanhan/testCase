//check type:cpp 
#include<iostream>
using namespace std;

class Document_R_2_8_1
{
public:
    Document_R_2_8_1(void) : docid(0)
        {

        }
    int get_docid(void);
private:
    int docid;
};
int Document_R_2_8_1::get_docid(void)
{
    return docid;
}
class Book_R_2_8_1 : public Document_R_2_8_1
{
public:
    Book_R_2_8_1(void) : Document_R_2_8_1(),bookid(0)
    {

    }
    int get_bookid(void);
private:
    int bookid;
};
int Book_R_2_8_1::get_bookid()
{
    return bookid;
}
int func_GJB_R_02_08_01_basic_01_bad()
{
    Book_R_2_8_1 book;
    try{
        throw book;
    }
    catch(Document_R_2_8_1 &d)
    {
        cout << d.get_docid() <<endl;
    }
    catch(Book_R_2_8_1 &b)                      //not compliant
    {
        cout<< b.get_bookid() <<endl;
    }
    return 0;
}

/*good example*/
int func_GJB_R_02_08_01_basic_01_good()
{
    Book_R_2_8_1 book;
    try{
        throw book;
    }
    catch(Book_R_2_8_1 &d)                  //ok
    {
        cout << d.get_bookid() <<endl;
    }
    catch(Document_R_2_8_1 &b)                      //ok
    {
        cout<< b.get_docid() <<endl;
    }
    return 0;
}

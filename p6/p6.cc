#include "table.h"
#include "word.h"
#include "key.h"

void testRek();
void testTable();
void testConst(const Table &t,const Word & w);

int main(){
  testRek();
  testTable();
}

void testRek(){
  cout<<"------testRek()-----\n";
  Rek t(Key("one"),9),u(Key("Three"),4),v(u);
  Rek w("Five",999);  //Tricky code! First arg of Rek()
                      //expects an instance of Key, but
                      //sees a char*  However, Key has a constructor that
                      // accepts c-strings: e.g., Key("Five"), so "Five" is
                      // promoted (coreced) to Key("Five") 
  cout<<t.getKey()<<endl;
  v.data=99;
  cout<<t<<u<<v<<endl;
  cout<<w<<endl;
};

void testTable(){
  cout<<"\n\n------testTable()-----\n";
  Table t(18);
  t["One"]=2;//Tricky code! [] expects an instance of Key, but
             //sees a char*  However, Key has a constructor that
             // accepts c-strings: e.g., Key("One"), so "One" is
             // promoted (coreced) to Key("One")
  t["two"]=1;
  t["two"] = 5;
  cout<<t<<endl;

  const char *h[]={"able","baker","charley","one","two","three","four",
	     "five","six","seven","eight","nine","ten"};
  int n[]={2,6,7,5,-9,3,84,99,22,7,8,9,65};
  Table hn(10);//size of actual hash table will be 11 (prime)
  for(int j=0;j<13;j++)
    hn[h[j]]=n[j]; 
  cout<<hn;
  cout<<"Expect 10: "<<hn.inTable("baker")<<hn.inTable("junko")<<endl;
  testConst(hn,"seven"); // "seven" gets promoted to Word("seven")
}

void testConst(const Table &t,const Word &w){
  cout<<"t[\""<<w<<"\"] = "<< t[w]<<endl;  //w gets promoted to Key(w)
  cout<<t["junk==>crash"]<<endl;
}

/*******************************OUTPUT
------testRek()-----
[one, 1143522]
{[one, 1143522], 9}{[Three, 259463612], 4}{[Three, 259463612], 99}
{[Five, 73204194], 999}


------testTable()-----

-------------------------
4   {[two, 1195446], 1}
14   {[One, 817090], 2}
-------------------------
There are 2 entries, requiring an average of 1 looks to find
----------------------


-------------------------
0   {[five, 106173826], 99}--->{[baker, 1709025725], 6}--->{[able,
100949904], 2}
1   {[seven, 812681343], 7}
2   {[four, 106234944], 84}
3   {[charley, 691393244], 7}
4   {[nine, 114415426], 9}
5   {[eight, 2029408837], 8}
6   {[ten, 1193627], 65}--->{[one, 1143522], 5}
8   {[three, 705570852], 3}
9   {[six, 1183840], 22}
10   {[two, 1195446], -9}
-------------------------
There are 10 entries, requiring an average of 1.3 looks to find
----------------------
Expect 10: 10
t["seven"] = 7
Error[Table]: Missing key
*********************************END OF OUTPUT*/

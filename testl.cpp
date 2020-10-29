#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
  string name;
  string uniqname;
  Job job;
};

int main() {

  Dlist<Record*> dlist1; 

  Record *r1 = new Record;
  r1->name = "Andrew DeOrio";
  r1->uniqname = "awdeorio";
  r1->job = FACULTY;

  Record *r2 = new Record;
  r2->name = "Terry";
  r2->uniqname = "tbear";
  r2->job = STAFF;

  Record *r3 = new Record;
  r3->name = "jimmy";
  r3->uniqname = "jimbo";
  r3->job = STUDENT;

  dlist1.InsertFront(r1);
  dlist1.InsertFront(r2);
  dlist1.InsertFront(r3);

  Dlist<Record*> copy(dlist1);

  while(!dlist1.IsEmpty()) {
    Record *r = dlist1.RemoveFront();
    cout << r->uniqname << "\n";
    delete r;
  }
  while(!copy.IsEmpty()) {
    Record *r = copy.RemoveFront();
    cout << r->uniqname << "\n";
    delete r;
  }


  return 0;
}

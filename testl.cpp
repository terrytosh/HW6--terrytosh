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

  Dlist<Record*> catsweb; //records are big, so store pointer

  Record *p = new Record;
  p->name = "Andrew DeOrio";
  p->uniqname = "awdeorio";
  p->job = FACULTY;

  Record *l = new Record;
  l->name = "Terry";
  l->uniqname = "tbear";
  l->job = STAFF;

  if (catsweb.IsEmpty()) {
    std::cout << "Empty\n";
  }
  else {
    std::cout << "Not empty\n";
  }
  catsweb.InsertBack(p);
  if (catsweb.IsEmpty()) {
    std::cout << "Empty\n";
  }
  else {
    std::cout << "Not empty\n";
  }
  catsweb.InsertFront(l);

  Dlist<Record*> copy(catsweb);

  // do something with "catsweb"

  // don't forget to delete objects on the heap
  while ( !catsweb.IsEmpty() ) {
    Record *r = catsweb.RemoveFront();
    cout << r->uniqname << endl;
    delete r;
  }
  try {
    Record *temp = catsweb.RemoveFront();
  }
  catch (emptyList e) {
    cout << "Can't remove from empty list\n";
  }
  while ( !copy.IsEmpty() ) {
    Record *r = copy.RemoveFront();
    cout << r->uniqname << endl;
    delete r;
  }

  return 0;
}

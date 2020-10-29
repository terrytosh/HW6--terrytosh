#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:

  // Operational methods

  bool IsEmpty() const;
  // EFFECTS: returns true if list is empty, false otherwise

  void InsertFront(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the front of the list
    
  void InsertBack(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the back of the list

  T RemoveFront();
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
  //         throws an instance of emptyList if empty

  T RemoveBack();
  // MODIFIES this
  // EFFECTS removes and returns last object from non-empty list
  //         throws an instance of emptyList if empty

  // Maintenance methods
  Dlist();                                   // ctor
  Dlist(const Dlist &l);                     // copy ctor
  Dlist &operator=(const Dlist &l);          // assignment
  ~Dlist();                                  // dtor

 private:
  // A private type
  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  node   *first; // The pointer to the first node (0 if none)
  node   *last;  // The pointer to the last node (0 if none)
  //How us this different than the doubly linked list in class?

  // Utility methods

  void MakeEmpty();
  // EFFECT: called by constructors to establish empty
  // list invariant
    
  void RemoveAll();
  // EFFECT: called by destructor and operator= to remove and destroy
  // all list nodes

  void CopyAll(const Dlist &l);
  // EFFECT: called by copy constructor/operator= to copy nodes
  // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/

//Default constructor
template <class T>
Dlist<T>::Dlist() {
  first = nullptr;
  last = nullptr;
}

//Copy constructor
template <class T>
Dlist<T>::Dlist(const Dlist &l) {
  CopyAll(l);
}

//Assignment operator
template <class T>
Dlist<T>& Dlist<T>::operator=(const Dlist &l) {
  //create new Dlist as copy of l and return it
}

//Utility methods
template <class T>
void Dlist<T>::MakeEmpty() {
  while (first != nullptr) {
     node *toDelete = first;
     first = first->next;
     delete toDelete;
   }
  first = nullptr;
  last = nullptr;
}

template <class T>
void Dlist<T>::CopyAll(const Dlist &l) {
  first = nullptr;
  last = nullptr;
  if (l.first) {
    first = new node(*l.first);
    last = first;
    while (last->next != nullptr) {
      last = last->next;
    }
  }
}

template <class T>
void Dlist<T>::RemoveAll() {
  while (first != nullptr) {
    node *toDelete = first;
    first = first->next;
    delete toDelete;
  }
}

//Class methods
template <class T>
bool Dlist<T>::IsEmpty() const {
  return (first == nullptr && last == nullptr);
}

template <class T>
void Dlist<T>::InsertFront(const T &o) {
  node *newNode = new node;
  newNode->o = o;
  newNode->prev = nullptr;
  if (IsEmpty()) {
    newNode->next = nullptr;
    first = newNode;
    last = newNode;
   }
   else {
     newNode->next = first;
     first->prev = newNode;
     first = newNode;
   }
 }

template <class T>
void Dlist<T>::InsertBack(const T &o) {
  node *newNode = new node;
  newNode->o = o;
  newNode->next = nullptr;
  if (IsEmpty()) {
    newNode->prev = nullptr;
    first = newNode;
    last = newNode;
  }
  else {
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
  }
}

template <class T>
T Dlist<T>::RemoveFront() {
  if (IsEmpty()) {
    emptyList e;
    throw e;
  }
  else {
    node *newHead = first->next;
    node *toReturn = first;
    toReturn->next = nullptr;
    toReturn->prev = nullptr;
    if (newHead == nullptr) {
      first = nullptr;
      last = nullptr;
    }
    else {
      first = newHead;
      first->prev = nullptr;
    }
    return toReturn->o;
  }
}

template <class T>
T Dlist<T>::RemoveBack() {
  if (IsEmpty()) {
    emptyList e;
    throw e;
  }
  else {
    node *newTail = last->prev;
    node *toReturn = last;
    toReturn->next = nullptr;
    toReturn->prev = nullptr;
    if (newTail == nullptr) {
      first = nullptr;
      last = nullptr;
    }
    else {
      last = newTail;
      last->next = nullptr;
    }
    return toReturn->o;
  }
}
 
 //Destructor
 template <class T>
 Dlist<T>::~Dlist() {
  RemoveAll();
  delete first;
  delete last;
 }

/* this must be at the end of the file */
#endif /* __DLIST_H__ */

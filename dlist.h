#ifndef __DLIST_H__
#define __DLIST_H__
//Pseudocode is commented above functions/methods/constru/destruc

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

//Default constructor, initalize empty list
template <class T>
Dlist<T>::Dlist() {
  MakeEmpty();
}

//Copy constructor, intialize empty list then copy
//all contents of source &l to new object
template <class T>
Dlist<T>::Dlist(const Dlist &l) {
  MakeEmpty();
  CopyAll(l);
}

//Assignment operator, if the current object isn't l,
//then RemoveAll current nodes and copy all contents
//of source &l to object, return pointer to this object
template <class T>
Dlist<T>& Dlist<T>::operator=(const Dlist &l) {
  if (this != &l) {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

//Utility methods
//Initialize empty list
template <class T>
void Dlist<T>::MakeEmpty() {
  first = nullptr;
  last = nullptr;
}

//Initalize empty list, set a temp node = l.first
//while (temp): insert new node at the back of the list
//and proceed to next node
template <class T>
void Dlist<T>::CopyAll(const Dlist &l) {
  first = nullptr;
  last = nullptr;
  node *temp = l.first;
  while (temp != nullptr) {
    InsertBack(temp->o);
    temp = temp->next;
  }
}

//while(first): temporarily store current node,
//advance first to next node, delete temp node
template <class T>
void Dlist<T>::RemoveAll() {
  while (first != nullptr) {
    node *toDelete = first;
    first = first->next;
    delete toDelete;
  }
  MakeEmpty();
}

//Class methods
//Return true if first && last are nullptr,
//else return false
template <class T>
bool Dlist<T>::IsEmpty() const {
  return (first == nullptr && last == nullptr);
}

//Create a new node, insert it's data and set prev to nullptr
//If empty list: set nodes next to nullptr, set first and last
//to new node
//Else: set new nodes next to first, set first->prev to new node
//and set first to new node
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

//Create a new node, insert it's data and set next to nullptr
//If empty list: set nodes prev to nullptr, set first and last
//to new node
//Else: set new nodes prev to last, set first->next to new node
//and set last to new node
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

//If empty list: declare emptyList and throw the error
//Else: declare newHead = first->next, toReturn = first,
//and set toReturn next & prev to nullptr
//If (newHead is nullptr): set first & last to nullptr
//Else: set first to newHead and first->prev to nulltpr
//Return the data in toReturn
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

//If empty list: declare emptyList and throw the error
//Else: declare newTail = last->prev, toReturn = last,
//and set toReturn next & prev to nullptr
//If (newTail is nullptr): set first & last to nullptr
//Else: set last to newTail and last->next to nulltpr
//Return the data in toReturn
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
 //Call remove all to destroy all objects nodes
 template <class T>
 Dlist<T>::~Dlist() {
  RemoveAll();
 }

/* this must be at the end of the file */
#endif /* __DLIST_H__ */

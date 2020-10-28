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
  //How is this different than the doubly linked list in class?

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
   while (first != nullptr) {
     node *toDelete = first;
     first = first->next;
     delete toDelete;
   }
   first = nullptr;
   last = nullptr;
 }

//Copy constructor
 template <class T>
 Dlist<T>::Dlist(const Dlist &l) {
   //copy to l, delete original list
 }

 //Assignment operator
 template <class T>
 Dlist<T>& Dlist<T>::operator=(const Dlist &l) {
   //copy to l, original list unaffected
 }

//Utility methods
template <class T>
void Dlist<T>::MakeEmpty() {
  while (first != nullptr) {
     node *toDelete = first;
     first = first->next;
     delete toDelete;
   }
}

template <class T>
void Dlist<T>::CopyAll(const Dlist &l) {

}

 template <class T>
 void Dlist<T>::RemoveAll() {
   while (first != nullptr) {
     node *toDelete = first;
     first = first->next;
     delete toDelete;
   }
   delete first;
   delete last;
 }

//Class methods
 template <class T>
 bool Dlist<T>::IsEmpty() const {
   if (first == nullptr) {
     return true;
   }
   return false;
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
  if(IsEmpty()) {
    throw "Empty list can't call Dlist<T>::RemoveFront()";
  }
  else{
    node *front = first;
    first = first->next;
    return front;
  }
}
 
 //Destructor
 template <class T>
 Dlist<T>::~Dlist() {
   RemoveAll();
 }

/* this must be at the end of the file */
#endif /* __DLIST_H__ */

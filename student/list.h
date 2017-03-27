/*
===========================================================================
File Name	:List.h
Project		:
File Type	:Header File
Last Updated:1.4.98
Portability	:C++
===========================================================================
Contains:

		a template for using linked list for any type of object
		this template expects for: 1) Data: this is your object class which will be in the list
								   2) Key : this is a part of your object class which
										    your list will be ordered by
		
		you have here also a define of iterator, so you can travel the list as follows:
			
			
		
		  List< My_Data_type* , My_key_type > my_list;  // The first definition of your list
			  
		  // travel the list:
		  
		  for(List< My_Data_type* , My_key_type > :: ConstIterator i(my_list) ; i ; i++)

			{
			   // do something with *(*i) ( This is your Record )
			
			}

		The following operators must be defined for the Key type:
			
			=	(assignment)   // This means also copy-constructor
			==	(equality)
			>	(greater than)

		The following operators must be defined for the Data type:

			<<	 (output)

*/

#ifndef LIST
#define LIST

#include <stdio.h>
#include <iostream.h>
#include <assert.h>

template <class Data,class Key>
class List {

		struct Record {  // The abstract node of the list
			Key key;
			Data data;
			Record *next;
		};

		Record *first;   // head of the list
		Record *candidate, *preceding; // for find
		bool find_record(const Key& );

public:


		List () : first(NULL) {}
		~List() ;

		bool get_data(const Key& ,Data &);
		bool add_data(const Key& ,const Data& );
		bool remove_data(const Key& );
		friend ostream& operator<<(ostream& ,const List<Data,Key>& );



		class ConstIterator {		// check out the note at the top !
		private:
			const List& m_list;
			Record *m_current;
		public:
			ConstIterator(const List& list) : m_list(list),m_current(NULL)
			{	m_current = m_list.first;}

			ConstIterator& operator++()
			{
				assert(m_current!= NULL);
				m_current = m_current->next;
				return *this;
			}

			ConstIterator operator++(int)
			{
				assert(m_current!= NULL);
				ConstIterator i(*this);
				m_current = m_current->next;
				return i;
			}

			operator int() const {return m_current != NULL;}
			const Data& operator *() { return m_current->data;}
			const Data& data() {return m_current->data;}
			const Key& key() {return m_current->key;}
		};
      friend class ConstIterator;

};





template <class Data,class Key>
List<Data,Key>::~List()		//Free the list
{
	Record *curr,*free_me;
	if (first == NULL) return;
	for(curr = first; ; ){
		free_me = curr;
		curr = curr->next;
		delete free_me;
		if(curr == NULL) break;
	}
	first = NULL;
}


// Looks for key and puts its data if found

template <class Data,class Key>
inline bool List<Data,Key>::get_data(const Key& key,Data &data)
{
			if( find_record(key) == true){
				data = candidate->data;
				return true;
			}
			return false;
}



template <class Data,class Key>
inline bool List<Data,Key>::add_data(const Key& key,const Data& data)
{
	Record *pt;
	if( (find_record(key) == true))
		return false;
	pt = new Record;
	assert(pt != NULL);
	pt->key = key;
	pt->data = data;

	if(preceding == NULL){ //insert before the first record or in empty list
		pt->next = first;
		first = pt;
		return true;
	}
	pt->next = preceding->next; //insert at middle or last
	preceding->next = pt;
	return true;
}


template <class Data,class Key>
inline bool List<Data,Key>::remove_data(const Key& key)
{
	Record *free_me;
	if( find_record(key) == false ) return false;
	free_me = candidate;
	if(preceding == NULL)  // Delete the first
		first = candidate->next;
	else
		preceding->next = candidate->next;
	delete free_me->data;
	delete free_me;
	return true;
}


template <class Data,class Key>
ostream& operator<<(ostream& out,const List<Data,Key>& l)
{
	for(List<Data,Key>::ConstIterator i(l); i ; i++)
		out << *(*i);
	return out;
}

template <class Data,class Key>
bool List<Data,Key>:: find_record(const Key& search_key)
{
	preceding = candidate = NULL;
	if(first == NULL) return false; // list is empty
	for(candidate = first; ; ){
		if(candidate->key == search_key) return true;
		if(candidate->key > search_key) return false;
		if(candidate->next == NULL) {
			preceding = candidate;
			return false;
		}
		preceding = candidate;
		candidate = candidate->next;
	}
}


#endif
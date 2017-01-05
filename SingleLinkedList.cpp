#include "SingleLinkedList.h"

void List::Append(int data){
	// Create a new node
	Node* newNode = new Node();
	newNode->Set_Data(data);
	newNode->Set_Next(nullptr);
	
	// Create a iterator pointer
	Node *iterator = head;
	
	if( iterator != nullptr){
		while(iterator->Get_Next() != nullptr){
			iterator = iterator->Get_Next();
		}
	iterator->Set_Next(newNode);
	}
	else{
		head = newNode;
	}
}


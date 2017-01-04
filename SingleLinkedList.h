#pragma once
#include <stddef.h>

// Node class
class Node{
	int data;
	Node* next;
	
	public:
		Node(){};
		void 	Set_Data(int Data) {data = Data;};
		int 	Get_Data() {return data;};		
		void 	Set_Next(Node* Next){next = Next;};
		Node* Get_Next(){return next;};
};

// List class
class List{
	Node *head;
	
	public:
		List() {head = nullptr;};
		void Print();
		void Append(int data);
		void Delete(int data);	
};
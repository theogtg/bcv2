#include <iostream>
#include <string.h>
#include "symTable.h"

using namespace std;

Symbol_node::Symbol_node(){
	next = NULL;
}

Symbol_node::Symbol_node(char * id){
   this->id = new char[strlen(id)+1];
	strcpy(this->id,id);
}

Symbol_node::Symbol_node(char * id, int token, VALUE value){
	this->id = id;
	this->token = token;
	this->value = value;
	next = NULL;
}

char * Symbol_node::getid(){
	return id;
}

void Symbol_node::putval(VALUE val){
	value = val;	
}

VALUE Symbol_node::getval(){
	return value;
}

Symbol_table::Symbol_table(){
	table = new Symbol_ptr [TABLE_SIZE];
	for (int i=0; i<TABLE_SIZE; i++)
		table[i] = NULL;
}

int Symbol_table::hash(char * id){
	int val = 0;
	
	for (int i=0; i<strlen(id); i++){
		val += id[i] * (i+1) * TABLE_SIZE;
	}

	val %= TABLE_SIZE;
	return val;
}

void Symbol_table::print(int index){
	cout << hash(table[index]->id) << " " << table[index]->id << " " << table[index]->value.ivalue << endl;	
}

void Symbol_table::dump_table(){
	for(int i=0; i<TABLE_SIZE; i++){
		Symbol_node* head = table[i];
		while(head != NULL){
			print(i);
			head = head->next;
		}
	}
}

Symbol_ptr Symbol_table::lookup(char * id){
	int index = hash(id);
	Symbol_ptr head = table[index];
	
	if (head == NULL)
		return NULL;

	while (head != NULL){
		if (strcmp(id, head->id) != 0)
			return head;

		head = head->next;
	}

	return NULL;
}

Symbol_ptr Symbol_table::insert(char * id){
	int index = hash(id);
	//Symbol_ptr location = table[index];
	Symbol_ptr stuff = new Symbol_node(id);

	if(table[index] == NULL){
		table[index] = stuff;
		return stuff;
	}
	else{
		Symbol_ptr location = table[index];
		while(location->next != NULL)
			location = location->next;

		location->next = stuff;
		return stuff;
	}
	return NULL;
}

/*
int main(){
	Symbol_table symbolTable;
	char *var = (char *)"test";
	char *abc = (char *)"abc";
	char *cba = (char *)"cba";

	symbolTable.insert(var);
	symbolTable.insert(abc);
	symbolTable.insert(cba);

	symbolTable.dump_table();

	return 0;
}
*/

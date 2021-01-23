//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

struct Node{		// Ein "Element" das einen Wert enthält und einen Pointer auf sich selbst.

	int Wert;
	int *next = NULL;
	int *back = NULL;
};

Node *anchor1 = NULL;
Node *anchor2 = NULL;
Node *runvar = NULL;

void InsertAtBegin(int x){
	Node* new_node= new Node;     // Neues Element wird erstellt.
	new_node->Wert= x;				// new_node->Wert  heißt, dass das neue Element vom Typ Node

	if(!anchor1){
		new_node->next= NULL;
		new_node->back=NULL;
		anchor1=new_node;
		anchor2=new_node;
	}
	else{
		anchor2->back=new_node;
		new_node->next=anchor2;
		anchor1=new_node;
		new_node->back=NULL;
	}

	}


void InsertAtEnd(int x){
	Node* new_node= new Node;	// Neues Element wird erstellt.
	new_node->Wert= x;			// gleiche wie bei InsertAtBegin()

	if(!anchor1){		// Keine Liste vorhanden (Erstes Element hinzufügen)
		new_node->next= NULL;
		new_node->back=NULL;
		anchor1=new_node;
		anchor2=new_node;
	}
	else{				// Liste vorhanden
		anchor2->next=new_node;
		new_node->back=anchor2;
		anchor2=new_node;
		new_node->next=NULL;
	}
}

void InsertSorted(int x){

}

void PrintList(){

	runvar=anchor1;
	while(runvar){
		cout << runvar->Wert << endl;
		runvar=runvar->next;
	}
}

void PrintListReversed(){

	runvar=anchor2;
	while(runvar){
		cout << runvar->Wert << endl;
		runvar=runvar->back;
	}
}

void BubbleSort(){

}

int main()
{
    time_t t;
    time(&t);
    srand(time(NULL));

    cout << "Druecken Sie: a, um ein neues Element am Anfang der Liste einzufuegen" << endl;
    cout << "Druecken Sie: e, um ein neues Element am Ende der Liste einzufuegen" << endl;
    cout << "Druecken Sie: s, um die gesamte List mit BubbleSort aufsteigend zu sortieren" << endl;
    cout << "Druecken Sie: i, um ein neues Element in eine bereits aufsteigend sortierte Liste einzufuegen" << endl;
    cout << "Druecken Sie: q, um das Programm zu verlassen" << endl;

    char Command;

    for(;;)
    {

        cin >> Command;


		switch(Command){
			case 'a':
				InsertAtBegin(rand() % 999 +1); // (rand() % 999 + 1)  <- gibt eine zufällige Zahl aus und fügt sie direkt in die Funktion ein.
				PrintList();
				PrintListReversed();
			break;
			case 'e' :
				InsertAtEnd(rand() % 999 +1);
				PrintList();
				PrintListReversed();
			break;
			case 's' :
				BubbleSort();
				PrintList();
				PrintListReversed();
			break;
			case 'i' :
				InsertSorted (rand() % 999 +1);
				PrintList();
				PrintListReversed();
			break;
			case 'q' :
				return 0;
			break;
		}

    }
    return 0;
}

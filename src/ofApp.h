#pragma once

#include "ofMain.h"

class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = nullptr;
	}

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

//-------------------------------------------------------
class LinkedList
{
	Node* head;
	int size;

public:
	LinkedList()
	{
		head = nullptr;
	}

	Node* GetHead() { return head; }

	void insertAtHead(int data);
	void insertAtTail(int data);
	void deleteHead();
	void deleteTail();

	void addValues(int value);
	void insertionSort();
	Node* sortedInsert(Node* newNode, Node* newHead);
	void printList(Node* head);

	vector<int> linkedListToVector(LinkedList& list);

	const int GetSize() { return size; }
};

class ofApp : public ofBaseApp{

	public:
		LinkedList* mainLinkedList;
		float spacing = 200;        
		float amplitude = 80;
		float offsetX = 0;
		float moveSpeed = 5;    

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void keycodePressed(ofKeyEventArgs& e);
};

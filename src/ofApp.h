#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		float x = 100.f;

		const int numberCircles = 15;
		float spacing = 150;        
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
	Node* newHead;

public:
	LinkedList()
	{
		head = nullptr;
		newHead = nullptr;
	}

	void insertAtHead(int data);
	void insertAtTail(int data);
	Node* deleteHead(Node* head);
	Node* deleteTail(Node* head);

	void addValues(int value);
	void insertionSort(Node* headref);
	void sortedInsert(Node* newNode);
	void printList(Node* head);
};

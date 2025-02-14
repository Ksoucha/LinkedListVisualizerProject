#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(ofGetWindowPtr()->events().keyPressed, this, &ofApp::keycodePressed);
}

//--------------------------------------------------------------
void ofApp::update(){
	//x += ofGetLastFrameTime() * 100;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawCircle(x, 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
		case 'q':
			//Insert node at the head of LinkedList
		    //ofApp::
			break;
		case 'w':
			//Insert node at the tail of LinkedList
		    //ofApp::
			break;
		case 'a':
			//Delete node at the head
		    //ofApp::
			break;
		case 's':
			//Delete node at the tail
		    //ofApp::
			break;
		case 'e':
			//Sort the LinkedList by ascending order
		    //ofApp::
			break;
		case 'z':
			//Increase the amplitude
		    //ofApp::
			break;
		case 'x':
			//Decrease the amplitude
		    //ofApp::
			break;
	}
}

//Code inspire de https://gist.github.com/stungeye/23580e5fef648e2798c069d9e7f83816
void ofApp::keycodePressed(ofKeyEventArgs& e){

	//cout << "KEY : " << e.key << endl;
	//cout << "KEYCODE : " << e.keycode << endl;
	//cout << "MODIFIERS : " << e.modifiers << endl;

	if (e.keycode == 262)
	{
		cout << "RightArrow";
		//Move list to the right
	}
	if (e.keycode == 263)
	{
		cout << "LeftArrow";
		//Move list to the left
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//Code inspiré de https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
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

class LinkedList
{
	Node* head;

public:
	LinkedList()
	{
		head = nullptr;
	}

	void LinkedList::insertAtHead(int data)
	{
		Node* node = new Node(data);

		//If the list is empty
		if (head == nullptr)
		{
			head = node;
			return;
		}

		node->next = head;
		head = node;
	}

	void LinkedList::insertAtTail(int data)
	{
		Node* node = new Node(data);

		//If the list is empty
		if (head == nullptr)
		{
			head = node;
			return;
		}

		Node* currentNode = head;
		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = node;
	}

	Node* LinkedList::deleteHead(Node* head)
	{
		//If the list is empty
		if (head == nullptr)
		{
			return nullptr;
		}

		Node* temp = head;
		head = head->next;
		delete temp;

		return head;
	}

	/*void LinkedList::deleteTail()
	{
	}*/

	/*void LinkedList::sortLinkedList()
	{
	}*/
};
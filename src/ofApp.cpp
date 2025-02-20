#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(ofGetWindowPtr()->events().keyPressed, this, &ofApp::keycodePressed);
	ofSetFrameRate(60);
	ofBackground(0);

	//generateRandomLinkedList(1);
	circles.push_back(2);
	circles.push_back(5);
	circles.push_back(7);
	circles.push_back(2);
}

//--------------------------------------------------------------
void ofApp::update(){
	//x += ofGetLastFrameTime() * 100;
	float maxOffset = ofGetWidth() - (circles.size() * spacing) - 100;
	offsetX = ofClamp(offsetX, 0, maxOffset);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawCircle(x, 100, 100);

	ofSetColor(255);
	ofDrawBitmapString("Press Q to insert a node at the head of the linked list", 40, 40);
	ofDrawBitmapString("Press W to insert a node at the tail of the linked list", 40, 55);
	ofDrawBitmapString("Press A to delete the node at the head of the linked list", 40, 70);
	ofDrawBitmapString("Press S to delete the node at the tail of the linked list", 40, 85);
	ofDrawBitmapString("Press E to sort the linked list", 40, 100);
	ofDrawBitmapString("Press Z to increase the amplitude of the linked list", 40, 115);
	ofDrawBitmapString("Press X to decrease the amplitude of the linked list", 40, 130);

	//Oscillation movement - Écrit avec l'aide de l'IA
	float time = ofGetElapsedTimef() * 5;

	for (int i = 0; i < circles.size(); i++) 
	{
		float x = i * spacing + 100 + offsetX;
		float y = ofGetHeight() / 2 + amplitude * sin(time + i * 0.5);

		//Draw circles
		ofSetColor(255);
		ofDrawCircle(x, y, circles[i]);

		//Draw lines connecting the circles
		if (i > 0) 
		{
			float prevX = (i - 1) * spacing + 100 + offsetX;
			float prevY = ofGetHeight() / 2 + amplitude * sin(time + (i - 1) * 0.5);
			ofSetColor(255);
			ofDrawLine(prevX, prevY, x, y);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	LinkedList linkedList;
	switch (key)
	{
		case 'q':
			//Insert node at the head of LinkedList
			linkedList.insertAtHead(5);
			break;
		case 'w':
			//Insert node at the tail of LinkedList
			linkedList.insertAtTail(5);
			break;
		case 'a':
			//Delete node at the head
			//linkedList.deleteHead(node);
			break;
		case 's':
			//Delete node at the tail
			//linkedList.deleteTail(node);
			break;
		case 'e':
			//Sort the LinkedList by ascending order
			//linkedList.insertionSort(node);
			break;
		case 'z':
			//Increase the amplitude
			amplitude += 10;
			break;
		case 'x':
			//Decrease the amplitude
			amplitude -= 10;
			break;
	}
}

//Code inspiré de https://gist.github.com/stungeye/23580e5fef648e2798c069d9e7f83816
void ofApp::keycodePressed(ofKeyEventArgs& e){

	if (e.keycode == 262)
	{
		//RightArrow
		//Move list to the right
		offsetX += moveSpeed;
	}
	if (e.keycode == 263)
	{
		//LeftArrow
		//Move list to the left
		offsetX -= moveSpeed;
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

//--------------------------------------------------------------
void generateRandomLinkedList(int size, int minValue = 1, int maxValue = 100) 
{
	LinkedList linkedList;
	srand(time(0));
	for (int i = 0; i < size; i++) 
	{
		int randomValue = minValue + (rand() % (maxValue - minValue + 1));
		linkedList.insertAtTail(randomValue);
	}
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

	//If the list has only 1 element
	if (head->next == nullptr)
	{
		delete head;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node* LinkedList::deleteTail(Node* head)
{
	//If the list is empty
	if (head == nullptr)
	{
		return nullptr;
	}

	//If the list has only 1 element
	if (head->next == nullptr)
	{
		delete head;
	}

	Node* node = head;
	while (node != nullptr)
	{
		node = node->next;
		if (node->next == nullptr)
		{
			delete node;
		}
	}
	return node;
}

//Code inspiré de https://www.prepbytes.com/blog/linked-list/insertion-sort-for-singly-linked-list/
//--------------------------------------------------------------
void LinkedList::addValues(int value)
{
	Node* newNode = new Node(value);
	newNode->next = head;

	head = newNode;
}

void LinkedList::insertionSort(Node* headref)
{
	newHead = nullptr;
	Node* current = headref;
	while (current != nullptr)
	{
		Node* temp = current->next;
		sortedInsert(current);
		current = temp;
	}
	head = newHead;
}

void LinkedList::sortedInsert(Node* newNode)
{
	if (newHead == nullptr || newHead->data >= newNode->data)
	{
		newNode->next = newHead;
		newHead = newNode;
	}
	else
	{
		Node* current = newHead;

		while (current->next != nullptr && current->next->data < newNode->data)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void LinkedList::printList(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data << std::endl;
		head = head->next;
	}
}
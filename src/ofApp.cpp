#include "ofApp.h"

LinkedList* generateRandomLinkedList(int size)
{
	LinkedList* linkedList = new LinkedList();
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int randomValue = 1 + (rand() % 95);
		linkedList->insertAtTail(randomValue);
	}
	return linkedList;
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(ofGetWindowPtr()->events().keyPressed, this, &ofApp::keycodePressed);
	ofSetFrameRate(60);
	ofBackground(ofColor::black);

	mainLinkedList = generateRandomLinkedList(1);
}

//--------------------------------------------------------------
void ofApp::update(){
	float maxOffset = ofGetWidth() - (mainLinkedList->GetSize() * spacing) - 100;
	offsetX = ofClamp(offsetX, 0, maxOffset);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::white);
	ofDrawBitmapString("Press Q to insert a node at the head of the linked list", 40, 40);
	ofDrawBitmapString("Press W to insert a node at the tail of the linked list", 40, 55);
	ofDrawBitmapString("Press A to delete the node at the head of the linked list", 40, 70);
	ofDrawBitmapString("Press S to delete the node at the tail of the linked list", 40, 85);
	ofDrawBitmapString("Press E to sort the linked list", 40, 100);
	ofDrawBitmapString("Press Z to increase the amplitude of the linked list", 40, 115);
	ofDrawBitmapString("Press X to decrease the amplitude of the linked list", 40, 130);

	//Oscillation movement - Écrit avec l'aide de l'IA
	float time = ofGetElapsedTimef() * 5;

	Node* currentNode = mainLinkedList->GetHead();
	int index = 0;
	while (currentNode)
	{
		float x = index * spacing + 100 + offsetX;
		float y = ofGetHeight() / 2 + amplitude * sin(time + index * 0.5);

		//Draw circles
		ofSetColor(ofColor::white);
		ofDrawCircle(x, y, currentNode->data);
		ofSetColor(ofColor::black);
		ofDrawBitmapString(ofToString(currentNode->data), x, y);

		//Draw lines connecting the circles
		if (index > 0)
		{
			float prevX = (index - 1) * spacing + 100 + offsetX;
			float prevY = ofGetHeight() / 2 + amplitude * sin(time + (index - 1) * 0.5);
			ofSetColor(ofColor::white);
			ofDrawLine(prevX, prevY, x, y);
		}

		currentNode = currentNode->next;
		index++;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
		case 'q':
			{
				//Insert node at the head of LinkedList
				srand(time(0));
				int randomValue = 1 + (rand() % 95);
				mainLinkedList->insertAtHead(randomValue);
			}
			break;
		case 'w':
			{
				//Insert node at the tail of LinkedList
				srand(time(0));
				int randomValue = 1 + (rand() % 95);
				mainLinkedList->insertAtTail(randomValue);
			}
			break;
		case 'a':
			//Delete node at the head
			mainLinkedList->deleteHead();
			break;
		case 's':
			//Delete node at the tail
			mainLinkedList->deleteTail();
			break;
		case 'e':
			//Sort the LinkedList by ascending order
			mainLinkedList->insertionSort();
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
	size++;
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
	size++;
}

void LinkedList::deleteHead()
{
	//If the list is empty
	if (head == nullptr)
	{
		return;
	}

	//If the list has only 1 element
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
	size--;
}

void LinkedList::deleteTail()
{
	//If the list is empty
	if (head == nullptr)
	{
		return;
	}

	//If the list has only 1 element
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}

	Node* node = head;
	while (node->next->next)
	{	
		node = node->next;
	}

	delete node->next;
	node->next = nullptr;
	size--;
}

//Code inspiré de https://www.prepbytes.com/blog/linked-list/insertion-sort-for-singly-linked-list/
//--------------------------------------------------------------
void LinkedList::addValues(int value)
{
	Node* newNode = new Node(value);
	newNode->next = head;

	head = newNode;
	size++;
}

void LinkedList::insertionSort()
{
	Node* newHead = nullptr;
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		newHead = sortedInsert(current, newHead);
		current = temp;
	}
	head = newHead;
}

Node* LinkedList::sortedInsert(Node* newNode, Node* newHead)
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
	return newHead;
}

void LinkedList::printList(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data << std::endl;
		head = head->next;
	}
}
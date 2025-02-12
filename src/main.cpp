#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();
}

//Code inspire de https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
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

		/*void LinkedList::deleteHead()
		{
		}*/

		/*void LinkedList::deleteTail()
		{
		}*/

		/*void LinkedList::sortLinkedList()
		{
		}*/
};

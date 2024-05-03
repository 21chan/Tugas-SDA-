#include <iostream>
using namespace std;


class Node {
	public :
	Node *left;
	Node *right;
	
	int key;
	
	Node(){
		left = right = NULL;	
	}	
};

class BST {
	public :
		Node *root;
		
		BST(){
			
			root = NULL;
		}
		
		Node *insertRecursive (int inputKey, Node *currentRoot){
			if (currentRoot==NULL){
				Node *newNode = new Node();
				newNode->key = inputKey;
				return newNode;
			}
			
			if (inputKey < currentRoot->key ){
				
				currentRoot->left = insertRecursive(inputKey, currentRoot->left);
			} else if (inputKey > currentRoot->key ){
				
				currentRoot->right = insertRecursive(inputKey, currentRoot->right);
			}
			
			return currentRoot;
		}
			
			void insert(int inputKey)
			{
				root = insertRecursive(inputKey, root);
				
			}
			
			void preOrderTraversal(Node *currentRoot){
				if (currentRoot!=NULL){
					cout << currentRoot->key<<" ";
					preOrderTraversal (currentRoot->left);
					preOrderTraversal (currentRoot->right);
					
				}
			}
			
			void preOrder(){
				cout << "Pre Order Traversal = ";
				
				preOrderTraversal (root);
				
				cout << endl;
			}
			void postOrderTraversal(Node *currentRoot){
				if (currentRoot!=NULL){
					postOrderTraversal (currentRoot->left);
					postOrderTraversal (currentRoot->right);
					cout << currentRoot->key<<" ";
					
				}
			}
			
			void postOrder(){
				cout << "Post Order Traversal = ";
				
				postOrderTraversal (root);
				
				cout << endl;
			}
			
			void inOrderTraversal(Node *currentRoot){
				if (currentRoot!=NULL){
					inOrderTraversal (currentRoot->left);
					cout << currentRoot->key<<" ";
					inOrderTraversal (currentRoot->right);
					
					
				}
			}
			
			void inOrder(){
				cout << "In Order Traversal = ";
				inOrderTraversal (root);
				cout << endl;
			}
			
			
			void findmax (Node* currentNode, int& maxVal){
				while (currentNode->right != NULL)
				currentNode = currentNode->right;
				maxVal = currentNode->key;
			}
			
			
			void findmin (Node* currentNode, int& minVal){
				while (currentNode->left != NULL)
				currentNode = currentNode->left;
				minVal = currentNode->key;
			}
			
			
			void search (int key, Node* currentNode, bool& found){
					if (key == currentNode->key)
						found = true;
					else if (key > currentNode->key)
						search (key, currentNode->right, found);
					else 
						search (key, currentNode->left, found);				
			}
				
				
};




int main(int argc, char** argv) {
	
	BST *bin1 = new BST();
	bin1->insert(6);
	bin1->insert(7);
	bin1->insert(4);
	bin1->insert(8);
	bin1->insert(5);
	bin1->insert(3);
	
	bin1->preOrder();
	bin1->postOrder();
	bin1->inOrder();
	
	int maxVal;
	bin1->findmax(bin1->root, maxVal);
	cout << "Max value : " << maxVal << endl;	
	
	int minVal;
	bin1->findmin(bin1->root, minVal);
	cout << "Min value : " << minVal << endl;
	
	int searchKey = 9;
	bool found = false;
	bin1->search(searchKey, bin1->root, found);
	if (found)
		cout << "value " << searchKey << " found\n";
	else 
		cout << "value " << searchKey << "not Found\n";
	
	return 0;
}
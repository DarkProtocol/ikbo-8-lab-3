#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct _node {
	
	int key;
	struct _node *left, *right;
	struct _node *parent;
	
} node;


node* crnode(int value, node *parent);
void addTree(node **root, int value);
node* getNode(node *root, int value);
void removeNode(node *target);
node* getMaxNode(node *root);
void deleteValue(node *root, int value);
void printTree(node *root, char *dir, int level);



int main() {
	
	node *root = NULL;
	
	
	/* Test */
	
    addTree(&root, 10);
    addTree(&root, 12);
    addTree(&root, 8);
    addTree(&root, 9);
    addTree(&root, 7);
    addTree(&root, 3);
    addTree(&root, 4);
    
    printTree(root, "root", 0);
    printf("-------------------- \n\n");
    
    deleteValue(root, 12);
    printTree(root, "root", 0);

	
	
	return 0;
}



/* Creating new node of tree */

node* crnode(int value, node *parent) {
	
	node *tmp = (node*)malloc(sizeof(node));
	
	
	tmp->key = value;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = parent;
	
	
	return tmp;
}



/* Adds new node to tree */

void addTree(node **root, int value) {
	
	node *tmp = NULL;
    node *ins = NULL;
    
    
    /* If this is root */
    
    if (*root == NULL) {
    	
        *root = crnode(value, NULL);
        return;
    }
    
    
    /* Adds value to tree */
    
    tmp = *root;
    while (tmp) {
    	
        if (value > tmp->key) {
        	
            if (tmp->right) {
            	
                tmp = tmp->right;
                continue;
                
            }	else {
            	
                tmp->right = crnode(value, tmp);
                return;
            }
            
        }	else if (value < tmp->key) {
        	
        	
            if (tmp->left) {
            	
                tmp = tmp->left;
                continue;
                
            }	else {
            	
                tmp->left = crnode(value, tmp);
                return;
            }
            
        }	else {
            
            return;
        }
        
    }
    
      

}
     


/* Finding value in tree */

node* getNode(node *root, int value) {
	
	while (root) {
		
		if (root->key > value) {
			
			root = root->left;
			continue;
			
		}	else if (root->key < value) {
			
			root = root->right;
			continue;
			
		}	else {
			
			return root;
		}
		
	}
	
	return NULL;
	
}



/* Deletes nodes */

void removeNode(node *target) {

	 if (target->left && target->right) {
  	 	 
  	 	 node *max = getMaxNode(target->left);
  	 	 target->key = max->key;
  	 	 removeNode(max);
  	 	 
  	 	 return;
	 	
	 }	else if (target->left) {

			if (target == target->parent->left) {
				
			    target->parent->left = target->left;
			    
			}	else {
				
			    target->parent->right = target->left;
			}
	 	
	 	
	 }	else if (target->right) {
 	
			if (target == target->parent->right) {
				
			    target->parent->right = target->right;
			
			}	else {
				
			    target->parent->left = target->right;
			}
	 	
	 	
	 }	else {
	 	
	 	if (target == target->parent->left) {
	 		
	 		target->parent->left = NULL;
	 		
		 }	else {
		 	
		 	target->parent->right = NULL;
		 }
	 	
	 }
	 


}



node* getMaxNode(node *root) {
	
	while (root->right) {
		
        root = root->right;
    }
    
    
    return root;
}



/* Accessory function */

void deleteValue(node *root, int value) {
	
    node *target = getNode(root, value);
 
    removeNode(target);
}



void printTree(node *root, char *dir, int level) {
	
    if (root) {
    	
        printf("level[%d] %s = %d\n", level, dir, root->key);
        
       	printTree(root->left, "left", level + 1);
       	printTree(root->right, "right", level + 1);
    }
    
    
}




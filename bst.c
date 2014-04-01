#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

struct bst_node {
    int val;
    int size_elem;   // added argument->the total size of tree
    int left_size;   //added argument -> size of the left subtree
    int right_size;  //added argument -> size of the right subtree
    struct bst_node *left;
    struct bst_node *right;
    
};
typedef struct bst_node NODE;


struct bst {
    NODE *root;
};

BST_PTR bst_create(){
    BST_PTR t = malloc(sizeof(struct bst));
    t->root = NULL;
    return t;
}


static void free_r(NODE *r){
    if(r==NULL) return;
    free_r(r->left);
    free_r(r->right);
    free(r);
}
void bst_free(BST_PTR t){
    free_r(t->root);
    free(t);
}
/*
   The function insert was modified
   the total size of the tree is been incremented when an element add to the tree
   the size of left subtree is been incremented if an element is added to that subtree
   the size of right subtree is been incremented if an element is added to that subtree

 */
static NODE * insert(NODE *r, int x){
    NODE *leaf;
    if(r == NULL){
        leaf = malloc(sizeof(NODE));
        leaf->left = NULL;
        leaf->right = NULL;
        leaf->val = x;
        leaf->size_elem = 0;//initializing the total size of tree to zero
        leaf->left_size = 0;//initializing the size left subtree to zero
        leaf->right_size = 0;//initializing the size of right to zero
        return leaf;
    }
    
    if(r->val == x)
        return r;
    if(x < r->val){
        r->left = insert(r->left, x);
        r->size_elem++; //increment the total size of tree
        r->left_size++;//incrementing the left subtree
        
        return r;
    }
    else {
        r->right = insert(r->right, x);
        r->size_elem++;//increment the total size of tree
        r->right_size++;//incrementing the right subtree
        return r;
    }
}

// how about an iterative version?
static NODE *insert_i(NODE *r, int x){
    
    return NULL;
    
}


void bst_insert(BST_PTR t, int x){
    t->root = insert(t->root, x);
}

int bst_contains(BST_PTR t, int x){
    NODE *p = t->root;
    
    while(p != NULL){
        
        if(p->val == x)
            return 1;
        if(x < p->val){
            p = p->left;
        }
        else
            p = p->right;
    }
    return 0;
}

static int min_h(NODE *r){
    if(r==NULL)
        return -1; // should never happen!
    while(r->left != NULL)
        r = r->left;
    return r->val;
}

static int max_h(NODE *r){
    if(r==NULL)
        return -1; // should never happen!
    while(r->right != NULL)
        r = r->right;
    return r->val;
}
/*
 The function remove is been modified 
 The total size of the tree is been decremented when we remove an element from tree
 The size of left subtree is been decremented when we remove an element from left subtree
 The size of right subtree is been decremented when we remove an element from right subtree
 */
static NODE *remove_r(NODE *r, int x, int *success){
    NODE   *tmp;
    
    int sanity;
    //leaf->size_elem = 0;
    
    if(r==NULL){
        *success = 0;
        return NULL;
    }
    if(r->val == x){
        r->size_elem--;//decrementing tree size of tree
        *success = 1;
        
        if(r->left == NULL){
            tmp = r->right;
            free(r);
            return tmp;
        }
        if(r->right == NULL){
            tmp = r->left;
            free(r);
            return tmp;
        }
        // if we get here, r has two children
        r->val = min_h(r->right);
        r->right = remove_r(r->right, r->val, &sanity);
        if(!sanity)
            printf("ERROR:  remove() failed to delete promoted value?\n");
        return r;
    }
    if(x < r->val){
        r->left = remove_r(r->left, x, success);
        if (*success == 1) {
            r->size_elem--;//decrementing tree size of tree
            r->left_size--;//decrementing the left subtree
        }
    }
    else {
        r->right = remove_r(r->right, x, success);
        if (*success == 1) {
            r->size_elem--;//decrementing tree size of tree
            r->right_size--;//decrementing the right subtree
        }
    }
    return r;
    
}


int bst_remove(BST_PTR t, int x){
    int success;
    t->root = remove_r(t->root, x, &success);
    return success;
}
static int size(NODE *r){
    
    if(r==NULL) return 0;
    return size(r->left) + size(r->right) + 1;
}
int bst_size(BST_PTR t){
    
    return size(t->root);
}

static int height(NODE *r){
    int l_h, r_h;
    
    if(r==NULL) return -1;
    l_h = height(r->left);
    r_h = height(r->right);
    return 1 + (l_h > r_h ? l_h : r_h);
    
}
int bst_height(BST_PTR t){
    return height(t->root);
    
}

int bst_min(BST_PTR t){
    return min_h(t->root);
}

int bst_max(BST_PTR t){
    return max_h(t->root);
}

static void indent(int m){
    int i;
    for(i=0; i<m; i++)
        printf("-");
}

static void inorder(NODE *r){
    if(r==NULL) return;
    inorder(r->left);
    printf("[%d]\n", r->val);
    inorder(r->right);
    
}
void bst_inorder(BST_PTR t){
    
    printf("========BEGIN INORDER============\n");
    inorder(t->root);
    printf("=========END INORDER============\n");
    
}

static void preorder(NODE *r, int margin){
    if(r==NULL) {
        indent(margin);
        printf("NULL \n");
    } else {
        indent(margin);
        printf("%d\n", r->val);
        preorder(r->left, margin+3);
        preorder(r->right, margin+3);
    }
}

void bst_preorder(BST_PTR t){
    
    printf("========BEGIN PREORDER============\n");
    preorder(t->root, 0);
    printf("=========END PREORDER============\n");
    
}

/*
 * Complete the (recursive) helper function for the post-order traversal.
 * Remember: the indentation needs to be proportional to the height of the node!
 */
static void postorder(NODE *r, int margin){
    /* FILL IN FUNCTION */
}

// indentation is proportional to depth of node being printed
//   depth is #hops from root.
void bst_postorder(BST_PTR t){
    
    printf("========BEGIN POSTORDER============\n");
    postorder(t->root, 0);
    printf("=========END POSTORDER============\n");
    
}

/*
 * Write the (recursive) helper function from_arr, used by
 * bst_from_sorted_arr(...). The function must return a sub-tree that is
 * perfectly balanced, given a sorted array of elements a.
 */
static NODE * from_arr(int *a, int n){
    int m;
    NODE *root;
    
    if(n <= 0) return NULL;
    m = n/2;
    root = malloc(sizeof(NODE));
    root->val = a[m];
    root->left = from_arr(a, m);
    root->right = from_arr(&(a[m+1]), n-(m+1));
    return root;
    
}

BST_PTR bst_from_sorted_arr(int *a, int n){
    
    BST_PTR t = bst_create();
    
    t->root = from_arr(a, n);
    
    return t;
}
/*
  Function:helper_to_array
  Parameters:NODE r,int array.
  Purpose:copy all the elements in the binary tree in to an array
 */
void helper_to_array(NODE *r,int *array){
    
    //initailizint the counter variable to zero
    static int count = 0;
    //checking to see if the tree is empty..if not empty then
    if(r == NULL) return;
    //Left subtree is then copied to array recursively
    helper_to_array(r->left,array);
    // the element is been assigned to array
    array[count] = r->val;
    //element is printed
    printf("Count ->[%d]\n", array[count]);
    //the counter variable is been incremented
    count++;
    //Right subtree is then copied to array recursively
    helper_to_array(r->right,array);
}
/*
 Function:bst_to_array
 Parameter: BST_PTR t
 Purpose: puts all the elements in the binary tree in to an array..
           it also use the helper function ->helper_to_array()
 */
int *bst_to_array(BST_PTR t){
    
    // allocating space for the array to store it elements
    int *array1 = malloc(sizeof(int)*bst_size(t));
    printf(" %d",bst_size(t));
    // initailizint the counter variable to zero
    int count1= 0;
    //calling the helper function that does that copy that trees elements to an array..
    helper_to_array(t->root,array1);
    // the array is been returned already sorted.
    return array1;
}
/*
 Function:get_ith_helper
 Parameters:NODE r, int i
 Purpose:This is a helper function for the bst_get_ith function
          This returns the ith element
 */
int get_ith_helper(NODE *r,int i){
    //checking to see if the root is the targeted variable.
    if (r->left_size +1 == i) {
        //if so return the root
        return r->val;
    }
    //so if the targeted element is less root that is  the targeted element is on the left said
    else if(i <= r->left_size){
        //Check the left subtree then return the ith element recursively
        return get_ith_helper(r->left,i);
    }
    else
    {
        //else check the rigth subtree, then return ith element recursively
        return get_ith_helper(r->right,i-r->left_size -1);
    }
}
/*
 Function:bst_get_ith
 Parameters:BST_PTR t,int i
 Purpose:This returns the ith element
 */
int bst_get_ith(BST_PTR t,int i){
    
    // The helper function is been returned
    return get_ith_helper(t->root,i);
}
/*
 Function:bst_num_leq_helper
 Parameter:NODE *r,int count,int i
 Purpose:This function is a helper function
         It does return the element in the tree that is less or equal to the target element i
 
 */
int bst_num_leq_helper(NODE *r,int count,int i){
    //check to see if the tree is empty ,i
    if (r == NULL)
        //if so return the counter variable
        return count;
    // if the root is the smallest element is equal to root..
    if (r->val == i ) {
        //then return the root
        return count + r->left_size + 1;
    }
    //hence if the the targeted variable is larger then the root,travesre through the left subtree
    else if(r->val < i){
        
        // the return the element less or equal to the target.
        return bst_num_leq_helper(r->right,count + r->left_size +1,i );
    }
    else{
        //else the targeted variable is less then the root...transverse through the right subtree
        //return the element less or equal to target..
        return bst_num_leq_helper(r->left,count,i );
    }
}
/*
Function:bst_num_leq_helper
Parameter:BST_PTR t,int x.
Purpose:Return the element in the tree that is less or equal to the target element i
        It use the helper function ->bst_num_leq_helper
 */

int bst_num_leq(BST_PTR t,int x){
    
    //The helper function is been called and the less or equal value to the target is been return.
    return bst_num_leq_helper(t->root,0,x);
}
/*
 Function:bst_num_geq_helper
 Parameter:NODE *r,int count,int i
 Purpose:This function is a helper function
         It does return the element in the tree that is greater or equal to the target element i
 */
int bst_num_geq_helper(NODE *r ,int count,int i){
    
     //check to see if the tree is empty ,
    if(r == NULL)
        //if so return the counter variable
        return count;
    // if the root is the greatest element is equal to root..
    if ( r->val == i ) {
        //then return the root
        return count + r->right_size + 1;
    }
   // the targeted variable is greater then the root...transverse through the  left subtree
    else if(r->val > i){
        //return the element greater or equal to the target variable
        return bst_num_geq_helper(r->left,count + r->right_size+1,i);
    }
    else
        //transerve the right subtree and then return the element greater or equal tothe target
        return bst_num_geq_helper(r->right,count,i);
}
/*
 Function:bst_num_geq_helper
 Parameter:BST_PTR t,int x
 Purpose: It does return the element in the tree that is greater or equal to the target element x
 */
int bst_num_geq(BST_PTR t,int x){
    //The helper function is been called to return the element of tree greater or equal to the targeted element x.
    return bst_num_geq_helper(t->root,0,x);
}
/*
 Function:bst_get_nearest_helper
 Parameter:NODE *r, int target, int path, int temp
 Purpose: traverse throuth tree , then Check for the element closet to target
          Then return it.
          This is a helper function for bst_nearest function
 */

int bst_get_nearest_helper(NODE *r, int target, int path, int temp){
    int distance;
    //Checking to  see if the tree is empty
    if(r == NULL)
    {
        //if so return the temperary variable
        return temp;
    }
    //checking for the difference between an element and the targeted variable
    distance = abs(r->val - target);
    // if the difference is less non negetive(absolute) value of the path
    if(abs(path) > distance)
    {
        //Then they are equal
        path = distance;
        
        //the nearest element is the root
        temp = r->val;
    }
// the targeted less then the root
    if(r->val > target)
    {
        //traverse through the left subtree and return the nearest element to the target
        return bst_get_nearest_helper(r->left,target,path,temp);
    }
    else
    {
        ////traverse through the right subtree,if great than the root and return the nearest element to the target
        return bst_get_nearest_helper(r->right,target,path,temp);
    
    }
}
/*
 Function:bst_get_nearest
 Parameter:BST_PTR t, int x
 Purpose:traverse throuth tree , then Check for the element closet to target
 Then return it.
 */
int bst_get_nearest(BST_PTR t, int x){
    int path = 99999;
    int temp;
    //The helper function is been called to return the nearest element in the tree to the target
    return bst_get_nearest_helper(t->root,x,path,temp);
}



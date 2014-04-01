#include <assert.h>
#include "bst.h"
#include <stdio.h>


int main(){
    int i;

    /* PART 1 */

    int a[] = {8, 2, 6, 9, 11, 3, 7};

    BST_PTR t = bst_create();

    for(i=0; i<7; i++)
        bst_insert(t, a[i]);

    //assert(bst_size(t) == 7);
    
    printf("R: %d\n",bst_remove(t, 7));
    printf("New size :%d\n",bst_size(t));
    printf("R: %d\n",bst_remove(t, 2));
     printf("New size :%d\n",bst_size(t));
    printf(" ith elem %d\n",bst_get_ith(t,3));


    /* PART 2 */
   
    //bst_inorder(t);

    /*
    bst_preorder(t);

    bst_postorder(t);

    bst_free(t);
    
     PART 3 (extra)
    
    
    
    int sorted_a[] = {2, 3, 6, 7, 8, 9, 11};
    
    t = bst_from_sorted_arr(sorted_a, 7);

    //int *b = malloc(sizeof(int));
        int *b  = bst_to_array(t);
    for (i = 0;i < bst_size(t);i++){
        
        printf("array new %d\n",b[i]);
    }
     */
    
    
    
    
    
    /*
    bst_inorder(t);

    bst_preorder(t);

    bst_postorder(t);

    bst_free(t);
    */
}

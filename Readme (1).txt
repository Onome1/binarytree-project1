


Name:Onome Ovedje
-----------------------------------------------

Describe what augmentations to the bst data structures you made to complete the 
project -- i.e., what typedefs did you change and why?

The arguments are: int size_elem->the total size of elements of the tree.
                   int left_size -> the size of left subtree
                   int right_size -> the size of the right subtree
These argument were been added to the structure,did had to decrement or increment the size of tree and its subtree when we added or remove an element from the tree.
-----------------------------------------------
Which functions did you need to modify as a result of the augmentations from the previous
question?  
The function that was modified are:1.)NODE * insert(NODE *r, int x)
                                   2.)NODE *remove_r(NODE *r, int x, int *success)

----------------------------------------------
For each function from the previous question, how did you ensure that the (assymptotic) runtime 
remained the same?
 Answer: I will say yes.I just account size of the tree.I think that shouldn’t have much change on the runtime of the modified function.
-----------------------------------------------
For each of the assigned functions, tell us how far you got using the choices 0-5 and
answer the given questions.  


0:  didn't get started
1:  started, but far from working
2:  have implementation but only works for simple cases
3:  finished and I think it works most of the time but not sure the runtime req is met. 
4:  finished and I think it works most of the time and I'm sure my design leads to 
       the correct runtime (even if I still have a few bugs).
5:  finished and confident on correctness and runtime requirements


bst_to_array level of completion:  __5________  


-----------------------------------------------
bst_get_ith level of completion:  _____4______  

    How did you ensure O(h) runtime?

    ANSWER:I say yes but not a 100% sure.The helper function which is then called in the function work recursively.
           check to see if some condition or statement are true or not.
           It then goes through the right or left subtree depending. basically its recursively.  

-----------------------------------------------
bst_get_nearest level of completion:  ______4_____  

    How did you ensure O(h) runtime?

    ANSWER:I say yes but not a 100% sure.The helper function which is then called in the function work recursively.
           check to see if some condition or statement are true or not.
           It then goes through the right or left subtree depending. basically its recursively.  

-----------------------------------------------
bst_num_geq level of completion:  _____4______  

    How did you ensure O(h) runtime?

    ANSWER:I say yes but not a 100% sure.The helper function which is then called in the function work recursively.
           check to see if some condition or statement are true or not.
           It then goes through the right or left subtree depending. basically its recursively.  

-----------------------------------------------
bst_num_leq level of completion:  ______4______

    How did you ensure O(h) runtime?

    ANSWER:I say yes but not a 100% sure.The helper function which is then called in the function work recursively.
           check to see if some condition or statement are true or not.
           It then goes through the right or left subtree depending. basically its recursively.  
-----------------------------------------------
EXTRA CREDIT FUNCTIONS:

bst_min level of completion:  ____0________

    How did you ensure O(1) runtime?

    ANSWER:

-----------------------------------------------
bst_max level of completion:  ____0________

    How did you ensure O(1) runtime?

    ANSWER:

----------------------------------------------

Write a few sentences describing how you tested your solutions.  Are there
any tests that in retrospect you wish you'd done?




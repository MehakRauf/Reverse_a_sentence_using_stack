#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//struct for stack
struct stack
{
    string str;
    struct stack *next;
    struct stack *prev;
};
struct stack *top = NULL;
//to push words from sentence in the stack
void push(string str1, int length1)
{
    //to break the sentence in words
    string words;
    //loop to iterate through the sentence
    for (int i = 0; i < length1; i++)
    {
        //making it empty after iterating every single word
        words = "";
        //loop to iterate a word
        while (str1[i] != ' ' && i < length1)
        {
            //concatenating the chars
            words += str1[i];
            i++;
        }
        //memory allocation
        struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
        temp->str = words;
        temp->next = NULL;
        //chcking if stack is empty
        if (top == NULL)
        {
            top = temp;
        }
        //if not empty then adding it on top
        else
        {
            //adjusting links
            temp->next = top;
            top->prev = temp;
            top = temp;
        }
    }
}
//to pop a word form stack
void pop()
{
    //lifo
    struct stack *curr = top;
    top = top->next;
    free(curr);
}
//to print the stack elements
void print()
{
    if (top == NULL)
    {
        cout << "List is underflow." << endl;
    }
    struct stack *curr = top;
    while (curr != NULL)
    {
        cout << curr->str << " ";
        curr = curr->next;
    }
}
int main()
{
    //taking the sentence as input
    string str1;
    cout << "Enter the sentence:";
    getline(cin,str1);
    push(str1,str1.length());
    print();
}
# HUFFMAN-CODING
*This project illustrates an implementation of the **Huffman Coding** Data Compression Algorithm. It takes input a text (.txt) file as input and compresses   it to produce a binary (.bin) file of reduced size. The .bin file can be decoded back to get the original .txt file.*

• Text File is input from the user and a **Frequency Map** of all characters of the file is created.__
• A **Minimum Priority Queue** is constructed ordered by the frequency of characters with help of which a Huffman Tree is generated.__
• A **Huffman Tree** is a complete binary tree whose leaf nodes contain set of character and its frequency in the text file.__
• Traversing from root node to each leaf node of the Huffman Tree gives the corresponding **Prefix Code** for each character -> going from a node to its left   child is assigned bit value '0' while going to right child is assigned bit value '1'.__
• Text file is then **decoded** into 0s and 1s using character to code map and written into a binary (.bin) file.__
• To decode the .bin file, a **code to character map** is used.__

**CONCEPTS OF C++ USED IN THIS PROJECT:**__
__
❖Concepts of OOP like Classes and Objects, Data Abstraction, Inheritence and Encapsulation__
❖Data Structures like Priority Queue, Binary Tree, HashMap__
❖Basic Text File, Binary File Handling__
❖Basic C++ Concepts like Pointers, Arrays, Vectors, Strings etc.__

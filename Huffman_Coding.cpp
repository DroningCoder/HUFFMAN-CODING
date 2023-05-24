#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//HUFFMAN CODING IMPLEMENTATION

//Code Written By : ARYAN BHATIA
//University      : DELHI TECHNOLOGICAL UNIVERSITY (DTU)
//Roll Number     : 2K21/IT/43

//Note - While mentioning path for a text file, take care that path contains '/' and not '\'.

class node{

    //a single node of Huffman Tree consisiting of
    //pointer to left node, pointer to right node,
    //a character and its frequency

    public:

    node*left;
    node*right;
    char c;
    int freq;

    node(){          
        //default constructor

        left=NULL;
        right=NULL;
        c='\0';
        freq=0;
    }

    node(node*left,node*right,char c,int freq){       
        //parameterized constructor

        this->left=left;
        this->right=right;
        this->c=c;
        this->freq=freq;
    }
};

struct compare{

    //compares frequency of two nodes while pushing nodes in minimum priority queue

    bool operator()(node*a,node*b){
        return a->freq>b->freq;
    }
};

class encode{

    //   private members:

    //1. path to a text file
    //2. frequency map of characters
    //3. map containing binary code for each distinct character in text file
    //4. pointer to root node of huffman tree
    //5. no. of distinct characters in text file
    //6. original text file size and compressed bin file size

    //   public members:

    //1. no. of lines in text file
    //2. map containing character for each binary code
    //3. vector containing size of each encoded line
    //4. input_and_freq_map() 
    //5. print_freq_map()
    //6. create_huffman_tree()
    //7. print_huffman_tree()
    //8. void assign_codes()
    //9. assign_codes_helper(node*,string&)
    //10.print_codes()
    //11.create_binary_file()

    private:

    string path;
    unordered_map<char,int>freq_map;
    unordered_map<char,string>char_to_code_map;
    node*huffman_tree_rootnode;
    int distinct_char=0;
    int original_size=0,compressed_size=0;

    public:

    int no_of_lines=0;
    unordered_map<string,char>code_to_char_map;
    vector<int>line_sizes;
    void input_and_freq_map();
    void print_freq_map();
    void create_huffman_tree();
    void print_huffman_tree();
    void assign_codes();
    void assign_codes_helper(node*,string&);
    void print_codes();
    void create_binary_file();
};

void encode::input_and_freq_map(){

    //takes path to a text file as input
    //and creates a frequency map of characters;
    //also calculates size of text file provided

    for(int i=0;i<100000000;i++){}
    cout<<"\n\nEnter A Path For A Text File (a file with .txt extension) : ";
    getline(cin,path);
    ifstream textfile;
    for(int i=0;i<100000000;i++){}
    cout<<"\n\nOpening File";
    for(int i=0;i<12;i++){
        for (int a=0;a<=100000000;a++){}
        cout<<".";
    }
    textfile.open(path);
    for(int i=0;i<100000000;i++){}
    if(!textfile.is_open()){
        cout<<"\n\n\nFile Could Not Be Opened. Check For The Following:"<<endl;
        for(int i=0;i<1000000000;i++){}
        cout<<"\n\n1. File Is Present In The Given Location.\n2. Syntax Of Path Is Correct."<<endl;
    } 
    int choice;
    for (int a=0;a<=100000000;a++){}
    while(!textfile.is_open()){
        for(int a=0;a<=100000000;a++){}
        cout<<"\nPress 1 To Try Again.\nPress 2 To Exit.\n\nEnter Choice: ";
        cin>>choice;
        for(int a=0;a<=100000000;a++){}
        if(choice==2){
            cout<<"\nExiting";
            for(int i=0;i<5;i++){
                for (int a=0;a<=100000000;a++){}
                cout<<".";
            }
            abort();
        }
        else if(choice==1){
            cout<<"\nEnter A Path For A Text File (a file with .txt extension) : ";
            cin.ignore();
            getline(cin,path);
            textfile.open(path);
            for (int a=0;a<=100000000;a++){}
            cout<<"\n\nOpening File";
            for(int i=0;i<12;i++){
                for (int a=0;a<=100000000;a++){}
                cout<<".";
            }
            if(!textfile.is_open()){
                cout<<"File Could Not Be Opened. Check For The Following:\n1. File Is Present In The Provided Path.\n2. Syntax Of Path Is Correct."<<endl;
                for (int a=0;a<=1000000000;a++){}
            }
        }
        else cout<<"\nInvalid Choice, Try Again."<<endl;
    }
    for(int a=0;a<=100000000;a++){}
    cout<<"\n\n\nFile Opened Successfully!"<<endl<<endl;
    string line;
    int no_char=0;
    while(getline(textfile,line)){
        for(int i=0;i<line.length();i++)freq_map[line[i]]++;
        no_char+=line.length();
        no_of_lines++;
    }
    for(auto i:freq_map)distinct_char++;
    original_size=no_char+2*(no_of_lines-1);
    for(int a=0;a<=1000000000;a++){}
    cout<<"Size of the file is calculated as:"<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Size of file in bytes = Number of characters in each line + one Line Feed(\\n) and one Carriage Return(\\r) character for each line excpet last."<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Size of file in bytes = Total number of alphanumeric and whitespace characters + 2 x (number of lines -1)"<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Size of file in bytes = "<<no_char<<" + 2 x ("<<no_of_lines<<"-1) = "<<original_size<<" bytes."<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"( You Can Crosscheck This Result By Going To The Provided Directory And Right Click On The File -> Properties -> Size )"<<endl<<endl;
    system("pause");
    cout<<"\n\nCreating Frequency Map";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    cout<<"\n\nFrequency Map Constructed Successfully!"<<endl;
}

void encode::print_freq_map(){

    //prints the frequency map created

    for(int a=0;a<=1000000000;a++){}
    cout<<"\nDo You Want To Print The Frequency Map?\n\nPress 1 To Print.\nPress 0 To Continue Without Printing."<<endl;
    int choice;
    while(true){
        for(int a=0;a<=100000000;a++){}
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"\t\t\t\t\t_____________________________________________________________________"<<endl;
            for(int i=0;i<100000000;i++){}
            cout<<"\t\t\t\t\t|\t\t\t\t\t\t\t\t    |"<<endl;
            for(int i=0;i<100000000;i++){}
            cout<<"\t\t\t\t\t|\t\t     FREQUENCY MAP OF CHARACTERS    \t\t    |"<<endl;
            for(int i=0;i<100000000;i++){}
            cout<<"\t\t\t\t\t|\t\t\t\t\t\t\t\t    |"<<endl;
            for(int i=0;i<100000000;i++){}
            cout<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t\t        |\t      CHARACTER\t\t  |\t\t FREQUENCY\t    |"<<endl;
            cout<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl;
            for(auto i:freq_map){
                for(int a=0;a<=100000000;a++){}
                if(i.first==' ')cout<<"\t\t\t\t        |\t      whitespace\t  |\t\t     "<<i.second<<"\t\t    |"<<endl;
                else cout<<"\t\t\t\t        |\t          "<<i.first<<"    \t\t  |\t\t     "<<i.second<<"   \t    |"<<endl;
            }
            cout<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl;
            return;
        }
        else if(choice==0)return;
        else cout<<"\nInvalid Input, Try Again."<<endl;
    }
}

void encode::create_huffman_tree(){

    //creates a minimum priority queue of type pointer to node
    //ordered by frequency of each character in text file
    
    //creates a huffman tree using this minimum priority queue
    //and stores its root node as a private member of encode class

    cout<<endl;
    system("pause");
    cout<<"\nCreating a Minimum Priority Queue Ordered By Frequency";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    priority_queue<node*,vector<node*>,compare>min_pq,min_p_q;
    for(auto i:freq_map){
        node*newnode=new node(NULL,NULL,i.first,i.second);
        min_pq.push(newnode);
    }
    cout<<"\n\nMinimum Priority Queue Created Successfully!"<<endl;
    for(int a=0;a<=1000000000;a++){}
    int choice;
    cout<<"\n\nDo You Want To Print The Minimum Priority Queue?\n\nPress 1 To Print.\nPress 0 to Continue Without Printing."<<endl<<endl;
    while(true){
        for(int a=0;a<=100000000;a++){}
        cout<<"Enter Your Choice: ";
        cin>>choice;
        if(choice==0)break;
        else if(choice==1){
            for(int a=0;a<=100000000;a++){}
            cout<<"\n\nCHARACTER        FREQUENCY"<<endl;
            for(int a=0;a<=100000000;a++){}
            cout<<"---------------------------"<<endl;
            for(int a=0;a<=100000000;a++){}
            while(!min_pq.empty()){
                for(int a=0;a<=100000000;a++){}
                min_p_q.push(min_pq.top());
                if(min_pq.top()->c==' ')cout<<"whitespace   :       "<<min_pq.top()->freq<<endl;
                else cout<<min_pq.top()->c<<"            :       "<<min_pq.top()->freq<<endl;
                min_pq.pop();
            }
            break;
        }
        else cout<<"\nInvalid Input, Try Again."<<endl<<endl;
    }
    while(!min_pq.empty()){
        for(int a=0;a<=100000000;a++){}
        min_p_q.push(min_pq.top());
        min_pq.pop();
    }
    cout<<endl;
    system("pause");
    cout<<"\n\nCreating Huffman Tree";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    for(int i=0;i<distinct_char-1;i++){
        node*node1=min_p_q.top();
        min_p_q.pop();
        node*node2=min_p_q.top();
        min_p_q.pop();
        node*node3=new node(node1,node2,'\0',node1->freq+node2->freq);
        min_p_q.push(node3);
    }
    huffman_tree_rootnode=min_p_q.top();
    cout<<"\n\nHuffman Tree Created Successfully!"<<endl;        
    for(int a=0;a<=1000000000;a++){}
}

void encode::print_huffman_tree(){

    //prints the huffman tree in level order fashion using queue data structure

    cout<<"\nDo You Want To Print The Huffman Tree?\n\nPress 1 To Print.\nPress 0 To Continue Without Printing."<<endl;
    int choice;
    while(true){
        for(int a=0;a<=100000000;a++){}
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        if(choice==1){
            for(int a=0;a<=100000000;a++){}
            cout<<"\n\nLevel Order Traversal of The Huffman Tree is:"<<endl<<endl;
            queue<const node*>q;
            q.push(huffman_tree_rootnode);
            while(!q.empty()){
                for(int a=0;a<=100000000;a++){}
                node*frontnode=new node(q.front()->left,q.front()->right,q.front()->c,q.front()->freq);
                if(frontnode->left&&frontnode->right){
                    q.push(frontnode->left);
                    q.push(frontnode->right);
                }
                q.pop();
                if(frontnode->c==' ')cout<<"whitespace:"<<to_string(frontnode->freq)<<"  ";
                else if(freq_map[frontnode->c])cout<<frontnode->c<<":"<<to_string(frontnode->freq)<<"  ";
                else cout<<to_string(frontnode->freq)<<"  ";
            }
            return;
        }
        else if(choice==0)return;
        else cout<<"\nInvalid Input, Try Again."<<endl;
    }
}

void encode::assign_codes_helper(node*root,string&code){
    if(!root->left&&!root->right){
        char_to_code_map[root->c]=code;
        return;
    }
    code.push_back('0');
    assign_codes_helper(root->left,code);
    code.pop_back();
    code.push_back('1');
    assign_codes_helper(root->right,code);
    code.pop_back();
}

void encode::assign_codes(){

    //assigns binary codes to each character of text file 
    //recursively by calling a helper function
    //0 is assigned for left child and 1 is assigned for right child
    
    //char to code map is constructed for encoding textfile
    //code to char map is constructed for decoding a binary file back to text file

    cout<<endl<<endl;
    system("pause");
    string code="";
    assign_codes_helper(huffman_tree_rootnode,code);
    for(auto i:char_to_code_map)code_to_char_map[i.second]=i.first;
    cout<<"\n\nAssigning Codes";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    cout<<"\n\nCodes Assigned to Each Character Successfully!"<<endl<<endl;
}

void encode::print_codes(){

    //prints the codes assigned to each character of text file

    for(int a=0;a<=1000000000;a++){}
    cout<<"\nDo You Want To Print The Assigned Codes?\n\nPress 1 To Print.\nPress 0 To Continue Without Printing."<<endl;
    int choice;
    while(true){
        for(int a=0;a<=100000000;a++){}
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        if(choice==1){
            for(int a=0;a<=100000000;a++){}
            cout<<"\n\nCHARACTER         CODE"<<endl;
            for(int a=0;a<=100000000;a++){}
            cout<<"-------------------------"<<endl;
            for(int a=0;a<=100000000;a++){}
            for(auto i:char_to_code_map){
                for(int a=0;a<=100000000;a++){}
                if(i.first==' ')cout<<"whitespace :      "<<i.second<<endl;
                else cout<<"    "<<i.first<<"      :      "<<i.second<<endl;
            }
            return;
        }
        else if(choice==0)return;
        else cout<<"\nInvalid Input, Try Again."<<endl;
    }
}

void encode::create_binary_file(){

    //creates a binary file
    //encodes the text file line by line into string of 0s and 1s using generated codes
    //string of 0s and 1s is padded (size is made a multiple of 8 by adding extra 0 bits in the end of each line)
    //so that byte by byte data is written into binary file

    cout<<endl;
    system("pause");
    cout<<"\n\nCreating a Binary File Named COMPRESSED.bin For Writing";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    ofstream binfile("COMPRESSED.bin",ios::binary);
    if(!binfile.is_open()){
        cout<<"\nError Creating BIN File."<<endl;
        abort();
    }
    ifstream textfile;
    textfile.open(path);
    int no_of_bytes=0,line_number=0,choice;
    cout<<"\n\nBinary File COMPRESSED.bin Was Created Successfully! Do You Want To Print The Contents Of The Binary File?\n\nPress 1 To Print.\nPress Any Other Number To Continue Without Printing."<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Enter Your Choice: ";
    cin>>choice;
    if(choice==1){
        for(int a=0;a<=100000000;a++){}
        cout<<"\n\nContents Of COMPRESSED.bin : "<<endl<<endl;
    }
    string line,padded_binary_string;
    while(getline(textfile,line)){
        string binary_string="";
        for(int i=0;i<line.length();i++)binary_string+=char_to_code_map[line[i]];
        line_sizes.push_back(binary_string.length());
        padded_binary_string=binary_string;
        while(padded_binary_string.length()%8!=0){padded_binary_string+="0";}
        if(choice==1){
            for(int a=0;a<=100000000;a++){}
            cout<<padded_binary_string<<endl;
        }
        for(int i=0;i<padded_binary_string.length();i+=8){
            no_of_bytes++;
            string bytestring=padded_binary_string.substr(i,8);
            int binary_converted=stoi(bytestring,nullptr,2);
            char byte=char(binary_converted);
            binfile.write(&byte,sizeof(char));
        }
        line_number++;
        if(line_number<no_of_lines)binfile<<'\n';
    }
    compressed_size=no_of_bytes+no_of_lines-1;
    for(int a=0;a<=1000000000;a++){}
    cout<<"\n\nSize Of COMPRESSED.bin File = "<<compressed_size<<" Bytes."<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"( You Can Crosscheck This Result By Going To The Directory Where This Program is Saved And Right Click On COMPRESSED.bin -> Properties -> Size )"<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"A Compression Of Approximately "<<(float(original_size-compressed_size)/original_size)*100<<"% was achieved."<<endl;
}

class decode: public encode{

    //child class of base class encode

    //private members:
    //all public and private members of base class encode

    //public members:
    //get_text_from_bin()

    public:
    void get_text_from_bin();
};

void decode::get_text_from_bin(){

    //opens binary file created by create_binary_file()
    //creates a new text file 
    //decodes content of binary file using code to char map 
    //and writes text into a new text file
    //original text file and new text file created in this step have same content and size

    cout<<endl;
    system("pause");
    cout<<"\n\nDecoding Procedure Initiated";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    ofstream textfile;
    cout<<"\n\nCreating New Text File For Writing Decoded Characters";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    textfile.open("DECODED_TEXTFILE.txt");
    if(!textfile.is_open()){
        cout<<"\n\nError Opening Text File."<<endl;
        abort();
    }
    cout<<"\n\nNew Text File Created Successfully!"<<endl;
    for(int a=0;a<=1000000000;a++){}
    cout<<"\n\nOpening COMPRESSED.bin";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    ifstream binfile;
    binfile.open("COMPRESSED.bin",ios::binary);
    if(!binfile.is_open()){
        cout<<"\n\nError opening the BIN file."<<endl;
        abort();
    }
    cout<<"\n\nCOMPRESSED.bin Was Opened Successfully!"<<endl<<endl;
    cout<<"Decoding COMPRESSED.bin";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    cout<<"\n\nCOMPRESSED.bin Was Decoded Successfully!"<<endl<<endl;
    cout<<"Writing Into DECODED_TEXTFILE.txt";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
    string binline;
    int index=0,line_number=0;
    while(getline(binfile,binline)){
        string line="";
        for(int i=0;i<binline.length();i++){
            int n=binline[i]+0;
            bitset<8>binary(n);
            line+=binary.to_string();
        }
        line=line.substr(0,line_sizes[index++]);
        int slow_ptr=0,fast_ptr=0;
        while(fast_ptr<line.length()){
            if(code_to_char_map[line.substr(slow_ptr,fast_ptr-slow_ptr+1)]){
                textfile<<code_to_char_map[line.substr(slow_ptr,fast_ptr-slow_ptr+1)];
                fast_ptr++;
                slow_ptr=fast_ptr;
            }
            else fast_ptr++;
        }
        line_number++;
        if(line_number<no_of_lines)textfile<<'\n';
    }
    for(int a=0;a<=100000000;a++){}
    cout<<"\n\nWriting Into DECODED_TEXTFILE.txt Was Completed."<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Open DECODED_TEXTFILE.txt To See Contents."<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Size Of Original Text File And DECODED_TEXTFILE.txt Is Same (Check This Result)."<<endl<<endl;
    for(int a=0;a<=100000000;a++){}
    cout<<"Terminating Program";
    for(int i=0;i<10;i++){
        for(int a=0;a<=100000000;a++){}
        cout<<".";
    }
}

void welcome_message(){

    cout<<"\t\t\t\t\t_____________________________________________________________________"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t|\t\t\t\t\t\t\t\t    |"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t|\t\t   FILE COMPRESSION USING HUFFMAN CODING    \t    |"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t|\t\t\t\t\t\t\t\t    |"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t\t\t\t    Written by:"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t\t\t\t    Aryan Bhatia"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t\t\t   DELHI TECHNOLOGICAL UNIVERSITY"<<endl;
    for(int i=0;i<100000000;i++){}
    cout<<"\t\t\t\t\t\t\t\t     2K21/IT/43"<<endl<<endl<<endl<<endl<<endl;
    system("pause");

}

int main(){

    welcome_message();
    decode user;
    user.input_and_freq_map();
    user.print_freq_map();
    user.create_huffman_tree();
    user.print_huffman_tree();
    user.assign_codes();
    user.print_codes();
    user.create_binary_file();
    user.get_text_from_bin();
    
}
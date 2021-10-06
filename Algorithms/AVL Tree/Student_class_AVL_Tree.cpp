#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Student
{
	
	int RollNo;
	char *name;
	float cgpa;
public:
	void setRollno(int rn)
	{
		RollNo=rn;
	}
	int getrollno()
	{
		return RollNo;
	}
	void setname(char* _name)
	{
		int n=strlen(_name)+1;
		name=new char[n];
		strcpy_s(name,n,_name);
	}
	char * getname()
	{
		return name;
	}
	void setcgpa(float _cgpa)
	{
		cgpa=_cgpa;
	}
	float getcgpa()
	{
		return cgpa;
	}
	Student()
	{
		RollNo=0;
		name=nullptr;
		cgpa=0;
	}
	friend ostream & operator <<(ostream & Out,Student & obj)
	{
		Out<<"RollNo: "<<obj.getrollno()<<'\n';
		if(obj.name!=nullptr)
			Out<<"Name: "<<obj.getname()<<'\n';
		Out<<"CGPA: "<<obj.getcgpa()<<'\n';
		return Out;
	}
};
struct StdNode
{
	Student * data;
	int height;
	StdNode *lchild;
	StdNode * rchild;
	StdNode()
	{
		data=new Student();
		height=0;
		lchild=nullptr;
		rchild=nullptr;
	}
};
class AVL
{
	StdNode * root;
public:
	AVL()
	{
		root=nullptr;
	}
	int getheight(StdNode * N)
	{
		if(N==nullptr)
			return 0;
		return N->height;
	}
	int maxbwNode(int N,int M)
	{
		if(M>N)
			return M;
		else
		{
			return N;
		}
	}
	int CheckBalance(StdNode *N)
	{
		if(N==nullptr)
			return 0;
		return getheight(N->lchild)-getheight(N->rchild);
	}
	StdNode *rightRotate(StdNode *N)
	{
		StdNode *M = N->lchild;  
        StdNode *Z = M->rchild; 
		M->rchild = N;  
		N->lchild = Z;  
  
    // Update heights  
    N->height = maxbwNode(getheight(N->lchild), 
                    getheight(N->rchild)) + 1;  
    M->height = maxbwNode(getheight(M->lchild), 
                    getheight(M->rchild)) + 1;  
  
    // Return new root  
    return M;  
	}
	StdNode *leftRotate(StdNode *N)
	{
		StdNode *M = N->rchild;  
        StdNode *Z = M->lchild; 
		M->lchild = N;  
		N->rchild = Z;  
  
    // Update heights  
    N->height = maxbwNode(getheight(N->lchild), 
                    getheight(N->rchild)) + 1;  
    M->height = maxbwNode(getheight(M->lchild), 
                    getheight(M->rchild)) + 1;  
  
    // Return new root  
    return M;  
	}
	StdNode * helpinsert(StdNode * R,int RNo,char * _name,float _cgpa)
	{
		if(R==nullptr)
		{
			R=new StdNode();
			R->data->setRollno(RNo);
			R->data->setname(_name);
			R->data->setcgpa(_cgpa);
			R->height=1;
			R->lchild=nullptr;
			R->rchild=nullptr;
			return R;
		}
		if(RNo<R->data->getrollno())
		{
			R->lchild=helpinsert(R->lchild,RNo,_name,_cgpa);
		}
		else if(RNo>R->data->getrollno())
		{
			R->rchild=helpinsert(R->rchild,RNo,_name,_cgpa);
		}
		else
		{
			return R;
		}
		R->height = 1 + maxbwNode(getheight(R->lchild),  
			getheight(R->rchild));  
		int balance = CheckBalance(R);
		if (balance > 1 && RNo < R->lchild->data->getrollno())  
        return rightRotate(R);  

		if (balance < -1 && RNo < R->rchild->data->getrollno())  
			return leftRotate(R);  
		if (balance > 1 && RNo < R->lchild->data->getrollno())  
		{
			R->rchild=rightRotate(R->rchild);
			return rightRotate(R);
		}
		if (balance < -1 && RNo < R->rchild->data->getrollno())  
		{
			R->rchild=rightRotate(R->rchild);
			return leftRotate(R);
		}

		return R;
	}
	void insertStudent(int RNo,char * _name,float _cgpa)
	{
		if(root==nullptr)
		{
			root=new StdNode();
			root->data->setRollno(RNo);
			root->data->setname(_name);
			root->data->setcgpa(_cgpa);
			root->height=1;
			root->lchild=nullptr;
			root->rchild=nullptr;
		}
		if(RNo<root->data->getrollno())
		{
			root->lchild=helpinsert(root->lchild,RNo,_name,_cgpa);
		}
		else if(RNo>root->data->getrollno())
		{
			root->rchild=helpinsert(root->rchild,RNo,_name,_cgpa);
		}
		else
		{
			return;
		}
	}
	StdNode * searchhelp(StdNode * R,int key)
	{
		StdNode * temp=nullptr;
		if(R->data->getrollno()==key)
			return R;
		if(key<R->data->getrollno())
			 temp=searchhelp(R->lchild,key);
		else if(key > R->data->getrollno())
			temp=searchhelp(R->rchild,key);

		return temp;
	}
	Student * search(int RNo)
	{
		StdNode * temp=searchhelp(root,RNo);
		return temp->data;
	}
	StdNode * minValueNode(StdNode* node) 
	{ 
		StdNode* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->lchild != NULL)  
        current = current->lchild;  
  
    return current;  
}  
	StdNode* deleteNode(StdNode* _root, int key)  
	{
		if (_root == NULL)  
        return _root;  
		if ( key < _root->data->getrollno())  
        _root->lchild = deleteNode(_root->lchild, key);  
		else if( key > _root->data->getrollno() )  
        _root->rchild = deleteNode(_root->rchild, key); 
    else
    {  
        if( (_root->lchild == NULL) || 
			(_root->rchild == NULL) )  
        {  
            StdNode *temp = _root->lchild ?  
                         _root->lchild :  
                         _root->rchild;  
  
            // No child case 
            if (temp == NULL)  
            {  
                temp = _root;  
                _root = NULL;  
            }  
            else // One child case  
            *_root = *temp; // Copy the contents of  
                           // the non-empty child  
            delete temp;  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            StdNode* temp = minValueNode(_root->rchild);  
  
            // Copy the inorder successor's  
            // data to this node  
			_root->data->setRollno(temp->data->getrollno());  
            _root->rchild = deleteNode(_root->rchild,  
				temp->data->getrollno());  
        }  
    }  
    if (_root == NULL)  
    return _root;  
    _root->height = 1 + maxbwNode(getheight(_root->lchild),  
                           getheight(_root->rchild));  
 
    int balance = CheckBalance(_root);  
    if (balance > 1 &&  CheckBalance(_root->lchild) >= 0)  
        return rightRotate(_root);  
  
    // Left Right Case  
    if (balance > 1 && CheckBalance(_root->lchild) < 0)  
    {  
        _root->lchild = leftRotate(_root->lchild);  
        return rightRotate(_root);  
    }   
    if (balance < -1 &&  CheckBalance(_root->rchild) <= 0)  
        return leftRotate(_root);  
  
    // Right Left Case  
    if (balance < -1 &&   CheckBalance(_root->rchild) > 0)  
    {  
        _root->rchild = rightRotate(_root->rchild);  
        return leftRotate(_root);  
    }  
  
    return _root;  
}  
	bool deleteStudent(int RNo)
	{
		deleteNode(root,RNo);
	}
	void printGivenLevel(StdNode* root, int level) 
	{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
		cout<< root->data->getrollno()<<'\t'; 
    else if (level > 1) 
    { 
        printGivenLevel(root->lchild, level-1); 
        printGivenLevel(root->rchild, level-1); 
    }
	} 
	void inorderPrintStdRNo()
	{
		int h = getheight(root); 
        int i;
		for (i=1; i<=6; i++) 
		{ 
        printGivenLevel(root, i); 
        cout<<'\n';
		} 
	}
	~AVL()
	{
		if(root!=nullptr)
			delete [] root;
	}
};
void popuateStudentTree(char * filename, AVL & stdTree)
{
	ifstream ifile(filename);
	if(!ifile)
	{
		cout<<"File Not Opened\n";
	}
	else
	{
		cout<<"File Opened\n";
		while (!ifile.eof())
		{
			int rn;
			char ch[100];
			float cgpa;
			ifile>>rn;
			ifile.ignore();
			ifile.getline(ch,100,' ');
			ifile>>cgpa;
			stdTree.insertStudent(rn,ch,cgpa);
		}
	}
}
void main()
{
	AVL stdTree;
    popuateStudentTree("students.txt", stdTree);
    cout << endl << endl << "Tree Before Deletion: " << endl;
	stdTree.inorderPrintStdRNo();
    //delete any student
    cout << endl << endl << "Tree after Deletion: " << endl;
	stdTree.inorderPrintStdRNo();
    cout<<"Data of student, whose roll number is 254, is as follows: "<< endl;
    cout << *stdTree.search(254);
	system("pause");
}
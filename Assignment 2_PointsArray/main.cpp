#include<iostream>
using namespace std;

class point
{
private:
	int x, y;
public:
	void setxy(int i,int j)
	{
		x = i;
		y = j;
	}
	int getx()
	{
		return x;
	}

	int gety()
	{
		return y ;
	}
	void print()
	{
		cout << "(" << x << "," << y << ")";
	}


};

class pointsarray
{
private:
	point** arrp;
	int rows, cols;

public:
    //1
	pointsarray(int r, int c)
	{
	    rows=r;
	    cols=c;
        arrp= new point* [rows];
		for (int i = 0; i < rows; i++)
        {
			arrp[i] = new point[cols];

		}
		for (int i=0; i<rows; i++ )
        {
            for(int j=0; j<cols; j++)
            {
                arrp[i][j].setxy(0,0);
            }
        }
	}
	//2
	pointsarray(const pointsarray& obj)
	{
	    rows=obj.rows;
	    cols=obj.cols;
	    arrp=new point* [rows];
	    for (int i = 0; i < rows; i++)
        {
			arrp[i] = new point[cols];

		}
		for (int i=0; i<rows; i++ )
        {
            for(int j=0; j<cols; j++)
            {
                arrp[i][j]=obj.arrp[i][j];
            }
        }
	}
	//3
	int getRows()
	{
        return rows;
    }
    //4
	int getColumns()
	{
        return cols;
    }
    //5
    friend istream& operator>>(istream& is, pointsarray& obj)
		{
			int x;
			int y;
			cout <<"Enter values of points in the matrix:"<< endl;
			for (int i = 0; i < obj.rows; i++)
            {
				for (int j = 0; j < obj.cols; j++)
				{
					cout <<"x-coordinate of index("<<i<<","<<j<<"):"<<endl;
					is >> x;
					cout <<"y-coordinate of index("<<i<<","<<j<<"):"<<endl;
					is >> y;
					obj.arrp[i][j].setxy(x,y);
				}
			}
			return is;
		}
     //6
     friend ostream& operator<<(ostream& os, const pointsarray& obj)
		{
			cout << "Points of pointsarray:" << endl;
				for (int i = 0; i < obj.rows; i++)
                {
					for (int j = 0; j < obj.cols; j++)
					{
						os <<"("<<obj.arrp[i][j].getx()<<","<<obj.arrp[i][j].gety()<<")"<<"  ";
					}
					cout<<endl;
				}
				return os;
			}
    //7
    void operator=(const pointsarray& obj)
    {
        for (int i=0; i<rows; i++ )
        {
            for(int j=0; j<cols; j++)
            {
                arrp[i][j]=obj.arrp[i][j];
            }
        }
    }
    //8
    void setpoint(int m,int n){
        int x,y;
        if(m>=0 && m<rows && n>=0 && m<cols )
        {
            cout<<"Enter the X-coordinate of the new point"<<endl;
            cin>>x;
            cout<<"Enter the Y-coordinate of the new point"<<endl;
            cin>>y;
            arrp[m][n].setxy(x,y);

        }

    }
    //9
    pointsarray operator+(int num)
    {
        pointsarray obj(rows,cols);
        for (int i=0; i<rows; i++ )
        {
            for(int j=0; j<cols; j++)
            {
                point temp=arrp[i][j];
                temp.setxy(temp.getx()+num,temp.gety()+num);
                obj.arrp[i][j]=temp;
            }
        }
        return obj;
    }
    //10
    void swapRows(int r1, int r2)
    {
        point* row1 = arrp[r1];
        point* row2 = arrp[r2];
        for (int i = 0; i < cols; ++i) {
            point temp = *(row1 + i);
            *(row1 + i) = *(row2 + i);
            *(row2 + i) = temp;
        }
    }

    //11
    void deleteColumn(int index)
    {
        if(index>=cols && index<0){
            cout<<"Wrong column index"<<endl;
        }
        else
        {
            for(int j=index;j<cols;j++)
            {
                for(int i=0;i<rows;i++)
                {
                    arrp[i][index]=arrp[i][index+1];

                }
            }
        cols=cols-1;
        }
    }
    //12
    void addColumn(int c,point* p)
    {
        int j;
        if(c>=0 && c<=rows)
        {
            cols+=1;
            for(int i=0; i<rows; i++)
            {
                for(j=cols-1;j>c;j--)
                {
                    arrp[i][j]=arrp[i][j-1];
                }
                if(j==c)
                {
                    arrp[i][c]=p[i];
                }
            }
        }
        else
            cout<<"Invalid index"<<endl;
    }
    //13
    void printMatrix()
    {
        for (int i=0; i<rows; i++ )
        {
            for(int j=0; j<cols; j++)
            {
                arrp[i][j].print();
                cout<<"  ";
            }
            cout<<endl<<endl;
        }
    }
    //14
    ~pointsarray()
    {
        for (int i = 0; i < rows; i++)
        {
			delete[] arrp[i];

		}
		delete[] arrp;


    }

};
int main()
{
    int r , c , x , index1 , index2 , row1 , row2 , m , n ;
    int choice;
    cout<<"Enter the number of rows of points matrix"<<endl;
    cin>>r;
    cout<<"Enter the number of columns of points matrix"<<endl;
    cin>>c;
    pointsarray obj1(r,c);
    cout <<endl<< "Choices:" << endl;
    cout << "1-Enter pointsarray elements" << endl;
    cout << "2-Display number of rows" << endl;
    cout << "3-Display number of columns" << endl;
    cout << "4-Copy pointsarray" << endl;
    cout << "5-Display pointsarray" << endl;
    cout << "6-Add integer to pointsarray " << endl;
    cout << "7-Swap rows" << endl;
    cout << "8-Delete column" << endl;
    cout << "9-Add column" << endl;
    cout << "10-Print pointsarray as matrix" << endl;
    cout << "11-Exit"<<endl<<endl;
    cout << "Enter the choice you want from 1 to 11:" << endl;
    cin >> choice;
   while (choice !=11)
    {
        switch (choice)
        {
        case 1:
            {
                cin >> obj1;
                break;
            }
        case 2:
            {
                cout <<"The number of rows = " <<obj1.getRows()<<endl;
                break;
            }
        case 3:
            {
                cout <<"The number of columns = "<<obj1.getColumns()<<endl;
                break;
            }
        case 4:
            {
                pointsarray obj2=obj1;
                cout<<"The copied pointsarray:"<<endl;
                obj2.printMatrix();
                break;
            }
        case 5:
            {
                cout<<obj1;
                break;
            }
         case 6:
             {
                cout<<"Enter the number you want to add to points:"<<endl;
                cin>>x;
                obj1=obj1+x;
                cout<<"The pointsarray after adding "<<x<<" to them:"<<endl;
                obj1.printMatrix();
                break;
             }
        case 7:
            {
                cout << "Enter the index of the first row you want to swap:" << endl;
                cin >> row1;
                cout << "Enter the index of the second row you want to swap:" << endl;
                cin >> row2;
                obj1.swapRows(row1, row2);
                cout<<"The pointsarray after swaping row of index "<<row1<<" with row of index "<<row2<<":"<<endl;
                obj1.printMatrix();
                break;
            }
        case 8:
            {
                cout << "Enter the index of the column you want to delete:" << endl;
                cin >> index1;
                obj1.deleteColumn(index1);
                cout<<"The pointsarray after deleting column of index "<<index1<<":"<<endl;
                obj1.printMatrix();
                break;
            }
        case 9:
            {
                cout<<"Enter the index of the column you want to add:"<<endl;
                cin>>index2;
                cout<<"Enter the values of points of the added column:"<<endl;
                point arr[r];
                for(int i=0;i<r;i++)
                {
                   cout<<"Enter x-coordinate of "<<i+1<<" row"<<endl;
                   cin>>m;
                   cout<<"Enter x-coordinate of "<<i+1<<" row"<<endl;
                   cin>>n;
                   arr[i].setxy(m,n);
                }
                obj1.addColumn(index2,arr);
                cout<<"The pointsarray after adding column of index "<<index2<<" to them:"<<endl;
                obj1.printMatrix();
                break;
            }
        case 10:
            {
                cout<<"The pointsarray as a matrix:"<<endl;
                obj1.printMatrix();
                break;
            }
        default:
            cout<<"Invalid choice, please enter a valid one"<<endl;
            break;
        }
        cout <<endl<< "Choices:" << endl;
        cout << "1-Enter pointsarray elements" << endl;
        cout << "2-Display number of rows" << endl;
        cout << "3-Display number of columns" << endl;
        cout << "4-Copy pointsarray" << endl;
        cout << "5-Display pointsarray" << endl;
        cout << "6-Add integer to pointsarray " << endl;
        cout << "7-Swap rows" << endl;
        cout << "8-Delete column" << endl;
        cout << "9-Add column" << endl;
        cout << "10-Print pointsarray as matrix" << endl;
        cout << "11-Exit"<<endl<<endl;
        cout << "Enter the choice you want from 1 to 11:" << endl;
        cin >> choice;

    }
    cout<<"Thank you for using our program ^_^"<<endl;



    return 0;
}

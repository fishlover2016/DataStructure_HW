#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

//global variables

string data[5000];
int last_str;


string str_list[1000];
int f_array1[1000]={0};
int f_array2[1000]={0};
int count1=0;
int found=0;






int main()
{
	
	
	//wait for user input and get them
	string inputtxt;
	int rank=0;
	
	cin>>inputtxt>>rank;
	
	
	//count process time
	clock_t start_time,end_time;
	double total_time=0;
	
	start_time=clock();
	
	
	//open the txt file
	fstream file;
	
	file.open(inputtxt,ios::in);
	
	if(file.is_open())
	{
		
		//read txt into string
		int i;
		
		for(i=0;i<=2500;i++)
		{
			if(file.eof()) break;
				
			file>>data[i];
		}
		
		last_str=i-1;	
			
		
		file.close();
		
		
	
	}
	else
	{
		cout<<"Fail to open file";
	}
	
	
	int is_char;
	
	
	for(int a1=0;a1<=last_str;a1++)
	{
		
		for(int a2=0;a2<data[a1].length();a2++)
		{
			
			//change capital letter to small letter
			//if the word isn't English or number, set is_char=1
			
			switch(data[a1][a2])
			{
			
			case 'A': data[a1][a2]='a';is_char=0; break;
			case 'B': data[a1][a2]='b';is_char=0; break;
			case 'C': data[a1][a2]='c';is_char=0; break;
			case 'D': data[a1][a2]='d';is_char=0; break;
			case 'E': data[a1][a2]='e';is_char=0; break;
			case 'F': data[a1][a2]='f';is_char=0; break;
			case 'G': data[a1][a2]='g';is_char=0; break;
			case 'H': data[a1][a2]='h';is_char=0; break;
			case 'I': data[a1][a2]='i';is_char=0; break;
			case 'J': data[a1][a2]='j';is_char=0; break;
			case 'K': data[a1][a2]='k';is_char=0; break;
			case 'L': data[a1][a2]='l';is_char=0; break;
			case 'M': data[a1][a2]='m';is_char=0; break;
			case 'N': data[a1][a2]='n';is_char=0; break;
			case 'O': data[a1][a2]='o';is_char=0; break;
			case 'P': data[a1][a2]='p';is_char=0; break;
			case 'Q': data[a1][a2]='q';is_char=0; break;
			case 'R': data[a1][a2]='r';is_char=0; break;
			case 'S': data[a1][a2]='s';is_char=0; break;
			case 'T': data[a1][a2]='t';is_char=0; break;
			case 'U': data[a1][a2]='u';is_char=0; break;
			case 'V': data[a1][a2]='v';is_char=0; break;
			case 'W': data[a1][a2]='w';is_char=0; break;
			case 'X': data[a1][a2]='x';is_char=0; break;
			case 'Y': data[a1][a2]='y';is_char=0; break;
			case 'Z': data[a1][a2]='z';is_char=0; break;
			case '0': is_char=0; break;
			case '1': is_char=0; break;
			case '2': is_char=0; break;
			case '3': is_char=0; break;
			case '4': is_char=0; break;
			case '5': is_char=0; break;
			case '6': is_char=0; break;
			case '7': is_char=0; break;
			case '8': is_char=0; break;
			case '9': is_char=0; break;
			case 'a': is_char=0; break;
			case 'b': is_char=0; break;
			case 'c': is_char=0; break;
			case 'd': is_char=0; break;
			case 'e': is_char=0; break;
			case 'f': is_char=0; break;
			case 'g': is_char=0; break;
			case 'h': is_char=0; break;
			case 'i': is_char=0; break;
			case 'j': is_char=0; break;
			case 'k': is_char=0; break;
			case 'l': is_char=0; break;
			case 'm': is_char=0; break;
			case 'n': is_char=0; break;
			case 'o': is_char=0; break;
			case 'p': is_char=0; break;
			case 'q': is_char=0; break;
			case 'r': is_char=0; break;
			case 's': is_char=0; break;
			case 't': is_char=0; break;
			case 'u': is_char=0; break;
			case 'v': is_char=0; break;
			case 'w': is_char=0; break;
			case 'x': is_char=0; break;
			case 'y': is_char=0; break;
			case 'z': is_char=0; break;
			default: is_char=1;
		    }
		    
		    
			//remove all character which isn't English or number
			
		    if(is_char)
		    {
		    	
		    	int str_len=data[a1].length();
		    	
		    	if(a2==0)
            	{
		
            		data[a1].erase(a2,1);
            		a2=a2-1;
            		
		
            	}
            	else if(a2==(str_len-1))
            	{
		
        	    	data[a1].erase(a2,1);
        	    	a2=a2-2;
		
            	}
            	else
            	{
            		
					for(int m=last_str;m>a1;m--)
					{
						
						data[m+1]=data[m];
						
					}
					
					
					
					data[a1+1].assign(data[a1],a2+1,str_len-a2-1);
            		last_str=last_str+1;
            		data[a1].erase(a2,str_len-a2);
            		a2=a2-2;
		
             	}
	
		    	
		    	
		    }
			
			
			
			
		}
		
		
		
	}
	
	
	//remove all empty strings from data
	
	for(int c3=0;c3<=last_str;c3++)
	{
		
		if(data[c3].empty())
		{
			
			for(int m1=c3;m1<=last_str;m1++)
			{
				
				data[m1]=data[m1+1];
				
			}
			
			last_str=last_str-1;
			c3=c3-1;
		}
		
		
		
	}
	
	
	//count word frequency and re-arrange
	//save counted strings in str_list
	//save frequency in f_array1 f_array2
	
	str_list[0]=data[0];
	f_array1[0]=1;
	f_array2[0]=1;
	
	for(int a3=1;a3<=last_str;a3++)
	{
		
		
		if(data[a3].empty())
		{
			
		}
		else
		{
			
			int a4;
			for(a4=count1;a4>=0;a4--)
			{
				if(data[a3]==str_list[a4])
				{
					f_array1[a4]++;
					f_array2[a4]++;
					found=1;
					break;
					
				}
				else
				{
					found=0;
				}
				
				
			}
			
			if(found==0)
			{
				str_list[count1+1]=data[a3];
				f_array1[count1+1]=1;
				f_array2[count1+1]=1;
				count1++;
				
			}
			
		
				
		}
		
		
		
	}
	
	
	//sort f_array2 from high frequency to low
	
	for(int i1=0;i1<=count1;i1++)
	{
		int j=i1;
		for(int i2=i1+1;i2<=count1;i2++)
		{
			
			if(f_array2[i2]>f_array2[j]) j=i2;
			
		}
		
		
		swap(f_array2[i1],f_array2[j]);
		
		
	}
	
	
	
	//output
	
	//first, use rank and f_array2 to know what word match the frequency count number
	//output the string and frequency count number
	//then, find the first appear location in data
	//output the location
	
	
	
	int a8=0;
	
	for(int a5=rank;a5>0;a5--)
	{
		
		if(a8==0)
		{
            
    		for(int a7=0;a7<=count1;a7++)
    		{
			
    			if(f_array1[a7]==f_array2[a8])
    			{
				
    				cout<<"("<<str_list[a7]<<","<<f_array1[a7]<<",";
    				
    				for(int c1=0;c1<=last_str;c1++)
    				{
    					
    					if(data[c1]==str_list[a7])
    					{
    						cout<<c1+1<<")"<<endl;
    						break;
    					}
    					
    					
    				}
    				
    				
    				
    				
				
    			}
			
			
    		}
    		
    	}
		else if(f_array2[a8]==f_array2[a8-1])
		{
			
			a5=a5+1;
			
		}
		else
		{
			
			for(int a7=0;a7<=count1;a7++)
    		{
			
    			if(f_array1[a7]==f_array2[a8])
    			{
    				
				
    				cout<<"("<<str_list[a7]<<","<<f_array1[a7]<<",";
    				
    				for(int c2=0;c2<=last_str;c2++)
    				{
    					
    					if(data[c2]==str_list[a7])
    					{
    						cout<<c2+1<<")"<<endl;
    						break;
    					}
    					
    					
    				}
    				
    				
    				
				}
			
			
    		}
			
			
		}
		
		
		a8=a8+1;
		
	}
	
	
	
	
	//stop count process time and output result in "ms"
	
	end_time=clock();
	
	total_time=end_time-start_time;
	
	cout<<total_time<<" ms"<<endl;
	
	
	system("pause");
	
	return 0;
	
	
	
}



#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;



int priority(char a) //判斷運算子的優先順序 
{ 
    switch(a) 
	{ 
        case '+': return 1;
		case '-': return 1;
        case '*': return 2;
		case '/': return 2;
        default: return 0;
    }
} 





void in_pre(char* infix,char* prefix) //轉換為prefix 
{ 
    char stack2[1000]={'\0'};
    
	int i,i1,i2,j,top;
	
	i2=-1;
	j=0;
    top=3;
    
    //從infix陣列的尾端開始讀入字元 
	 
    for(i1=0;(infix[i1]!='\0')||(infix[i1]==')');i1++)
    {
    	
    	i2=i2+1;
    	
    }
    
	
	
	
	for(i=i2;i>=0;i--) 
	{
	
      switch(infix[i]) 
	  { 
        
		case ')':
			
			//遇到右括號直接存入stack 
		    top=top+1;
            stack2[top]=infix[i]; 
            
			break;
            
        case '+':
        	
        	//遇到運算子先判斷優先度
			//如果stack中的運算子優先度較高 則從stack輸出到prefix 
        	//如果目前讀取的運算子優先度高 則將此運算子存入stack 
        	
        	while(priority(stack2[top])>=priority(infix[i])) 
			{ 
                prefix[j]=stack2[top--];
                j=j+1;
            } 
            
            top=top+1;
			stack2[top]=infix[i];  
            
			break; 
        	
		case '-':
			
			while(priority(stack2[top])>=priority(infix[i])) 
			{ 
                prefix[j]=stack2[top];
                
                j=j+1;
                top=top-1;
            } 
            
            top=top+1;
			stack2[top]=infix[i];  
            
			break; 
			
		case '*':
			
			while(priority(stack2[top])>=priority(infix[i])) 
			{ 
                prefix[j]=stack2[top];
                
                j=j+1;
                top=top-1;
            } 
            
            top=top+1;
			stack2[top]=infix[i];  
            
			break; 
			
		case '/':
			
            while(priority(stack2[top])>=priority(infix[i])) 
			{ 
                prefix[j]=stack2[top];
                
                j=j+1;
                top=top-1;
            } 
            
			top=top+1;
			stack2[top]=infix[i];  
            
			break; 
            
        case '(':
        	
        	//遇到左括號 將stack中的字元輸出 直到stack中遇到右括號為止 
        	
            while(stack2[top]!=')') 
			{
				
                prefix[j]=stack2[top];
                
                j=j+1;
                top=top-1;
            } 
            
            
            stack2[top]='\0';
			top=top-1;  
            
			break;
            
        default:   
            
            //遇到運算元 直接輸出到prefix 
            
			prefix[j]=infix[i];
			j=j+1;
			
     }
    
	
	}
    
    
	while(top>=0) 
	{ 
        
		if(stack2[top]!=')')
		{
		
	    	prefix[j]=stack2[top];
        
		}
		
		j=j+1;
        top=top-1;
    }
    
    
} 





void in_post(char* infix,char* postfix) //轉換為postfix 
{ 
    char stack1[1000]={'\0'};
    
	int i,j,top;
	
	j=0;
    top=3;
    
    //從infix陣列的首端開始讀入字元
    
    
	for(i=0;infix[i]!='\0';i++) 
	{
	
      switch(infix[i]) 
	  { 
        
		case '(':
			
			//遇到左括號直接存入stack
			
		    top=top+1;
            stack1[top]=infix[i]; 
            
			break;
            
        case '+':
        	
        	//遇到運算子先判斷優先度
			//如果stack中的運算子優先度較高 則從stack輸出到prefix 
        	//如果目前讀取的運算子優先度高 則將此運算子存入stack
        	
        	
        	while(priority(stack1[top])>=priority(infix[i])) 
			{ 
                postfix[j]=stack1[top--];
                j=j+1;
            } 
            
            top=top+1;
			stack1[top]=infix[i]; 
            
			break; 
        	
		case '-':
			
			while(priority(stack1[top])>=priority(infix[i])) 
			{ 
                postfix[j]=stack1[top];
                
                j=j+1;
                top=top-1;
            } 
            
            top=top+1;
			stack1[top]=infix[i]; 
            
			break; 
			
		case '*':
			
			while(priority(stack1[top])>=priority(infix[i])) 
			{ 
                postfix[j]=stack1[top];
                
                j=j+1;
                top=top-1;
            } 
            
            top=top+1;
			stack1[top]=infix[i];  
            
			break; 
			
		case '/':
			
            while(priority(stack1[top])>=priority(infix[i])) 
			{ 
                postfix[j] = stack1[top];
                
                j=j+1;
                top=top-1;
            } 
            
			top=top+1;
			stack1[top]=infix[i];  
            
			break; 
            
        case ')':
        	
        	//遇到左括號 將stack中的字元輸出 直到stack中遇到右括號為止 
        	
        	
            while(stack1[top]!='(')  
			{ 
                postfix[j]=stack1[top];
                
                j=j+1;
                top=top-1;
            } 
            
            stack1[top]='\0';
			top=top-1;  
            
			break;
            
        default:   
            
            //遇到運算元 直接輸出到prefix
            
			postfix[j]=infix[i];
			j=j+1;
			
     }
    
	
	}
    
	while(top>=0) 
	{ 
        
		if(stack1[top]!='(')
		{
		
	    	postfix[j]=stack1[top];
        
		}
		
		j=j+1;
        top=top-1;
    }
    
    
} 



int calc_value(char* postfix)//計算算式的值 
{
	
	int stack4[1000];
	
	
	int i1;
	int top3=0;
	
	
	//使用postfix的式子來計算 
	
	for(i1=0;postfix[i1]!='\0';i1++)
	{
		
		switch(postfix[i1])
		{
			case '+':
				stack4[top3-2]=stack4[top3-2]+stack4[top3-1];
				top3=top3-1;
				break;
			case '-':
				stack4[top3-2]=stack4[top3-2]-stack4[top3-1];
				top3=top3-1;
				break;
			case '*':
				stack4[top3-2]=stack4[top3-2]*stack4[top3-1];
				top3=top3-1;
				break;
			case '/':
				stack4[top3-2]=stack4[top3-2]/stack4[top3-1];
				top3=top3-1;
				break;
			case '0':
				stack4[top3]=0;
				top3=top3+1;
				break;
			case '1':
				stack4[top3]=1;
				top3=top3+1;
				break;
			case '2':
				stack4[top3]=2;
				top3=top3+1;
				break;
			case '3':
				stack4[top3]=3;
				top3=top3+1;
				break;
			case '4':
				stack4[top3]=4;
				top3=top3+1;
				break;
			case '5':
				stack4[top3]=5;
				top3=top3+1;
				break;
			case '6':
				stack4[top3]=6;
				top3=top3+1;
				break;
			case '7':
				stack4[top3]=7;
				top3=top3+1;
				break;
			case '8':
				stack4[top3]=8;
				top3=top3+1;
				break;
			case '9':
				stack4[top3]=9;
				top3=top3+1;
				break;
			default:
				int a=0;
			

			
	
		}
		
		
	
		
		
		
	}
	
	
	return stack4[0];
	
	
	
	
	
	
	
	
	
}




int main(void) 
{ 
    
	
	char infix[1000]={'\0'}; 
    char postfix[1000]={'\0'};
    char prefix[1000]={'\0'};
    
    //從txt讀入資料
	 
    cout<<"input filename: "; 
    
	char inputtxt[100];
    
    cin>>inputtxt;
    
    fstream file;
	
	file.open(inputtxt,ios::in);
	
	if(file.is_open())
	{
		
		
		file>>infix;	
			
		
		file.close();
		
	
	}
	else
	{
		cout<<"Fail to open file";
	}
    
    
    //進行轉換 
    
    in_pre(infix,prefix);
    
    in_post(infix,postfix);
    
    
    //輸出prefix
    
    cout<<"Prefix: ";
    int k1,k4;
    int k3=-1;
    
    for(k1=0;prefix[k1]!='\0';k1++)
    {
    	
    	k3=k3+1;
    	
    }
    
    for(k4=k3;k4>=0;k4--)
    {
    	
    	cout<<prefix[k4];
    	
    }
    
	cout<<endl;
    
    
    //輸出postfix
    
    cout<<"Postfix: ";
    int k2;
	
	for(k2=0;postfix[k2]!='\0';k2++)
	{
		
        cout<<postfix[k2]; 
    
	}
    
    cout<<endl;
    
    //輸出算式的值 
    
    int ans=calc_value(postfix);
    
    cout<<"Result: ";
    cout<<ans<<endl;
    
	
	system("pause");
	
	return 0;
	
} 

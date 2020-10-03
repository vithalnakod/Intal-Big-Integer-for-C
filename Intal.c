#include<stdio.h>
#include<stdlib.h>
#include "intal.h"
#include<string.h>

char* intal_add(const char* intal1, const char* intal2){
    
    int n1= strlen(intal1);
    int n2= strlen(intal2);
    char* new_1,*new_2;
   // printf("%s %s\n",intal1,intal2);
    if(n1>n2){
        new_1= (char*)malloc(sizeof(char)*(1001));
        new_2= (char*)malloc(sizeof(char)*(1001));
        int k=0;
        for(int i=n1-1;i>=0;i--){
            new_2[k]= intal1[i];
            k++;
        }
        new_2[k]='\0';
        k=0;
        for(int i=n2-1;i>=0;i--){
            new_1[k]= intal2[i];
            k++;
        }
        new_1[k]='\0';


    }
    else{
        new_1= (char*)malloc(sizeof(char)*(1001));
        new_2= (char*)malloc(sizeof(char)*(1001));
        int k=0;
        for(int i=n1-1;i>=0;i--){
            new_1[k]= intal1[i];
            k++;
        }
        new_1[k]='\0';
        k=0;
        for(int i=n2-1;i>=0;i--){
            new_2[k]= intal2[i];
            k++;
        }
        new_2[k]= '\0';
    }
    
    n1= strlen(new_1);
    n2= strlen(new_2);
    int k=0;
    int carry=0;
    char* res= (char*)malloc(sizeof(char)*(1002));

    for(int i=0;i<n1;i++){
        int digit= (new_1[i]-'0')+(new_2[i]-'0')+carry;
        carry= digit/10;
        res[k]= (digit%10)+'0';
        k++;
    }
    for(int i=n1;i<n2;i++){
        int digit= (new_2[i]-'0')+carry;
        carry= digit/10;
        res[k]= (digit%10)+'0';
        k++;
    }
    if(carry){
        res[k]= carry+'0';
        k++;
    }
    res[k]='\0';

    int index= strlen(res)-1;
    while(index>=0 && res[index]=='0'){
        //printf("YES");
        index--;
    }
    if(index==-1){
        char* zero= (char*)malloc(sizeof(char)*2);
        zero[0]='0';
        zero[1]='\0';
        free(res);
        free(new_2);
        free(new_1);
        return zero;
    }
    //printf("%s ", res);
    char* final= (char*)malloc(sizeof(char)*(index+2));
    k=0;
    for(int i=index;i>=0;i--){
        final[k]= res[i];
        k++;
    }
    final[k]='\0';
    free(res);
    free(new_2);
    free(new_1);
    return final;

}

int intal_compare(const char* intal1, const char* intal2){
    int n1= strlen(intal1);
    int n2= strlen(intal2);

    if(n1>n2)
        return 1;

    if(n2>n1)
        return -1;

    for(int i=0;i<n1;i++){
        int x,y;
        x= intal1[i]-'0';
        y= intal2[i]-'0';
        if(x>y)
            return 1;
        else if(y>x)
            return -1;
    }
    return 0;
}


char* intal_diff(const char* intal1, const char* intal2){
    
    int n1=strlen(intal1);
    int n2=strlen(intal2);

    int comp= intal_compare(intal1, intal2);
    
    int flag=0;
    if(comp==0){
        char* final= (char*)malloc(sizeof(char)*2);
        final[0]='0';
        final[1]='\0';
        return final;
    }
  
    else if(comp==1){
        flag=1;
    }
    else{
        flag=-1;
    }
    char* new_1,*new_2;
    if(flag==1){
        new_1= (char*)malloc(sizeof(char)*(1001));
        new_2= (char*)malloc(sizeof(char)*(1001));
        int k=0;
        for(int i=n1-1;i>=0;i--){
            new_1[k]= intal1[i];
            k++;
        }
        new_1[k]='\0';

        k=0;
        for(int i=n2-1;i>=0;i--){
            new_2[k]= intal2[i];
            k++;
        }
        new_2[k]='\0';
        
    }
    else{
        new_1= (char*)malloc(sizeof(char)*(1001));
        new_2= (char*)malloc(sizeof(char)*(1001));
        int k=0;
        for(int i=n1-1;i>=0;i--){
            new_2[k]= intal1[i];
            k++;
        }
        new_2[k]='\0';

        k=0;
        for(int i=n2-1;i>=0;i--){
            new_1[k]= intal2[i];
            k++;
        }
        new_1[k]='\0';
    }
    //printf("%ld %ld", strlen(new_1), strlen(new_2));
    //printf("%s %s\n", new_1, new_2);
    char* res= (char*)malloc(sizeof(char)*(1002));
    int carry=0;
    n1= strlen(new_1);
    n2= strlen(new_2);
    int k=0;
    for(int i=0;i<n2;i++){
        int digit_sub= (new_1[i]-'0')- (new_2[i]-'0')- carry;

        if(digit_sub<0){
            digit_sub+=10;
            carry=1;
        }
        else{
            carry=0;
        }
        res[k]= digit_sub+'0';
        k++;
    }

    for(int i=n2;i<n1;i++){
        int digit_sub= (new_1[i]-'0')- carry;
        if(digit_sub<0){
            digit_sub+=10;
            carry=1;
        }
        else{
            carry=0;
        }
        res[k]= digit_sub+'0';
        k++; 
    }
    res[k]='\0';

    int index= strlen(res)-1;
    while(index>=0 && res[index]=='0'){
        //printf("YES");
        index--;
    }

    if(index==-1){
        char* zero= (char*)malloc(sizeof(char)*2);
        zero[0]='0';
        zero[1]='\0';
        free(res);
        free(new_2);
        free(new_1);
        return zero;
    }

    //printf("%s ", res);
    char* final_1= (char*)malloc(sizeof(char)*(index+2));
    k=0;
    for(int i=index;i>=0;i--){
        final_1[k]= res[i];
        k++;
    }
    final_1[k]='\0';
    //printf("%s\n",final_1);
    free(res);
    free(new_2);
    free(new_1);
    return final_1;

}


char* intal_multiply(const char* intal1, const char* intal2){

    int n1= strlen(intal1);
    int n2= strlen(intal2);

    if(intal_compare(intal1,"0")==0 || intal_compare(intal2,"0")==0){
        char* result= (char*)malloc(sizeof(char)*2);
        result[0]='0';
        result[1]='\0';
        return result;
    }
    
    char* res= (char*)malloc(sizeof(char)*(n1+n2+1));
    for(int i=0;i<n1+n2;i++)
        res[i]='0';
    res[n1+n2]='\0';
    
    int index1=0;
    int index2=0;

    for(int i=n1-1;i>=0;i--){
        int carry=0;
        index2=0;
        for(int j=n2-1;j>=0;j--){
            int digit_digit= (intal1[i]-'0')*(intal2[j]-'0')+carry+ (res[index1+index2]-'0');
            carry= digit_digit/10;
            res[index1+index2]= (digit_digit%10) +'0';
            index2++;

        }
        if(carry>0){
            res[index1+index2]= ((res[index1+index2]- '0')+carry)+ '0';
        }
        index1++;
    }

    int index= n1+n2-1;
    //printf("%d",index);
    while(index>=0 && res[index]=='0'){
        index--;
    }
    if(index==-1){
        char* final= (char*)malloc(sizeof(char)*2);
        final[0]='0';
        final[1]='\0';
        free(res);
        return final;
    }
    //printf("%d",index);
    char* answer= (char*)malloc(sizeof(char)*(index+2));
    
    int k=0;
    //printf("%s\n",res);
    for(int i=index;i>=0;i--){
        answer[k]= res[i];
        k++; 
    }
    answer[k]='\0';
    //printf("%s\n",answer);
    free(res);
    return answer;

}


char* intal_mod(const char* intal1, const char* intal2){
    //int n1= strlen(intal1);
    //int n2= strlen(intal2);
    int flag=0;
    char* res;
    res= (char*)malloc(sizeof(char)*(1002));
    strcpy(res, intal1);
    char* temp= (char*)malloc(sizeof(char)*(1002));
   
    while(intal_compare(res, intal2)>=0)
    {
       
        strcpy(temp,intal2);

        while (intal_compare(temp, res)==-1)
        {
            char* temp2= intal_multiply(temp, "2"); 
            strcpy(temp, temp2);
            free(temp2); 
            //printf("%s %ld\n", temp, strlen(temp));
        
        }
        char* res2= intal_diff(temp,res);
        strcpy(res, res2);
        free(res2);
        //printf("HERE  %s\n ",res);
        flag= (flag+1)%2;
    }

    char*ans=(char*)malloc(sizeof(char)*1001);
    if(intal_compare(res,"0")==0)
    {
        char* zero= (char*)malloc(sizeof(char)*2);
        zero[0]='0';
        zero[1]='\0';
        strcpy(ans,zero);
        free(zero);
        free(res);
	free(temp);
        return ans;
    }
    else if(flag%2==1)
    {
        char* tempor= intal_diff(intal2, res);
        strcpy(ans, tempor);
        free(tempor);
    }
    else{
        strcpy(ans,res);
    }
    free(res);
    free(temp);
    return ans;

}

static char* gcdHelp(char* intal1, char* intal2){
    if(intal_compare(intal1,"0")==0){
        char* res= (char*)malloc(sizeof(char)*1002);
        strcpy(res,intal2);
	return res;
    }

    char* copy1= (char*)malloc(sizeof(char)*1002);

    char* copy2= (char*)malloc(sizeof(char)*1002);

    strcpy(copy1, intal1);
    strcpy(copy2, intal2);

    char* result= intal_mod(copy2, copy1);
    char* sol= gcdHelp(result, copy1);
    free(copy1);
    free(copy2);
    free(result);
    return sol;

}

char* intal_gcd(const char* intal1, const char* intal2){
    
    //int n1= strlen(intal1);
    //int n2= strlen(intal2);
    
    char* copy_intal1= (char*)malloc(sizeof(char)*1002);
    char* copy_intal2= (char*)malloc(sizeof(char)*1002);
    strcpy(copy_intal1, intal1);
    strcpy(copy_intal2, intal2);
    char* ans= (char*)malloc(sizeof(char)*1002);

    if(intal_compare(copy_intal1,"0")==0 && intal_compare(copy_intal2,"0")==0){
        char* sol= intal_add("0","0");
        strcpy(ans, sol);
	free(sol);
    }
    else{
        char* res= gcdHelp(copy_intal1, copy_intal2);
        strcpy(ans, res);
        free(res);

    }
    free(copy_intal1);
    free(copy_intal2);
    return ans;
}


char* intal_pow(const char* intal1, unsigned int n){

    char* res= (char*)malloc(sizeof(char)*1002);
    char* copy_intal1= (char*)malloc(sizeof(char)*1002);
    strcpy(copy_intal1, intal1);
    char* one= (char*)malloc(sizeof(char)*2);
    one[0]='1';
    one[1]='\0';

    strcpy(res,one);
    free(one);
    int f= n;
    while(f>0){
        if((f & 1) ==1){
	    char* avoid_leak= intal_multiply(res, copy_intal1);
            strcpy(res,avoid_leak);
	    free(avoid_leak);
        }
        f= f >> 1;
	
	//copy_intal1= intal_multiply(copy_intal1,copy_intal1);
    	char* avoid= intal_multiply(copy_intal1,copy_intal1);
	    strcpy(copy_intal1, avoid);
	    free(avoid);
        //printf("%s %d\n",copy_intal1,f);
    }
    //free(copy_intal1);
    return res;
}


char* intal_fibonacci(unsigned int n){

    char* zero= (char*)malloc(sizeof(char)*2);
    zero[0]='0';
    zero[1]='\0';
    if(n==0)
        return zero;
    
    char* one= (char*)malloc(sizeof(char)*2);
    one[0]='1';
    one[1]='\0';
    if(n==1){
        free(zero);
        return one;
    }

    char** res= (char**)malloc(sizeof(char*)*(n+1));
    for(int i=0;i<n+1;i++){
        res[i]= (char*)malloc(sizeof(char)*1001);
        strcpy(res[i],zero);
    }    

    strcpy(res[1],one);
    free(one);
    free(zero);

    for(int i=2;i<=n;i++){
        char* dp_i= intal_add(res[i-1], res[i-2]);

        strcpy(res[i], dp_i);
        free(dp_i);
       // printf("%s\n", res[i]);
    }

    char* final= (char*)malloc(sizeof(char)*(strlen(res[n])+1));
    strcpy(final, res[n]);
    
    for(int i=0;i<n+1;i++){
        free(res[i]);
    }
    free(res);
    return final;
}


char* intal_factorial(unsigned int n){

    char* zero= (char*)malloc(sizeof(char)*2);
    zero[0]='0';
    zero[1]='\0';

    char* one= (char*)malloc(sizeof(char)*2);
    one[0]= '1';
    one[1]='\0';

    if(n==0){
        free(zero);
        return one;
    }
    
    
    if(n==1){
        free(zero);
        return one;
    }

    char** res= (char**)malloc(sizeof(char*)*(n+1));
    for(int i=0;i<n+1;i++){
        res[i]= (char*)malloc(sizeof(char)*1001);
        strcpy(res[i], zero);
    }
    free(zero);
    strcpy(res[0], one);
    strcpy(res[1], one);

    free(one);
    for(int i=2;i<=n;i++){
        char* pres_ele= (char*)malloc(sizeof(char)*1000);
        sprintf(pres_ele, "%d",i);

        char* dp_i= intal_multiply(res[i-1],pres_ele);

        strcpy(res[i], dp_i);
        free(dp_i);
        free(pres_ele);
    }
    char* final= (char*)malloc(sizeof(char)*(strlen(res[n])+1));
    strcpy(final, res[n]);

    for (int i =0; i < n+1; i++)
    {
        free(res[i]);
    }
    free(res);
    return final;
    
}


int intal_max(char **arr, int n){

    char* max_ele= (char*)malloc(sizeof(char)*1001);
    strcpy(max_ele, arr[0]);

    int index=0;
    for(int i=0;i<n;i++){
        if(intal_compare(arr[i],max_ele)==1){
            index= i;
            strcpy(max_ele, arr[i]);
        }
    }

    free(max_ele);
    return index;

}

int intal_min(char **arr, int n){

    char* min_ele= (char*)malloc(sizeof(char)*1001);
    strcpy(min_ele, arr[0]);

    int index=0;
    for(int i=0;i<n;i++){
        if(intal_compare(arr[i],min_ele)==-1){
            index= i;
            strcpy(min_ele, arr[i]);
        }
    }

    free(min_ele);
    return index;

}


int intal_search(char **arr, int n, const char* key){

    int index=-1;
    for(int i=0;i<n;i++){
        if(intal_compare(arr[i],key)==0){
            index= i;
            break;
        }
    }

    return index;


}

static int helper(char** arr, int start, int end,const char* key, int n){
    //printf("%d %d\n",start, end);
    if(start>end){
        return -1;
    }
    int mid= start+ (end-start) /2;

    int comp= intal_compare(arr[mid], key);
    if(comp==0)
        return mid;
    
    if(comp==1){
        return helper(arr, start, mid-1, key, n);
    }
    else{
        return helper(arr, mid+1, end, key, n);
    }

}

int intal_binsearch(char **arr, int n, const char* key){
    int index= helper(arr, 0, n-1, key, n);
    if(index==-1 || index==0){
        return index;
    }
    while(index>=0 && intal_compare(arr[index],key)==0)
        index--;

    return index+1;

}

static unsigned long int min_find(unsigned int n, unsigned int m){
    if(m<=n)
        return m;
    return n;
}

char* intal_bincoeff(unsigned int n, unsigned int k){

    //int kk= min_find(k, n-k);
    if(n-k<k)
        k=n-k;
    char** res= (char**)malloc(sizeof(char*)*(k+2));
    char* zero= (char*)malloc(sizeof(char)*2);
    zero[0]='0';
    zero[1]='\0';

    for(int i=0;i<k+2;i++){
        res[i]= (char*)malloc(sizeof(char)*10001);
        strcpy(res[i],zero);
    }
    free(zero);
    //printf("%s",res[0]);
    char* one= (char*)malloc(sizeof(char)*2);
    one[0]='1';
    one[1]='\0';
    strcpy(res[0], one);
    free(one);

    for(int i=0;i<=n;i++){
        for(int j= min_find(i, k);j>0;j--){
            char* dp_i= intal_add(res[j], res[j-1]);
            strcpy(res[j], dp_i);
            //printf("%s\n", res[j]);
            free(dp_i);
        }
    }

    char* final= (char*)malloc(sizeof(char)*(strlen(res[k])+1));
    strcpy(final, res[k]);

    for(int i=0;i<(k+2);i++)
        free(res[i]);
    
    free(res);

    return final;
}



static void heapify(char** arr, int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2; 
   
    if (l < n && intal_compare(arr[l], arr[largest])==1) 
        largest = l; 

    if (r < n && intal_compare(arr[r], arr[largest])==1) 
        largest = r; 
  
    if (largest != i) 
    { 
        char* temp2= arr[i];
        arr[i]= arr[largest];
        arr[largest]= temp2;
        heapify(arr, n, largest); 
    } 
} 
   
void intal_sort(char **arr, int n){ 

    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    {
        char* temp= arr[0];
        arr[0]= arr[i];
        arr[i]= temp;
        heapify(arr, i, 0); 
    } 
} 
  
char* coin_row_problem(char **arr, int n){

    char* firstele= (char*)malloc(sizeof(char)*1001);
    strcpy(firstele, arr[0]);

    char* zero= (char*)malloc(sizeof(char)*2);
    zero[0]= '0';
    zero[1]= '\0';

    char* secondele= (char*)malloc(sizeof(char)*1001);
    strcpy(secondele, zero);

    free(zero);
    char* excluding= (char*)malloc(sizeof(char)*1001);
    for(int i=1; i<n; i++){

        if(intal_compare(firstele, secondele)==1){
            strcpy(excluding, firstele);
        }
        else{
            strcpy(excluding, secondele);
        }

        char* sum_int= intal_add(secondele, arr[i]);
        strcpy(firstele, sum_int);
        free(sum_int);

        strcpy(secondele, excluding);

    }
    if(intal_compare(firstele, secondele)==1){
        free(secondele);
        free(excluding);
        return firstele;
    }
    else{
        free(firstele);
        free(excluding);
        return secondele;
    }

}


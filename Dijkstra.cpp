/* Dijkstra's Algorithm in C 
	¸êºÞ©Ò1 0653410 ¶À§BÀR    */

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#define IN 9999
#define totalNode 10
int dijsktra2(int cost[][totalNode],int N,int source,int target,int path[totalNode],int linkCapacity);
int dijsktra(int cost[][totalNode],int N,int source, int target, int path[totalNode] ,int linkCapacity);
int main()
{
    int i,j,weight,ch,minpath,path[totalNode],path2[totalNode]={0},flag=0;
    int source, target,x,y,N,linkCapacity,threshold=-1;
    int totalRequest=0,satisfication=0,check=0;
    int cost[totalNode][totalNode];
    //int  cost[10][10]= {{},{0,9999,5,6,2,9999,9999},{0,5,9999,9999,7,4,9999},{0,6,9999,9999,2,9999,9},{0,2,7,7,9999,5,9999},{0,9999,4,9999,5,9999,6},{0,9999,9999,9,9999,6,9999}};
    //int cost[10][10] = {{},{0,9999,5,3,6,9999,9999},{0,5,9999,9999,7,4,9999},{0,3,9999,9999,3,9999,4},{0,6,7,3,9999,3,9999},{0,9999,4,9999,3,9999,6},{0,9999,9999,4,9999,6,9999}};
    //int cost[totalNode][totalNode]={{},{0,9999,8,3,4},{0,8,9999,5,9999},{0,3,5,9999,9999},{0,4,9999,9999,9999}};
	printf("The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C \n\n");
	printf("Please enter the number of nodes(< 10) :\n");
    scanf("%d",&N);
    
    N = N+1;
    
    for(i=1;i< N;i++){
    	for(j=1;j< N;j++){
			cost[i][j] = IN;
    	}
	}
   
    for(x=1;x< N;x++){
        for(y=x+1;y< N;y++){
        	
            printf("Enter the weight of the path between nodes %d and %d:(1~9998 and 9999 for no link between two node) ",x,y);
            scanf("%d",&weight);
            cost [x][y] = cost[y][x] = weight;
        printf("\n");
    } }
    
    while(1){
    	printf("\n\n\n");
		for(i=1;i<N;i++){
			for(j=1;j<N;j++){
				printf("%d\t",cost[i][j]);
			}
			printf("\n");
		}
		source=target=linkCapacity=0;
	    printf("\nEnter the source(9999 to exit):\t");
	    scanf("%d", &source); 
		if(source==9999){
	    	printf("\nBye Bye\n\n");
	    	break;
		}
	    printf("\nEnter the target:\t");
	    scanf("%d", &target);
	    printf("\nEnter the Link Capacities:\t");
	    scanf("%d",&linkCapacity);
	    printf("\n\n");
	   
	    
	    minpath = dijsktra(cost,N,source,target,path,linkCapacity);
	    totalRequest++;
	    	   
	    if(minpath==9999){
	    	printf("\nCan't find the path \n\n");
		}
		else{
			satisfication++;
		}
	}//while

	printf("Satisfaction index : %.2f\n,",(float)satisfication/totalRequest);
	
  /*  
    flag=0;
    for(i = N-1 ; i > -1 ; i--){
		if(path[i]==9999){
			flag=1;
			continue;
		}
		if(flag==1 && i==0)printf("%d",path[i]);
		else if(flag==1)printf("%d->",path[i]);
	}
	printf("\nThe Shortest Path: %d\n\n",minpath);
	*/
	
    
    return 0;
}


int dijsktra(int cost[][10],int N,int source,int target,int path[10],int linkCapacity)
{
    int dist[N],prev[N],selected[N]={0},i,m,start,d,j,flag1=0,flag2=0,k,changPath=0;
    int temp[N][N],x=-1,y=0,flag[N]={0},sum[N]={0},index=0,minpath,min=0;
    
    
	
    for(j=0;j<N;j++){
		for(k=0;k<N;k++){
			temp[j][k]=0;
		}
	}
	
	
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {

			if(cost[start][i] >= linkCapacity &&cost[start][i] >=0){
				
			/*	
				printf("\nstart:%d\n",start);
				printf("i:%d\n",i);
				printf("m:%d\n",m);
				printf("dist[start]:%d\n",dist[start]);
				printf("cost[start][i]:%d\n",cost[start][i]);
				printf("min:%d\n",min);
				printf("dist[i]:%d\n",dist[i]);
				*/
		    	d = dist[start] +cost[start][i];

	            if(d<= dist[i]&&selected[i]==0)
	            {
	               		
						
						dist[i] = d;
						prev[i] = start;
	                  	if(i==target){
	                  		x++;
	                  		y=0;
							k = target;
						    
						    while(k != -1)
						    {   
						    	
						        //printf("%d\t",k);
						        temp[x][y++]=k;
						        k = prev[k];
						    }
						   // printf("\n");

						}
	            }         
			
				if(min>=dist[i] && selected[i]==0)
	            {
	                min = dist[i];
	                m = i;
	            }
	    	}
	    	else continue;
        }
        x++;
        y=0;
        start = m;
        selected[start] = 1;
    /*    
        printf("dist:\n");
        for(k=0;k<N;k++){
        	printf("%d\t",dist[k]);
		}*/
		
	
       /* printf("%d,%d,%d\n",start,selected[target],dist[target]);*/
        if(start==0&&selected[target]==0 && dist[target]==9999)break;
    }
    if(dist[target]==9999)return 9999;
    start = target;
    j = 0;
    while(start != -1)
    {   
 
        path[j++] = start;
        start = prev[start];
    }
	path[j]=9999;
	

	minpath=9999;
	for(i=0;i<N;i++){
		if(sum[i]!=9999 && sum!= 0){
			for(j=0;j<N;j++){
				if(temp[i][j]!=0 && temp[i][j+1]!=0) {
					//printf("cost : %d \n",cost[temp[i][j]][temp[i][j+1]]);
					if((cost[temp[i][j]][temp[i][j+1]]-linkCapacity)<minpath){
					min=i;
					minpath=cost[temp[i][j]][temp[i][j+1]]-linkCapacity;
					}
				   // printf("%d\t",temp[i][j]);
					
				}
				
			}
		}
	
	}
//	printf("min%d,%d\n",min,minpath);
printf("Shortest path : ");
	for(i=N-1;i>-1;i--){
			if(temp[min][i]!=0){
			cost[temp[min][i]][temp[min][i-1]] -= linkCapacity;
			cost[temp[min][i-1]][temp[min][i]] -= linkCapacity;
			if(cost[temp[min][i-1]][temp[min][i]]<=0){
				cost[temp[min][i-1]][temp[min][i]]=9999;
				cost[temp[min][i]][temp[min][i-1]]=9999;
			}
			if(i!=0)printf("%d->",temp[min][i]);
			else printf("%d",temp[min][i])	;
		    }
	}
	
	
	
	printf("\nPath cost : %d\n\n",dist[target]);
	
	


	
    return dist[target];
}


